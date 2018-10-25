#include "Monster.h"

void Monster::load(int x, int y, int width, int height, int currentRow, int currentFrame,
	std::string textureID)
{
	GameObject::load(x, y, width, height, currentRow, currentFrame, textureID);
}

void Monster::draw(SDL_Renderer* pRenderer)
{
	GameObject::draw(pRenderer);
}

void Monster::update()
{
	m_x += XSpeed;
	if (m_x <= 0 ) {
		XSpeed = abs(XSpeed);
	}
	else if (m_x >= 300) {
		XSpeed = -XSpeed;
	}
}

void Monster::ChangeSpeed() {
	XSpeed = 3;
}