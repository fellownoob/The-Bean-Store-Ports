settings = {
    resMul = 2
}

sprites = {
    objects = {
        beans = love.graphics.newImage("sprites/objects/Beans.png"),
        jones = love.graphics.newImage("sprites/objects/Cashier Jones.png"),
        shard = love.graphics.newImage("sprites/objects/Shard.png"),
        spike = love.graphics.newImage("sprites/objects/Spike.png"),
        roamer = love.graphics.newImage("sprites/objects/Ghost.png"),
        flag = love.graphics.newImage("sprites/objects/Flag.png"),
        man = love.graphics.newImage("sprites/objects/Man.png"),
        storeDoor = love.graphics.newImage("sprites/objects/Store Door.png"),
        corpse = love.graphics.newImage("sprites/objects/Corpse.png")
    },
    text = {
        colon = love.graphics.newImage("sprites/text/_COLON.png"),
    }
}
audio = {
    bgm = {
        BeanStore = love.audio.newSource("audio/Bean Store.mp3", "stream"),
        End = love.audio.newSource("audio/End.mp3", "stream"),
        Overworld = love.audio.newSource("audio/Overworld.mp3", "stream"),
        OverworldDistorted = love.audio.newSource("audio/OverworldDistorted.mp3", "stream")
    },
    sound = {
        AAAA = love.audio.newSource("audio/AAAA.wav", "static"),
        Jump = love.audio.newSource("audio/Jump.wav", "static"),
        uuhhh = love.audio.newSource("audio/uuhhh.wav", "static"),
        Hit = love.audio.newSource("audio/Hit.wav", "static"),
        Eat = love.audio.newSource("audio/Eat.wav", "static"),
        Coin = love.audio.newSource("audio/Coin.wav", "static")
    }
}

for i,v in pairs(audio.bgm) do
    if v == audio.bgm.End then return end
    v:setLooping(true)
end
