#include "GameObject.h"

void GameObject::load(int x, int y, int width, int height, int currentRow, int currentFrame,
	std::string textureID)
{
	m_x = x;
	m_y = y;
	m_width = width;
	m_height = height;
	m_textureID = textureID;
	m_currentRow = currentRow;
	m_currentFrame = 1;
}

void GameObject::draw(SDL_Renderer* pRenderer)
{
	
	TheTextureManager::Instance()->draw(m_textureID,
		m_x, m_y, m_width, m_height, pRenderer);
}

void GameObject::update()
{
	m_currentFrame = int((SDL_GetTicks() / 100 % 6));
}

void GameObject::ChangeSpeed() {

}
