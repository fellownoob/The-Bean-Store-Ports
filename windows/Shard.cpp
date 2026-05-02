#include "Shard.hpp"

void Shard::Update() {

    auto* solid = CollisionDetection.rectClassIntersecting(collider.pos.x, collider.pos.y + hvsp.y, collider.w, collider.h, Solid);

    if (solid || collider.pos.y + 32 > 352) {
        dir *= -1;
    }
   
    hvsp.y = (speed * dir);
    collider.pos.y += hvsp.y;
    


}