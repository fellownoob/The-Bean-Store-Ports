roamer = {}
roamer.__index = roamer
allRoamers = {}

function roamer.new(x,y)
    local instance = setmetatable({},roamer)
    instance.dir = (math.random(0,1) > 0.5 and 1 or -1) -- -1==left 1==right
    instance.speed = 84
    instance.img = sprites.objects.roamer
    instance.hsp = 0
    instance.collider = fcd:newItem("Roamer",x,y,32,32,"Enemy")
    table.insert(allRoamers, instance)
end
function roamer.destroyAll()
    for i,v in pairs(allRoamers) do
        v.collider.destroy()
    end
    allRoamers = {} 
end
function roamer:draw()
    love.graphics.draw(self.img,self.collider.x+16,self.collider.y+16,0,self.dir,1,self.img:getWidth()/2,self.img:getHeight()/2)
end

function roamer:update(dt)
    if fcd:rectClassIntercepting(self.collider.x+self.hsp,self.collider.y,self.collider.w,self.collider.h,"Solid") or not fcd:rectClassIntercepting((self.dir > 0 and self.collider.x+self.collider.w or self.collider.x),self.collider.y+self.collider.h+1,1,1,"Solid") then
        self.dir = self.dir * -1
    end

    self.hsp = self.speed * self.dir * dt
    self.collider.x = self.collider.x + self.hsp
end

function roamer.drawAll()
    for i,v in pairs(allRoamers) do
        v:draw()
    end
end

function roamer.updateAll(dt)
    for i,v in pairs(allRoamers) do
        v:update(dt)
    end
end