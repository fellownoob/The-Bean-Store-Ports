#include "Corpse.hpp"

void Corpse::Draw() {
	if (timer < 900) {
		DrawTexturePro(ObjectTexture, { 0,0,48,56 }, { collider.pos.x,collider.pos.y,24,28 }, { 0.0f, 0.0f }, 0, { 255,255,255,255 });
	}
}

void Corpse::Update() {
	if (timer < 900) {
		hvsp.x *= 0.95;
		hvsp.y += (float)gravity;

		if (auto* solid = CollisionDetection.rectClassIntersecting(collider.pos.x, collider.pos.y + hvsp.y, collider.w, collider.h, Solid)) {
		

			while (std::abs(hvsp.y) > 0.1f) {
				hvsp.y *= 0.5f;
				if (!CollisionDetection.rectClassIntersecting(collider.pos.x, collider.pos.y + hvsp.y, collider.w, collider.h, Solid))
					collider.pos.y += hvsp.y;
			}
			hvsp.y = 0.0f;
		}
		collider.pos.y += hvsp.y;

		if (auto* solid = CollisionDetection.rectClassIntersecting(collider.pos.x + hvsp.x, collider.pos.y, collider.w, collider.h, Solid)) {

			while (std::abs(hvsp.x) > 0.1f) {
				hvsp.x *= 0.5f;
				if (!CollisionDetection.rectClassIntersecting(collider.pos.x + hvsp.x, collider.pos.y, collider.w, collider.h, Solid))
					collider.pos.x += hvsp.x;
			}
			hvsp.x = 0.0f;
		}
		collider.pos.x += hvsp.x;
		timer++;
	}
}