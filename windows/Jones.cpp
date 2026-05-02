#include "Jones.hpp"

void Jones::Update(){
	if (man.collider.pos.x > collider.pos.x) {
		dir = 1;
	}
	else {
		dir = -1;
	}
}