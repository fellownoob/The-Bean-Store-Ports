#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
#include <raylib.h>
#define RAYLIB_TILESON_IMPLEMENTATION
#include "raylib-tileson.h"
#include <UpdateAndDraw.hpp>
#include <iostream>




int main() {
	float resMul = 2.0f;
	InitWindow((int)(480*resMul), (int)(352*resMul), "The Bean Store");
	InitAudioDevice();

	UpdateAndDraw uandd;
	SetTargetFPS(144);
	Image windowIcon = LoadImage("res/sprites/objects/Beans.png");
	SetWindowIcon(windowIcon);

	while (!WindowShouldClose()) {
		uandd.Update();

		BeginDrawing();
		rlScalef(resMul, resMul, 0.0f);
		uandd.Draw();

		EndDrawing();
	}
	
	CloseAudioDevice();

	CloseWindow();
	return 0;
}