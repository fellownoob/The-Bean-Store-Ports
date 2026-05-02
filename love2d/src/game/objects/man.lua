man = {}
require("src/game/objects/corpse")
function man:load(x,y)
    self.spr = sprites.objects.man
    self.speed = 186
    self.dir = 1 -- -1==left 1==right
    self.jumpPower = 2.6
    self.hsp = 0
    self.vsp = 0
    self.gravity = 7
    self.beanCollected = false
    self.beanAte = false

    self.scaleX = 1
    self.collider = fcd:newItem("Man",x,y,self.spr:getWidth()/2,self.spr:getHeight()/2, "Man")
    self.grounded = true

end

function man:flipCharacter()
    if self.dir ~= 0 then
        self.scaleX = self.dir
    end
    return self.scaleX
end

function man:respawn(x,y)
    self.collider.x = x
    self.collider.y = y
    self.hsp = 0
    self.vsp = 0
end

function man:die()
    if self.collider.y > 352 then
        audio.sound.AAAA:stop()
        audio.sound.AAAA:play()
        man:respawn(levelHandler.manSpawnX,levelHandler.manSpawnY)
        return
    end
    print(self.hsp)
    corpse.new(self.collider.x,self.collider.y,self.hsp,self.vsp,self.scaleX)
    audio.sound.uuhhh:stop()
    audio.sound.uuhhh:play()
    man:respawn(levelHandler.manSpawnX,levelHandler.manSpawnY)
end

function man:draw() ------------------------ ADD THE FUCKING Glass
    love.graphics.push()
    corpse.drawAll()
    love.graphics.scale(0.5)
    love.graphics.draw(self.spr, (self.collider.x*2+24), (self.collider.y*2+28), 0, man:flipCharacter(), 1,24,28)
    --love.graphics.print(string.format("The Bean Store \nx: %f \ny: %f (X and Y arent pixel perfect cuz floating point issues) \n currentLevel: %i",self.collider.x, self.collider.y, levelHandler.currentLevel), 0, 0)
    love.graphics.pop()
end

function sign(number)
    return number > 0 and 1 or (number == 0 and 0 or -1)
end

function man:update(dt)
    self.grounded = false
    corpse.updateAll(dt)
    if (levelHandler.currentLevel ~= 17 and self.collider.enter("Flag")) or (levelHandler.currentLevel == 17 and self.beanCollected == true and self.collider.enter("Flag")) then
        levelHandler:goTo(levelHandler.currentLevel+1)
    elseif self.collider.enter("Enemy") or self.collider.y > 352 then
        self:die()
    end
    if self.collider.enter("Beans") then
        if levelHandler.currentLevel == 17 then
            beans.collect()
            self.beanCollected = true
        elseif levelHandler.currentLevel == 18 then
            beans.eat()
            self.beanAte = true
        end
    end

    up = love.keyboard.isDown("up") or love.keyboard.isDown("space") or love.keyboard.isDown("w")
    left = love.keyboard.isDown("left") or love.keyboard.isDown("a")
    right = love.keyboard.isDown("right") or love.keyboard.isDown("d")
    self.dir = (right and 1 or 0) - (left and 1 or 0)
    self.hsp = self.speed * self.dir * dt
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

    if up and self.grounded and self.vsp > -1 then
        self.vsp = -self.jumpPower
        audio.sound.Jump:stop()
        audio.sound.Jump:play()
    end

    if fcd:rectClassIntercepting(self.collider.x+self.hsp,self.collider.y,self.collider.w,self.collider.h,"Solid") then
        while math.abs(self.hsp) > 0.1 do
                self.hsp = self.hsp * 0.5
                if not fcd:rectClassIntercepting(self.collider.x+self.hsp,self.collider.y,self.collider.w,self.collider.h,"Solid") then self.collider.x = self.collider.x + self.hsp end 
        end
        self.hsp = 0
    end

    self.collider.x = self.collider.x + self.hsp

    --if fcd:pointClassIntercepting(self.collider.x,(self.vsp > 0 and self.collider.y+self.collider.h+self.vsp or self.collider.y+self.vsp),"Solid") then
    --    --while fcd:pointClassIntercepting((self.dir > 0 and self.collider.x+self.collider.w or self.collider.x),self.collider.y,"Solid") do
    --    --    self.collider.x = self.collider.x - self.hsp
        --end
    --    while math.abs(self.vsp) > 0.1 do
    --            self.vsp = self.vsp * 0.5
    --            if not fcd:pointClassIntercepting(self.collider.x,(self.vsp > 0 and self.collider.y+self.collider.h+self.vsp or self.collider.y+self.vsp),"Solid") then self.collider.y = self.collider.y + self.vsp end 
    --    end
    --    self.vsp = 0
    --end
end