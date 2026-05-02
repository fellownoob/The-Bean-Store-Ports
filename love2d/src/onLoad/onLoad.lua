function onLoad()
    love.audio.setVolume(0.3)
    love.graphics.setDefaultFilter("nearest","nearest")
    require("src/onLoad/requireAll")
    discordRPC.initialize("1379958629213671594", true)
    local now = os.time(os.date("*t"))
    presence = {
        details = "Level: 0",
        state = "Trying to collect Bean",
        largeImageText = "The Bean Store";
        startTimestamp = now,
        endTimestamp = now + 60
    }
    nextPresenceUpdate = 0

    if settings.resMul ~= 1 then love.window.setMode(480*settings.resMul,352*settings.resMul) end
    math.randomseed(math.random())
    game:load()
end