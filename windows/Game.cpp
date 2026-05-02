#include "Game.hpp"


Game::Game() :
	MOverworld(LoadMusicStream("res/audio/OverworldDistorted.mp3")),
	MBeanStore(LoadMusicStream("res/audio/Bean Store.mp3")),
	MEnd(LoadMusicStream("res/audio/End.mp3"))
{
	MOverworld.looping = true;
	MBeanStore.looping = true;
	MEnd.looping = false;
	levelhandler.Start();
	man.init();
	currentMusic = (levelhandler.GetLevel() < 17) ? &MOverworld : (levelhandler.GetLevel() == 17) ? &MBeanStore : &MEnd;

}

Game::~Game() {
	UnloadMusicStream(MOverworld);
	UnloadMusicStream(MBeanStore);
	UnloadMusicStream(MEnd);
	levelhandler.Clean();
	CollisionDetection.deleteAllItems();
}

void Game::Draw() {
	if (levelhandler.GetLevel() != 17) {
		ClearBackground({ 102,195,255,255 });
	}else{
		ClearBackground({ 157,159,166,255 });
	}
	levelhandler.DrawLevel();
	man.draw();

	//CollisionDetection.draw();
}

void Game::Update() {

	Music* lastMusic = currentMusic;
	currentMusic = (levelhandler.GetLevel() < 17) ? &MOverworld : (levelhandler.GetLevel() == 17) ? &MBeanStore : &MEnd;
	SetMusicVolume(MOverworld, (levelhandler.GetLevel() == 16) ? 0.75f : 1.0f);

	UpdateMusicStream(*currentMusic);

	if (currentMusic == &MEnd && lastMusic != currentMusic) {
		PlayMusicStream(*currentMusic);
	}
	if (currentMusic != &MEnd && !IsMusicStreamPlaying(*currentMusic)) {
		PlayMusicStream(*currentMusic);
	}
	levelhandler.Update();
	man.update();
}