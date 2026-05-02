#include "fcd.hpp"
fcd CollisionDetection;

fcd::fcd() {

}

fcd::Item& fcd::newItem(const std::string& pn, float px, float py, int pw, int ph, Classes pc) {
	items.push_back({ pn, {px, py}, pw, ph, pc });
	return items.back();
}


void fcd::deleteItem(Item& item) {
	//auto it = std::find(items.begin(), items.end(), item);
	//if (it != items.end()) {
	//	items.erase(it);
	//}
	items.remove(item);
}

void fcd::deleteClass(Classes pc) {
	std::cout << "n\n";
	if (items.empty()) return;
	items.remove_if([pc](const Item& item) {
		return item.c == pc;
	});
}

void fcd::deleteAllItems() {
	items.clear();
}

bool fcd::rectIntersecting(float x1, float y1, int w1, int h1, float x2, float y2, int w2, int h2) {
	return x1 < x2 + w2 && x2 < x1 + w1 && y1 < y2 + h2 && y2 < y1 + h1;
}

bool fcd::rectItemIntersecting(float x1, float y1, int w1, int h1, Item& item) {
	return fcd::rectIntersecting(x1, y1, w1, h1, item.pos.x, item.pos.y, item.w, item.h);
}

fcd::Item* fcd::rectClassIntersecting(float px, float py, int pw, int ph, Classes pc) {
	for (auto& item : items) {
		if (item.c == pc && fcd::rectItemIntersecting(px, py, pw, ph, item)) {
			return &item;
		}
	}
	return nullptr;
}

bool fcd::itemClassIntersecting(Item& item, Classes pc) {
	return fcd::rectClassIntersecting(item.pos.x, item.pos.y, item.w, item.h, pc);
}

void fcd::draw() {
	for (auto& item : items) {
		Color color = WHITE;
		switch (item.c) {
			case Classes::Solid:  color = { 0,   0,   0,   255 }; break;
			case Classes::Die:  color = { 204, 0,   0,   255 }; break;
			case Classes::Win:   color = { 204, 204, 0,   255 }; break;
			case Classes::Bean:  color = { 102, 102, 0, 255 }; break;
			case Classes::Player: color = { 0,   204, 0,   255 }; break;
			case Classes::CJ:  color = { 0,   102, 204, 255 }; break;
			case Classes::Dead: color = { 128, 128, 128, 255 }; break;
		}
		DrawRectangle((int)item.pos.x, (int)item.pos.y, item.w, item.h, color);
	}
}

