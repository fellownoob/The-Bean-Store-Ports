#pragma once
#include "Enemy.hpp"

class Shard : public Enemy {
public:
	Shard(Vector2 SpawnPos) : Enemy("Shard", SpawnPos) { 
		dir = (float((rand() & 2)) > 0.5f) ? 1 : -1;
		speed = 0.7f * dir;
		hvsp.y = speed;
		collider.pos.x += 8.0f;
	}
	void Update();

};