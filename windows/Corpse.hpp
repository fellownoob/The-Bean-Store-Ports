#pragma once
#include "Object.hpp"

class Corpse : public Object {
public:
	Corpse(Vector2 SpawnPos, Vector2 xyvel) : Object("Corpse", SpawnPos, Classes::Dead) {
		collider.w = 24;
		collider.h = 28;
		hvsp = xyvel;
	}
	void Draw();
	void Update();

private:
	const float gravity = 0.05f;
};