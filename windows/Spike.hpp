#pragma once
#include "Enemy.hpp"

class Spike : public Enemy {
public:
	Spike(Vector2 SpawnPos) : Enemy("Spike", SpawnPos) {}
	void Update();
	
};