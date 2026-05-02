#include "Roamer.hpp"

void Roamer::Update() {

    auto* solid = CollisionDetection.rectClassIntersecting(collider.pos.x + hvsp.x, collider.pos.y, collider.w, collider.h, Solid);

    if (solid || !CollisionDetection.rectClassIntersecting((dir > 0 ? collider.pos.x + collider.w : collider.pos.x), collider.pos.y + collider.h + 1, 1, 1, Solid)) {
        dir *= -1;
    }

    hvsp.x = (speed)* dir;
    collider.pos.x += hvsp.x;
}