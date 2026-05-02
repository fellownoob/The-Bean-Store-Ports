#include "Enemy.hpp"

Enemy::Enemy(std::string name, Vector2 SpawnPos) :
    EnemyName(name),
    pos(SpawnPos),
    FilePath("res/sprites/objects/" + name + ".png"),
    hvsp({ 0, 0 }),
    speed(0),
    EnemyImage(LoadImage(FilePath.c_str())),
    EnemyTexture(LoadTextureFromImage(EnemyImage)),
    collider(CollisionDetection.newItem(EnemyName, pos.x, pos.y, EnemyTexture.width, EnemyTexture.height, Classes::Die))

{
    UnloadImage(EnemyImage);
}

void Enemy::Draw() {
	DrawTexturePro(EnemyTexture, { 0,0,(float)EnemyTexture.width * (float)dir,(float)EnemyTexture.height}, { collider.pos.x,collider.pos.y,(float)EnemyTexture.width,(float)EnemyTexture.height }, { 0.0f, 0.0f }, 0, { 255,255,255,255 });
}

Enemy::~Enemy() {
    CollisionDetection.deleteItem(collider);
	UnloadTexture(EnemyTexture);
}