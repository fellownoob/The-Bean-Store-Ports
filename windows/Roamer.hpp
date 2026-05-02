#pragma once
#include "Enemy.hpp"

class Roamer : public Enemy {
public:
	Roamer(Vector2 SpawnPos) : Enemy("Roamer", SpawnPos) {
		dir = (float((rand() & 2)) > 0.5f) ? 1 : -1;
		speed = 0.65f + ((rand() & 100) / 1200.0f);
		hvsp.x = speed*dir;
	}
	void Update();

};