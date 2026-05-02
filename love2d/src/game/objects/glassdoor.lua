glassdoor = {}
glassdoor.__index = glassdoor
allglassdoor = {}

function glassdoor.new(x,y)
    local instance = setmetatable({},glassdoor)
    instance.img = sprites.objects.storeDoor
    instance.collider = fcd:newItem("glassdoor",x,y,instance.img:getWidth(),instance.img:getHeight(), "Flag")
    table.insert(allglassdoor,instance)
end
function glassdoor:destroy(glassdoor)
    for i,v in pairs(allglassdoor) do
        if v == glassdoor then v.collider.destroy() table.remove(allglassdoor,i) end
    end
end

function glassdoor.destroyAll()
    for i,v in pairs(allglassdoor) do
        glassdoor:destroy(v)
    end
    allglassdoor = {}
end

function glassdoor:draw()
    love.graphics.draw(self.img,self.collider.x+16,self.collider.y+16,0,self.dir,1,self.img:getWidth()/2,self.img:getHeight()/2)
end

function glassdoor.drawAll()
    for i,v in pairs(allglassdoor) do
        v:draw()
    end
end