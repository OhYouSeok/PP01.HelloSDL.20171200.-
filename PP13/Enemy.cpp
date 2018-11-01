#include "Enemy.h"

Enemy::Enemy(const LoaderParams* pParams) : SDLGameObject(pParams)
{
}
void Enemy::draw()
{
	SDLGameObject::draw(); // we now use SDLGameObject
}
void Enemy::update()
{
	m_position.setX(m_position.getX() + 1);
	m_position.setY(m_position.getY() + 1);
	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
}
void Enemy::clean()
{
}

void Enemy::handleInput() {
	// void Enemy::handleInput() �߰� : ���콺 button
	if (TheInputHandler::Instance()->getMouseButtonState(TheInputHandler::LEFT))
	{
		m_velocity.setX(1);
	}

	// void Enemy::handleInput() �߰� : ���콺 motion
	Vector2D* vec = TheInputHandler::Instance()->getMousePosition();
	m_velocity = (*vec - m_position) / 100;
}