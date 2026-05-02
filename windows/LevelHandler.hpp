#pragma once
#include <raylib.h>
#include <raylib-tileson.h>
#include <iostream>
#include <fstream>
#include <string>
#include "fcd.hpp"
#include <json.hpp>
#include "Man.hpp"
#include "Spike.hpp"
#include "Shard.hpp"
#include "Roamer.hpp"
#include "Corpse.hpp"
#include "Flag.hpp"
#include "Jones.hpp"
#include "GlassDoor.hpp"
#include "Beans.hpp"
#include "Text.hpp"

using json = nlohmann::json;

class LevelHandler {
private:
	int CurrentLevel;
	std::list<std::unique_ptr<Object>> objects;
	std::list<std::unique_ptr<Enemy>> enemies;
	std::string Level;
	Map TiledLevel;
	float CurrentTime;
	std::ifstream LevelFile;
	Vector2 PlayerSpawnLocation;
	void Init();
	void SetObject(auto obj);
	json LevelData;
	Text text;
public:
	LevelHandler();
	Vector2 GetSpawnLocation();
	void Clean();
	void SpawnCorpse(Vector2 pos, Vector2 velocity);
	void Start();
	~LevelHandler();
	int GetLevel();
	void SetLevel(int level);
	void NextLevel();
	void PrevLevel();
	void Update();
	void DrawLevel();
};

extern LevelHandler levelhandler;