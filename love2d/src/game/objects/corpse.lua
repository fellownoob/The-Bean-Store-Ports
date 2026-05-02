corpse = {}
corpse.__index = corpse
allCorpses = {}

function corpse.new(x,y,xVel,yVel,dir)
    local instance = setmetatable({},corpse)
    instance.hsp = xVel * 1.5
    instance.vsp = yVel
    instance.gravity = 7
    instance.dir = dir
    instance.img = sprites.objects.corpse
    instance.timer = 0
    instance.collider = fcd:newItem("Corpse",x,y,instance.img:getWidth()/2,instance.img:getHeight()/2, "Corpse")
    table.insert(allCorpses,instance)
end
function corpse:remove(corpse)
    for i,v in pairs(allCorpses) do
        if v == corpse then v.collider.destroy() table.remove(allCorpses,i) end
    end
end

function corpse.removeAll()
    for i,v in pairs(allCorpses) do
        corpse:remove(v)
    end
    allCorpses = {}
end

function corpse:update(dt)
    if self.timer > 900 then corpse:remove(self) end
    self.hsp = self.hsp * 0.95
    self.vsp = self.vsp + self.gravity * dt


    if fcd:rectClassIntercepting(self.collider.x,self.collider.y+self.vsp,self.collider.w,self.collider.h,"Solid") then
        if (self.collider.y < self.collider.y+self.vsp) then
            self.grounded = true
        end
        while math.abs(self.vsp) > 0.1 do
                self.vsp = self.vsp * 0.5
                if not fcd:rectClassIntercepting(self.collider.x,self.collider.y+self.vsp,self.collider.w,self.collider.h,"Solid") then self.collider.y = self.collider.y + self.vsp end 
        end
        self.vsp = 0
    end
    self.collider.y = self.collider.y + self.vsp

    if fcd:rectClassIntercepting(self.collider.x+self.hsp,self.collider.y,self.collider.w,self.collider.h,"Solid") then
        while math.abs(self.hsp) > 0.1 do
                self.hsp = self.hsp * 0.5
                if not fcd:rectClassIntercepting(self.collider.x+self.hsp,self.collider.y,self.collider.w,self.collider.h,"Solid") then self.collider.x = self.collider.x + self.hsp end 
        end
        self.hsp = 0
    end

    self.collider.x = self.collider.x + self.hsp
    
    self.timer = self.timer + 1
end

function corpse:draw()
    love.graphics.push()
    love.graphics.scale(0.5)
    love.graphics.draw(self.img,(self.collider.x+12)*2,(self.collider.y+14)*2,0,self.dir,1,self.img:getWidth()/2,self.img:getHeight()/2)
    love.graphics.pop()
end

function corpse.drawAll()
    for i,v in pairs(allCorpses) do
        v:draw()
    end
end

function corpse.updateAll(dt)
    for i,v in pairs(allCorpses) do
        v:update(dt)
    end
end