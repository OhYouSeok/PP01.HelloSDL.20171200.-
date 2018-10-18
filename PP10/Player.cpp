#include "Player.h"

void Player::load(int x, int y, int width, int height, int currentRow, int currentFrame,
	std::string textureID)
{
	GameObject::load(x, y, width, height, currentRow, currentFrame, textureID);
}

void Player::draw(SDL_Renderer* pRenderer)
{
	GameObject::draw(pRenderer);
}

void Player::update()
{
	m_x -= 1;
}