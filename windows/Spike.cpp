#include "Spike.hpp"

void Spike::Update() {
	dir = (float((rand() & 2)) > 0.5f) ? 1 : -1;
}