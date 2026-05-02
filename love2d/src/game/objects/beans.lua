beans = {}
beans.__index = beans
allbeans = {}
local itt = 0

function beans.new(x,y)
    local instance = setmetatable({},beans)
    itt = 0
    instance.img = sprites.objects.beans
    instance.x = x
    instance.y = y
    instance.w = instance.img:getWidth()
    instance.h = instance.img:getHeight()
    instance.scale = 1
    instance.spin = 0
    instance.collected = false
    instance.ate = false
    instance.collider = fcd:newItem("beans",x,y,instance.img:getWidth(),instance.img:getHeight(), "Beans")
    table.insert(allbeans,instance)
end
function beans:destroy(beans)
    for i,v in pairs(allbeans) do
        if v == beans then v.collider.destroy() table.remove(allbeans,i) end
    end
end

function beans.collect()
    allbeans[1].collider.destroy()
    love.audio.stop(audio.sound.Coin)
    love.audio.play(audio.sound.Coin)
    allbeans[1].collected = true
end

function beans.eat()
    allbeans[1].collider.destroy()
    love.audio.stop(audio.sound.Eat)
    love.audio.play(audio.sound.Eat)
    allbeans[1].ate = true
end

function beans.destroyAll()
    for i,v in pairs(allbeans) do
        beans:destroy(v)
    end
    allbeans = {}
end

function beans:update(dt)
    if self.collected == true then
        self.spin = math.rad((2.72*itt))
        itt = itt + 1
        self.y = self.y - 1
    elseif self.ate == true then
        self.spin = math.rad((0.906*itt))
        self.scale = self.scale - 0.002
        itt = itt + 1
       --self.x = self.x + 0.906*itt
        --self.y = self.y + 0.906*itt
    end
end

function beans:draw()
    love.graphics.push()
    love.graphics.setColor(1,1,1,(self.ate == false) and 1-(0.01*itt) or (1-(0.004*itt)))
    love.graphics.translate(self.x+14, self.y+16)
    love.graphics.scale(self.scale,self.scale)
    love.graphics.draw(self.img,0,0,self.spin,1,1,self.w/2,self.h/2)
    love.graphics.setColor(1,1,1,1)
    love.graphics.pop()
end

function beans.drawAll()
    for i,v in pairs(allbeans) do
        v:draw()
    end
end

function beans.updateAll(dt)
    for i,v in pairs(allbeans) do
        v:update(dt)
    end
end