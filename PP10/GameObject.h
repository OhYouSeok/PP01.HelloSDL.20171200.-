#pragma once
#include <SDL.h>
#include <iostream>
#include "TextureManager.h"

class GameObject
{
public:
	virtual void load(int x, int y, int width, int height, int currentRow, int currentFrame,
		std::string textureID);
	virtual void draw(SDL_Renderer* pRenderer);
	virtual void update();
	virtual void clean() {};
	virtual void ChangeSpeed();
protected:
	std::string m_textureID;
	int m_currentFrame;
	int m_currentRow;
	int m_x;
	int m_y;
	int m_width;
	int m_height;
};