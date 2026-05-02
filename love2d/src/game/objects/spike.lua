spike = {}
spike.__index = spike
allSpikes = {}

function spike.new(x,y)
    local instance = setmetatable({},spike)
    instance.x = x
    instance.y = y
    instance.img = sprites.objects.spike
    instance.collider = fcd:newItem("Spike",x,y,instance.img:getWidth(),instance.img:getHeight(),"Enemy")
    table.insert(allSpikes,instance)
end
function spike.destroyAll()
    for i,v in pairs(allSpikes) do
        v.collider.destroy()
    end
    allSpikes = {}
end
function spike:setDir()
    local scaleX = 1
    if math.random(0,1) > 0.5 then
        scaleX = 1
    else
        scaleX = -1
    end
    return scaleX
end
function spike:draw()
    love.graphics.draw(self.img,self.x+16,self.y+16,0,self:setDir(),1,16,16)
end

function spike.drawAll()
    for i,v in pairs(allSpikes) do
        v:draw()
    end
end