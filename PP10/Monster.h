#pragma once
#include "GameObject.h"

class Monster :public GameObject {
public:
	void load(int x, int y, int width, int height, int currentRow, int currentFrame, std::string textureID);
	void draw(SDL_Renderer* pRenderer);
	void update();
	void ChangeSpeed();
	void clean() {};
	int XSpeed = 1;
private:
}; 
