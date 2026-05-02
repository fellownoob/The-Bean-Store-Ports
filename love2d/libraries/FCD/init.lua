fcd = {}

function fcd:load()
    self.items = {
        Man = {},
        Solid = {},
        Enemy = {},
        Flag = {},
        Jones = {},
        Beans = {},
        Corpse = {}
    }
end

local function rectIntersecting(x1,y1,w1,h1, x2,y2,w2,h2)
    --local dir.x, dir.y
    --print(x1,y1)
    return x1 < x2+w2 and x2 < x1+w1 and y1 < y2+h2 and y2 < y1+h1
end
local function pointIntersecting(x1,y1, x2,y2,w2,h2)
    return x1 > x2 and x1 < x2+w2 and y1 > y2 and y1 < y2+h2
end

function fcd:itemIntersecting(item1,item2)
    return rectIntersecting(item1.x,item1.y,item1.w,item1.h, item2.x,item2.y,item2.w,item2.h)
end

function fcd:pointItemIntersecting(px,py,item)
    return pointIntersecting(px,py, item.x,item.y,item.w,item.h)
end

function fcd:rectItemIntersecting(x1,y1,w1,h1,item)
    return rectIntersecting(x1,y1,w1,h1, item.x,item.y,item.w,item.h)
end



function fcd:pointClassIntercepting(px,py,class)
    for i,v in pairs(self.items[class]) do
        if self:pointItemIntersecting(px,py,v) then
            return self:pointItemIntersecting(px,py,v)
        end
    end
end

function fcd:rectClassIntercepting(x1,y1,w1,h1, class)
    for i,v in pairs(self.items[class]) do
        if self:rectItemIntersecting(x1,y1,w1,h1,v) then
            return self:rectItemIntersecting(x1,y1,w1,h1,v)
        end
    end
end


function fcd:newItem(pname,px,py,pw,ph,pclass)
    local item = {
        Name = name,
        x = px,
        y = py,
        w = pw,
        h = ph,
    }
    item.enter = function(class)
            return self:rectClassIntercepting(item.x,item.y,item.w,item.h,class)
    end
    item.destroy = function()
        item = nil
        table.remove(self.items[pclass],self.items[pclass][item])
    end
    item.boundingBoxes = {
        left = item.x,
        right = item.x+item.w,
        up = item.y,
        down = item.y+item.h,
    }
    table.insert(self.items[pclass],item)
    return item
end

function fcd:update(dt)
    for i,v in pairs(self.items) do
        for j,item in pairs(v) do
            item.boundingBoxes ={
                left = item.x,
                right = item.x+item.w,
                up = item.y,
                down = item.y+item.h,
            }
        end
    end
end

function fcd:draw()
    love.graphics.setColor(0,0,0)
    for i,v in pairs(self.items["Solid"]) do
        love.graphics.rectangle("fill", v.x,v.y,v.w,v.h)
    end
    love.graphics.setColor(0.8,0,0)
    for i,v in pairs(self.items["Enemy"]) do
        love.graphics.rectangle("fill", v.x,v.y,v.w,v.h)
    end
    love.graphics.setColor(0.8,0.8,0)
    for i,v in pairs(self.items["Flag"]) do
        love.graphics.rectangle("fill", v.x,v.y,v.w,v.h)
    end
    love.graphics.setColor(0.4,0.4,0)
    for i,v in pairs(self.items["Beans"]) do
        love.graphics.rectangle("fill", v.x,v.y,v.w,v.h)
    end
    love.graphics.setColor(0,0.8,0)
        for i,v in pairs(self.items["Man"]) do
        love.graphics.rectangle("fill", v.x,v.y,v.w,v.h)
    end
end


return fcd