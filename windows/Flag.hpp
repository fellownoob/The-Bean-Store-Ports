#pragma once
#include "Object.hpp"

class Flag : public Object {
public:
	Flag(Vector2 SpawnPos) : Object("Flag", SpawnPos, Classes::Win) {}
	void Update();
};