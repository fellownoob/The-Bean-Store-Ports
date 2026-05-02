flag = {}

function flag:load()
    self.collider = fcd:newItem("Flag",0,0,32,32, "Flag")
end

function flag:draw()
    love.graphics.draw(sprites.objects.flag,self.collider.x,self.collider.y)
end

function flag:move(x,y)
    self.collider.x = x
    self.collider.y = y
end