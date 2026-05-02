#pragma once
#include <raylib.h>
#include <iostream>
#include <algorithm>
#include <list>
#include <string>

typedef enum Classes {Player,Solid,Die,Win,CJ,Bean,Dead} Classes;

class fcd {
public:
	struct Item
	{
		std::string name = "a name";
		Vector2 pos = {0, 0};
		int w = 32;
		int h = 32;
		Classes c = Solid;
		bool operator==(const Item& other) const {
			return name == other.name && pos.x == other.pos.x && pos.y == other.pos.y && w == other.w && h == other.h && c == other.c;
		}

	};
	fcd();
	Item& newItem(const std::string& pn, float px, float py, int pw, int ph, Classes pc);
	void deleteItem(Item& item);
	void deleteClass(Classes pc);
	void deleteAllItems();
	bool rectItemIntersecting(float x1,float y1,int w1, int h1, Item& item);
	bool rectIntersecting(float x1, float y1, int w1, int h1, float x2, float y2, int w2, int h2);
	fcd::Item* rectClassIntersecting(float px, float py, int pw, int ph, Classes pc);
	bool itemClassIntersecting(Item& item, Classes pc);
	std::list<Item> items;
	void draw();
	
private:
};


extern fcd CollisionDetection;