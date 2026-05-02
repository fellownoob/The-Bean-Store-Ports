#include "Man.hpp"
Man man({0.0f,0.0f});

Man::Man(Vector2 SpawnPos)
	: spawn(SpawnPos),
	hvsp({ 0,0 }),
	collider(CollisionDetection.newItem("Man", SpawnPos.x, SpawnPos.y, 24, 28, Player))
{
}

Man::~Man() {
	UnloadSound(SJump);
	UnloadSound(SDie);
	UnloadSound(SFall);
}

void Man::init() {
	SJump = LoadSound("res/audio/Jump.wav");
	SDie = LoadSound("res/audio/uuhhh.wav");
	SFall = LoadSound("res/audio/AAAA.wav");
	SetSoundVolume(SJump, 0.5);
	SetSoundVolume(SDie, 0.5);
	SetSoundVolume(SFall, 0.5);

	manImage = LoadImage("res/sprites/objects/Man.png");
	manTexture = LoadTextureFromImage(manImage);
	UnloadImage(manImage);
}

int Man::flipCharacter() {
	if (dir != 0)
		scaleX = dir;
	return scaleX;
}

void Man::respawn(float x, float y) {
	collider.pos.x = x;
	collider.pos.y = y;
	hvsp.x = 0;
	hvsp.y = 0;
}

void Man::draw() {
	DrawTexturePro(manTexture, { 0,0,48 * float(Man::flipCharacter()),56}, {collider.pos.x,collider.pos.y,24,28}, {0.0f, 0.0f}, 0, {255,255,255,255});
}

void Man::update() {
	float lastVsp = hvsp.y;
	grounded = false;
	bool right = IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D);
	bool left = IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A);
	bool up = IsKeyDown(KEY_UP) || IsKeyDown(KEY_W) || IsKeyDown(KEY_SPACE);
	dir = right-left;

	auto* winsolid = CollisionDetection.rectClassIntersecting(collider.pos.x, collider.pos.y, collider.w, collider.h, Win);


	if (auto* solid = CollisionDetection.rectClassIntersecting(collider.pos.x, collider.pos.y, collider.w, collider.h, Die)) {
		levelhandler.SpawnCorpse(collider.pos, hvsp);
		respawn(levelhandler.GetSpawnLocation().x, levelhandler.GetSpawnLocation().y);
		PlaySound(SDie);

	}
	if (collider.pos.y > 352) {
		respawn(levelhandler.GetSpawnLocation().x, levelhandler.GetSpawnLocation().y);
		PlaySound(SFall);

	}

	if ((winsolid && levelhandler.GetLevel() != 17) || (winsolid && beanCollected)) {
		levelhandler.NextLevel();
	}


	hvsp.x = (speed * dir);
	hvsp.y += (float)gravity;

	if(auto* solid = CollisionDetection.rectClassIntersecting(collider.pos.x,collider.pos.y+hvsp.y,collider.w,collider.h,Solid)){
        if (collider.pos.y < collider.pos.y+hvsp.y)
            grounded = true;
        
		while (std::abs(hvsp.y) > 0.1f) {
                hvsp.y *= 0.5f;
                if(!CollisionDetection.rectClassIntersecting(collider.pos.x,collider.pos.y+hvsp.y,collider.w,collider.h,Solid))
					collider.pos.y += hvsp.y; 
        }
        hvsp.y = 0.0f;
	}
    collider.pos.y += hvsp.y;

	if (up && grounded && hvsp.y > -1.0f) {
		hvsp.y = -jumpPower;
		PlaySound(SJump);
	}

	if (auto* solid = CollisionDetection.rectClassIntersecting(collider.pos.x+hvsp.x, collider.pos.y, collider.w, collider.h, Solid)) {

		while (std::abs(hvsp.x) > 0.1f) {
			hvsp.x *= 0.5f;
			if (!CollisionDetection.rectClassIntersecting(collider.pos.x + hvsp.x, collider.pos.y, collider.w, collider.h, Solid))
				collider.pos.x += hvsp.x;
		}
		hvsp.x = 0.0f;
	}
	collider.pos.x += hvsp.x;


}