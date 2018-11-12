#include "Player.h"
#include "Game.h"
#include "BulletManager.h"

Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams)
{
}
void Player::draw()
{
	SDLGameObject::draw(); // we now use SDLGameObject
	BulletManager::getInstance()->draw();
	//for (std::vector<Bullet*>::size_type i = 0;
	//	i != m_Bullets.size(); i++)
	//{
	//	m_Bullets[i]->draw();
	//}
}
void Player::update()
{
	BulletManager::getInstance()->update();
	//for (std::vector<Bullet*>::size_type i = 0;
	//	i != m_Bullets.size(); i++)
	//{
	//	m_Bullets[i]->update();
	//}
	m_velocity.setX(0);
	m_velocity.setY(0);
	handleInput(); // add our function
	SDLGameObject::update();
}
void Player::clean()
{
	BulletManager::getInstance()->clean();
}
void Player::handleInput()
{
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
	{
		m_velocity.setX(2);
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
	{
		m_velocity.setX(-2);
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP))
	{
		m_velocity.setY(-2);
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN))
	{
		m_velocity.setY(2);
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_1)) {
		TheGame::Instance()->clean();
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_SPACE)) {
		/*m_Bullets.push_back(new Bullet(new LoaderParams(m_position.getX()+50, m_position.getY()+50, 10, 10, "bullet")));*/
		BulletManager::getInstance()->PushBackBullet(new Bullet(new LoaderParams(m_position.getX()+50, m_position.getY()+50, 10, 10, "bullet")));
	}

}