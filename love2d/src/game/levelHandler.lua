levelHandler = {}

function levelHandler:load()
    self.currentLevel = 0
    self.manSpawnX = 0
    self.manSpawnY = 0
    self.currentTime = 0
    self:init()
end

function levelHandler:init()
    self:clean()
    self.level = sti("maps/level_"..self.currentLevel..".lua")
    self.objects = self.level.layers["Objects"]
    self.groundLayer = self.level.layers["Ground"]
    self.solidObjects = self.level.layers["Solid"]
    
    for i,v in pairs(self.solidObjects.objects) do
        local solid = fcd:newItem("Solid",v.x,v.y,v.width,v.height,"Solid")
    end
    for i,v in pairs(self.objects.objects) do
        self:setObject(v)
    end
end

function levelHandler:draw(mul)
    self.level:draw(0,0,mul,mul)
    shard.drawAll()
    roamer.drawAll()
    spike.drawAll()
    jones.drawAll()
    beans.drawAll()
    glassdoor.drawAll()
    flag:draw()
end

function levelHandler:update(dt)
    if self.currentLevel ~= 0 and self.currentLevel ~= 18 then
        self.currentTime = self.currentTime+dt
        
    end
    roamer.updateAll(dt)
    shard.updateAll(dt)
    jones.updateAll()
    beans.updateAll()
end

function levelHandler:setObject(obj)
    if obj.type == "man" then
        self.manSpawnX = obj.x+4
        self.manSpawnY = obj.y+4
        man:respawn(self.manSpawnX, self.manSpawnY)
    elseif obj.type == "flag" then
        flag:move(obj.x,obj.y)
    elseif obj.type == "spike" then
        spike.new(obj.x,obj.y)
    elseif obj.type == "shard" then
        shard.new(obj.x,obj.y)
    elseif obj.type == "ghost" then
        roamer.new(obj.x,obj.y)
    elseif obj.type == "jones" then
        jones.new(obj.x,obj.y)
    elseif obj.type == "beans" then
        beans.new(obj.x+2,obj.y)
    elseif obj.type == "glassdoor" then
        glassdoor.new(obj.x,obj.y)
    end
    if self.currentLevel >= 17 then
        flag:move(1024,1024)
    end
    if self.currentLevel == 18 then
        love.audio.play(audio.bgm.End)
        text:make(26,46,"congratulations\\time:"..math.floor(self.currentTime))
    end
end
function levelHandler:clean()
    fcd.items.Solid = {}
    spike.destroyAll()
    shard.destroyAll()
    roamer.destroyAll()
    corpse.removeAll()
    jones.destroyAll()
    beans.destroyAll()
    glassdoor.destroyAll()

end
function levelHandler:reset()
    self:goTo(self.currentLevel)
end

function levelHandler:goTo(level)
    self.currentLevel = level
    self:init()
end