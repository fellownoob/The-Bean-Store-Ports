function love.load()
    require("src/onLoad/onLoad")
    onLoad()
end

function love.draw()
    draw()
end

function love.update(dt)
    update(dt)
end

function love.quit()
    discordRPC.shutdown()
end