#pragma once
#include <raylib.h>
#include <rlgl.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

class Text {
public:
	Text();
	~Text();
	void Init();

	void Make(std::string text);
	void Draw();
	void Update();
private:
	struct DrawTextEntry {
		char character;
		Vector2 position;
	};
	bool done = false;
	float timer = 0;
	int itt = 1;
	std::string text = "";
	char drawing[1];
	Vector2 Position;
	std::vector<DrawTextEntry> drawText;
	Texture2D FindTexture(char character);
	std::unordered_map<char, Texture2D> letterTextures;



	Texture2D CTexture;

	Texture2D OTexture;

	Texture2D NTexture;

	Texture2D GTexture;

	Texture2D RTexture;

	Texture2D ATexture;

	Texture2D TTexture;

	Texture2D UTexture;

	Texture2D LTexture;

	Texture2D ITexture;

	Texture2D STexture;

	Texture2D ETexture;

	Texture2D MTexture;
	
	Texture2D ColonTexture;
	
	//numbers

	Texture2D OneTexture;

	Texture2D TwoTexture;

	Texture2D ThreeTexture;

	Texture2D FourTexture;

	Texture2D FiveTexture;

	Texture2D SixTexture;

	Texture2D SevenTexture;

	Texture2D EightTexture;

	Texture2D NineTexture;

	Texture2D ZeroTexture;

};