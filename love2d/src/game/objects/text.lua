text = {}

function text:load()
    self.x = 0
    self.y = 0
    self.text = ""
    self.drawing = nil
    self.drawText = {}
    self.done = false
    self.timer = 0
end

function text:make(x,y,text)
    self.x = x
    self.y = y
    self.text = text
    self.drawing = nil
    self.drawText = {}
    self.done = false
    self.timer = 0
end
local i = 1

function text:update(dt)
    if self.done == true then return end

    self.timer = self.timer + dt
    if self.timer > 0.06 then
        if i > #self.text then return end
        self.drawing = string.sub(self.text,i,i)
        if self.drawing == "\\" then
            self.y = self.y + 20
            self.x = 12
        end
        table.insert(self.drawText,{self.drawing, self.x, self.y})
        self.x = self.x + 14
        self.timer = 0
        i = i + 1
        print(i)
    end


end

function text:draw()
    love.graphics.push()
    love.graphics.scale(1.5,1.5)
    for i,v in pairs(self.drawText) do
        if v[1] == ":" then
        love.graphics.draw(sprites.text.colon, v[2], v[3])
        elseif v[1] ~= "\\" then
        love.graphics.draw(love.graphics.newImage("sprites/text/"..(v[1])..".png"), v[2], v[3])
        end
    end
    love.graphics.pop()
end