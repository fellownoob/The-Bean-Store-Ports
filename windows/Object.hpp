#pragma once
#include <raylib.h>
#include <rlgl.h>
#include "fcd.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Object {
public:
	Object(std::string name, Vector2 SpawnPos, Classes FCDClass);
	virtual ~Object();

	virtual void Draw();
	virtual void Update() = 0;
	std::string ObjectName;
	int timer = 0;

protected:
	Vector2 pos;
	Vector2 hvsp;
	std::string FilePath;
	Image ObjectImage;
	Texture2D ObjectTexture;
	int dir = 1;
	float speed;

	fcd::Item& collider;

};