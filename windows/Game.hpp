#pragma once
#include <raylib.h>
#include "fcd.hpp"
#include "Man.hpp"
#include <iostream>
#include "LevelHandler.hpp"
extern LevelHandler levelhandler;

class Game {
private:
	Music MOverworld;
	Music MBeanStore;
	Music MEnd;
	Music* currentMusic;
	
public:
	Game();
	~Game();
	void Update();
	void Draw();
	void GetElapsedTime();

};