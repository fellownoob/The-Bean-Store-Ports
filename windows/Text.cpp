#include "Text.hpp"

Text::Text():
    drawing('A'),
    Position({42,72})

    

{

}

void Text::Init() {

    CTexture = LoadTexture("res/sprites/text/C.png");
    OTexture = LoadTexture("res/sprites/text/O.png");
    NTexture = LoadTexture("res/sprites/text/N.png");
    GTexture = LoadTexture("res/sprites/text/G.png");
    RTexture = LoadTexture("res/sprites/text/R.png");
    ATexture = LoadTexture("res/sprites/text/A.png");
    TTexture = LoadTexture("res/sprites/text/T.png");
    UTexture = LoadTexture("res/sprites/text/U.png");
    LTexture = LoadTexture("res/sprites/text/L.png");
    ITexture = LoadTexture("res/sprites/text/I.png");
    STexture = LoadTexture("res/sprites/text/S.png");
    ETexture = LoadTexture("res/sprites/text/E.png");
    MTexture = LoadTexture("res/sprites/text/M.png");
    ColonTexture = LoadTexture("res/sprites/text/_COLON.png");
    //numbers

    OneTexture = LoadTexture("res/sprites/text/1.png");
    TwoTexture = LoadTexture("res/sprites/text/2.png");
    ThreeTexture = LoadTexture("res/sprites/text/3.png");
    FourTexture = LoadTexture("res/sprites/text/4.png");
    FiveTexture = LoadTexture("res/sprites/text/5.png");
    SixTexture = LoadTexture("res/sprites/text/6.png");
    SevenTexture = LoadTexture("res/sprites/text/7.png");
    EightTexture = LoadTexture("res/sprites/text/8.png");
    NineTexture = LoadTexture("res/sprites/text/9.png");
    ZeroTexture = LoadTexture("res/sprites/text/0.png");

    letterTextures['C'] = CTexture;
    letterTextures['O'] = OTexture;
    letterTextures['N'] = NTexture;
    letterTextures['G'] = GTexture;
    letterTextures['R'] = RTexture;
    letterTextures['A'] = ATexture;
    letterTextures['T'] = TTexture;
    letterTextures['U'] = UTexture;
    letterTextures['L'] = LTexture;
    letterTextures['I'] = ITexture;
    letterTextures['S'] = STexture;
    letterTextures['E'] = ETexture;
    letterTextures['M'] = MTexture;
    letterTextures[':'] = ColonTexture;

    //numbers

    letterTextures['0'] = ZeroTexture;
    letterTextures['1'] = OneTexture;
    letterTextures['2'] = TwoTexture;
    letterTextures['3'] = ThreeTexture;
    letterTextures['4'] = FourTexture;
    letterTextures['5'] = FiveTexture;
    letterTextures['6'] = SixTexture;
    letterTextures['7'] = SevenTexture;
    letterTextures['8'] = EightTexture;
    letterTextures['9'] = NineTexture;
}

Text::~Text() {
    for (auto& p : letterTextures) {
        UnloadTexture(p.second);
    }
}

void Text::Make(std::string txt) {
    text = txt;
    itt = 1;
    drawText.clear();
}

void Text::Update() {
    if (done == true)
        return;

    timer += 0.007f;
    if (timer > 0.06) {
        if (itt > text.length())
            return;

        drawing[0] = text.substr(itt - 1, 1)[0];

        if (drawing[0] == '@') {
            Position.y += 32;
            Position.x = 24;
        }
        DrawTextEntry dte;
        dte.character = drawing[0];
        dte.position = Position;
        drawText.push_back(dte);
        Position.x += 18;
        timer = 0.0f;
        itt++;
    }
}

void Text::Draw() {
    for (auto& item : drawText) {
        if (item.character != '@') {
            //DrawRectangle(item.position.x,item.position.y,32,32,BLACK);
            DrawTextureEx(letterTextures[item.character], { item.position.x, item.position.y },0.0f,1.2f, { 255,255,255,255 });

        }
    }
}
