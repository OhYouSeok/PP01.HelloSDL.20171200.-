#pragma once
#include "SDLGameObject.h"
#include "Game.h"

SDLGameObject::SDLGameObject(const LoaderParams* pParams) : GameObject(pParams),m_position(pParams->getX(),pParams->getY()),m_velocity(0.0f,0.0f),m_acceleration(0.0f,0.0f)
{
	m_width = pParams->getWidth();
	m_height = pParams->getHeight();

	m_textureID = pParams->getTextureID();
	m_currentRow = 1;
	m_currentFrame = 1;
}

void SDLGameObject::draw()
{
	TextureManager::Instance()->draw(m_textureID,(int)m_position.getX(), (int)m_position.getY(),
		m_width, m_height, TheGame::Instance()->getRenderer());
}

SDL_Rect SDLGameObject::getRect() 

{
	SDL_Rect rect;
	rect.x = (int)m_position.getX();
	rect.y = (int)m_position.getY();
	rect.w = rect.x + m_width;
	rect.h = rect.y + m_height;
    return rect;

}
void SDLGameObject::update() {
	m_velocity += m_acceleration;
	m_position += m_velocity;
}
std::string SDLGameObject::getTextureID() const

{
	return m_textureID;
}