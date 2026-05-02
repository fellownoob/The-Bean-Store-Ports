#pragma once
#include "Object.hpp"
#include "Man.hpp"


class Jones : public Object {
public:
	Jones(Vector2 SpawnPos) : Object("Jones", SpawnPos, Classes::CJ) {}
	void Update();
};