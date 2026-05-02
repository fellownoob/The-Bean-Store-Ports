function draw()
    love.graphics.setColor(1, 1, 1)


    love.graphics.push()
    love.graphics.scale(settings.resMul,settings.resMul)
    game:draw()
    love.graphics.pop()
end