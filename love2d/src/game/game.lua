require("src/game/objects/man")
require("src/game/objects/flag")
require("src/game/objects/roamer")
require("src/game/objects/spike")
require("src/game/objects/shard")
require("src/game/objects/beans")
require("src/game/objects/glassdoor")
require("src/game/objects/jones")
require("src/game/objects/text")
require("src/game/levelHandler")
game = {}

function game:load()
    world = fcd:load()
    text:load()
    
    --text:make(26,66,"time:")
    --enemyflagsolidman
    man:load(0,0)
    flag:load(0,0)
    levelHandler:load()
end

function game:update(dt)
    audio.bgm.OverworldDistorted:setVolume((levelHandler.currentLevel == 16 and 0.75 or 1))
    love.audio.stop((levelHandler.currentLevel == 17) and (audio.bgm.OverworldDistorted) or audio.bgm.BeanStore)
    if levelHandler.currentLevel < 17 then love.audio.play(audio.bgm.OverworldDistorted) elseif levelHandler.currentLevel == 17 then love.audio.play(audio.bgm.BeanStore) end
    dt = math.min(dt, 1/60)
    fcd:update(dt)
    levelHandler:update(dt)
    man:update(dt)
    text:update(dt)
    if levelHandler.currentLevel < 17 then
        presence.state = "Trying to collect Bean"
    elseif levelHandler.currentLevel == 17 then 
        presence.state = "Collecting Bean"
    elseif levelHandler.currentLevel == 18 then
        presence.state = "Has collected Bean"
    end


    presence.details = "Level "..levelHandler.currentLevel
    if nextPresenceUpdate < love.timer.getTime() then
        discordRPC.updatePresence(presence)
        nextPresenceUpdate = love.timer.getTime() + 2.0
    end
    discordRPC.runCallbacks()
end

function game:draw()
    if levelHandler.currentLevel ~= 17 then
        love.graphics.setBackgroundColor(0.4, 0.76, 1)
    else
        love.graphics.setBackgroundColor(0.615, 0.623, 0.65)
    end
    levelHandler:draw(settings.resMul)
    --fcd:draw()
    man:draw()
    text:draw()
end