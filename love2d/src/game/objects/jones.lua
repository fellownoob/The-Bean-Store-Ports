jones = {}
jones.__index = jones
alljones = {}

function jones.new(x,y)
    local instance = setmetatable({},jones)
    instance.dir = dir
    instance.img = sprites.objects.jones
    instance.collider = fcd:newItem("jones",x,y,instance.img:getWidth(),instance.img:getHeight(), "Jones")
    table.insert(alljones,instance)
end
function jones:destroy(jones)
    for i,v in pairs(alljones) do
        if v == jones then v.collider.destroy() table.remove(alljones,i) end
    end
end

function jones.destroyAll()
    for i,v in pairs(alljones) do
        jones:destroy(v)
    end
    alljones = {}
end

function jones:update(dt)
    self.dir = (man.collider.x > self.collider.x) and 1 or -1
end

function jones:draw()
    love.graphics.draw(self.img,self.collider.x+16,self.collider.y+16,0,self.dir,1,self.img:getWidth()/2,self.img:getHeight()/2)
end

function jones.drawAll()
    for i,v in pairs(alljones) do
        v:draw()
    end
end

function jones.updateAll(dt)
    for i,v in pairs(alljones) do
        v:update(dt)
    end
end