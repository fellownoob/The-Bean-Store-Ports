#include "LevelHandler.hpp"
LevelHandler levelhandler;

LevelHandler::LevelHandler() {

}

Vector2 LevelHandler::GetSpawnLocation() {
	return PlayerSpawnLocation;
}

void LevelHandler::Start() {
	CurrentLevel = 0;
	Level = "res/maps/level_" + std::to_string(CurrentLevel) + ".json";
	TiledLevel = LoadTiled(Level.c_str());
	CurrentTime = 0;
	text.Init();
	Init();
}

LevelHandler::~LevelHandler() {
	
}

void LevelHandler::Init() {
	Clean();
	UnloadMap(TiledLevel);
	Level = "res/maps/level_" + std::to_string(CurrentLevel) + ".json";
	TiledLevel = LoadTiled(Level.c_str());
	std::ifstream LevelFile(Level.c_str());
	if (CurrentLevel == 18) {
		text.Make("CONGRATULATIONS@TIME:" + std::to_string(int(CurrentTime)));
	}
	if (!LevelFile.is_open()) {
		std::cerr << "Nah mate\n";
		
	}
	else {
		std::cout << "Ye\n";
	}
	LevelFile >> LevelData;
	for (const auto& item : LevelData["layers"]) {
		if (item["type"] == "objectgroup") {
			if (item["name"] == "Solid") {
				for (const auto& object : item["objects"]) {
					CollisionDetection.newItem("Solid", (float)object["x"], (float)object["y"], (float)object["width"], (float)object["height"], Solid);
				}
			}
		}
	}
	for (const auto& item : LevelData["layers"]) {
		if (item["type"] == "objectgroup") {
			if (item["name"] == "Objects") {
				for (const auto& object : item["objects"]) {
					SetObject(object);
				}
			}
		}
	}
}

void LevelHandler::SetObject(auto obj) {
	if (obj["type"] == "man") {
		PlayerSpawnLocation.x = (float)obj["x"] + 4.0f;
		PlayerSpawnLocation.y = (float)obj["y"] + 4.0f;
		man.respawn(PlayerSpawnLocation.x, PlayerSpawnLocation.y);
	}
	else if (obj["type"] == "flag")
		objects.push_back(std::make_unique<Flag>(Vector2{ (float)obj["x"], (float)obj["y"] }));
	else if (obj["type"] == "spike")
		enemies.push_back(std::make_unique<Spike>(Vector2{ (float)obj["x"], (float)obj["y"] }));
	else if (obj["type"] == "shard")
		enemies.push_back(std::make_unique<Shard>(Vector2{ (float)obj["x"], (float)obj["y"] }));
	else if (obj["type"] == "ghost")
		enemies.push_back(std::make_unique<Roamer>(Vector2{ (float)obj["x"], (float)obj["y"] }));
	else if (obj["type"] == "jones")
		objects.push_back(std::make_unique<Jones>(Vector2{ (float)obj["x"], (float)obj["y"] }));
	else if (obj["type"] == "beans")
		objects.push_back(std::make_unique<Beans>(Vector2{ (float)obj["x"], (float)obj["y"] }));
	else if (obj["type"] == "glassdoor")
		objects.push_back(std::make_unique<StoreDoor>(Vector2{ (float)obj["x"], (float)obj["y"] }));
}

void LevelHandler::Clean() {
	if (!CollisionDetection.items.empty()) {
		CollisionDetection.deleteClass(Solid);
	}
	enemies.clear();
	objects.clear();
}

void LevelHandler::SpawnCorpse(Vector2 pos, Vector2 velocity) {
	objects.push_back(std::make_unique<Corpse>(pos,velocity));
}

int LevelHandler::GetLevel() {
	return CurrentLevel;
}

void LevelHandler::SetLevel(int level) {
	CurrentLevel = level;
	Init();
}
void LevelHandler::NextLevel() {
	CurrentLevel++;
	Init();
}
void LevelHandler::PrevLevel() {
	CurrentLevel--;
	Init();
}
void LevelHandler::DrawLevel() {
	if (!Level.empty() && IsTiledReady(TiledLevel)) {
		DrawTiled(TiledLevel, 0, 0, WHITE);
	}
	for (auto& enemy : enemies) {
		enemy->Draw();
	}
	for (auto& object : objects) {
		object->Draw();
	}
	text.Draw();
}
void LevelHandler::Update() {
	CurrentTime += GetFrameTime();
	for (auto& enemy : enemies) {
		enemy->Update();
	}
	for (auto& object : objects) {
		object->Update();
	}
	text.Update();
}