#pragma once
#include <raylib.h>
#include <rlgl.h>
#include "fcd.hpp"
#include <iostream>
#include <vector>
#include <string>
#include "LevelHandler.hpp"

extern fcd CollisionDetection;

class Man {
public:
	Man(Vector2 SpawnPos);
	~Man();
	fcd::Item& collider;
	void init();
	void draw();
	void update();
	void respawn(float x, float y);
	bool beanCollected = false;
private:
	Image manImage;
	Texture2D manTexture;
	Vector2 spawn;
	Vector2 hvsp;
	Sound SJump;
	Sound SDie;
	Sound SFall;
	const float speed = 1.33f;
	int dir = 1; 
	const float jumpPower = 2.65f;
	const float gravity = 0.05f;
	int scaleX = 1;
	int flipCharacter();
	bool grounded = false;
};

extern Man man;
