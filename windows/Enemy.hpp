#pragma once
#include <raylib.h>
#include <rlgl.h>
#include "fcd.hpp"
#include <iostream>
#include <vector>
#include <string>

class Enemy {
public:
	Enemy(std::string name, Vector2 SpawnPos);
	virtual ~Enemy();

	void Draw();
	virtual void Update() = 0;

protected:
	std::string EnemyName;
	Vector2 pos;
	Vector2 hvsp;
	std::string FilePath;
	Image EnemyImage;
	Texture2D EnemyTexture;
	int dir = 1;
	float speed;

	fcd::Item& collider;

};