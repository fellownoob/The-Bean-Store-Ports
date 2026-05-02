#pragma once
#include <raylib.h>
#include <iostream>
#include "Game.hpp"

class UpdateAndDraw {
public:
	UpdateAndDraw();
	~UpdateAndDraw();
	Game game;
	void Update();
	void Draw();
};