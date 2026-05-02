#pragma once
#include "Object.hpp"
#include "Man.hpp"

class Beans : public Object {
public:
	Beans(Vector2 SpawnPos) : Object("Beans", SpawnPos, Classes::Bean) {}
	~Beans();
	void Draw();
	void Update();
private:
	bool beanCollected = false;
	bool beanAte = false;
	Sound SEat = LoadSound("res/audio/Eat.wav");
	Sound SCoin = LoadSound("res/audio/Coin.wav");
	float rot = 0;
	int itt = 0;
	float scale = 1;
	Vector2 BeanPos = {collider.pos.x, collider.pos.y};
};