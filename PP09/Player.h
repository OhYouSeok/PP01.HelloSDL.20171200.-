#pragma once
#include "GameObject.h"

class Player :public GameObject {
public:
	void load(int x, int y, int width, int height, int currentRow, int currentFrame, std::string textureID);
	void draw(SDL_Renderer* pRenderer);
	void update();
	void clean();
};