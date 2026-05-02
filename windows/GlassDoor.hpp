#pragma once
#include "Object.hpp"

class StoreDoor : public Object {
public:
	StoreDoor(Vector2 SpawnPos) : Object("StoreDoor", SpawnPos, Classes::Win) {}
	void Update();
};