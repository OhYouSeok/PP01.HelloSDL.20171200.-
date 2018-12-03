#include "Bullet.h"

Bullet::Bullet(const LoaderParams* pParams) : SDLGameObject(pParams)
{
}
void Bullet::draw()
{
	SDLGameObject::draw(); 
}
void Bullet::update()
{
	m_velocity.setX(10);
	SDLGameObject::update();
}
void Bullet::clean()
{
}

void Bullet::handleInput() {

}

std::vector<Bullet*> Bullet::getBullets() const
{
	return _bullets;
}


