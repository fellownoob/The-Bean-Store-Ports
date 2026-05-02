#include "Object.hpp"

Object::Object(std::string name, Vector2 SpawnPos, Classes FCDClass) :
    ObjectName(name),
    pos(SpawnPos),
    FilePath("res/sprites/objects/" + name + ".png"),
    hvsp({ 0, 0 }),
    speed(0),
    ObjectImage(LoadImage(FilePath.c_str())),
    ObjectTexture(LoadTextureFromImage(ObjectImage)),
    collider(CollisionDetection.newItem(ObjectName, pos.x, pos.y, ObjectTexture.width, ObjectTexture.height, FCDClass))

{
    UnloadImage(ObjectImage);
}

void Object::Draw() {
    DrawTexturePro(ObjectTexture, { 0,0,(float)ObjectTexture.width * (float)dir,(float)ObjectTexture.height }, { collider.pos.x,collider.pos.y,(float)ObjectTexture.width,(float)ObjectTexture.height }, { 0.0f, 0.0f }, 0, { 255,255,255,255 });
}

Object::~Object() {
    UnloadTexture(ObjectTexture);
    CollisionDetection.deleteItem(collider);
}