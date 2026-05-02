#include "Beans.hpp"

Beans::~Beans() {
    UnloadSound(SCoin);
    UnloadSound(SEat);
    UnloadTexture(ObjectTexture);
    CollisionDetection.deleteItem(collider);
}

void Beans::Draw() {
    DrawTexturePro(ObjectTexture,
        { 0,0,(float)ObjectTexture.width * (float)dir,(float)ObjectTexture.height },
        { BeanPos.x+(ObjectTexture.width / 2),BeanPos.y+(ObjectTexture.height / 2),(float)ObjectTexture.width * scale,(float)ObjectTexture.height * scale},
        {(float)ObjectTexture.width*scale/2, (float)ObjectTexture.height*scale/2},
        rot,
        {255,255,255,(beanAte == false) ? unsigned char(std::clamp(255 * (1 - (0.01f * itt)), 0.0f, 255.0f)) : unsigned char(std::clamp(255 * (1 - (0.004f * itt)), 0.0f, 255.0f))});
}
void Beans::Update() {
    auto* mansolid = CollisionDetection.rectClassIntersecting(collider.pos.x, collider.pos.y, collider.w, collider.h, Player);

    if (mansolid && levelhandler.GetLevel() == 17) {
        beanCollected = true;
        man.beanCollected = true;
        PlaySound(SCoin);
    }
    else if (mansolid && levelhandler.GetLevel() == 18) {
        beanAte = true;
        PlaySound(SEat);
    }

    if (beanCollected == true) {
        CollisionDetection.deleteItem(collider);
        rot = float(2.72 * itt);
        itt = itt + 1;
        BeanPos.y--;
    }else if(beanAte == true) {
        CollisionDetection.deleteItem(collider);

        rot = float(0.906 * itt);
        scale -= 0.002f;
        itt = itt + 1;
    }
}