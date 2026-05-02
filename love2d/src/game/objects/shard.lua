shard = {}
shard.__index = shard
allShards = {}

function shard.new(x,y)
    local instance = setmetatable({},shard)
    instance.dir = (math.random(0,1) > 0.5 and 1 or -1) -- -1==up 1==down
    instance.speed = 93
    instance.vsp = 0
    instance.img = sprites.objects.shard
    instance.collider = fcd:newItem("Shard",x+8,y,16,32,"Enemy")
    table.insert(allShards,instance)
end

function shard.destroyAll()
    for i,v in pairs(allShards) do
        v.collider.destroy()
    end
    allShards = {} 
end

function shard:draw()
    love.graphics.draw(self.img,self.collider.x+8,self.collider.y+16,0,1,1,self.img:getWidth()/2,self.img:getHeight()/2)
end

function shard:update(dt)

    self.vsp = self.speed * self.dir * dt
    self.collider.y = self.collider.y + self.vsp
end
function shard.updateAll(dt)
    for i,v in pairs(allShards) do
        if fcd:rectClassIntercepting(v.collider.x,v.collider.y+v.vsp,v.collider.w,v.collider.h,"Solid") or v.collider.y+32 > 352 then
                v.dir = v.dir * -1
        end
        v:update(dt)
    end
end

function shard.drawAll()
    for i,v in pairs(allShards) do
        v:draw()
    end
end