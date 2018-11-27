#include "PlayState.h"
#include "Game.h"
const std::string PlayState::s_playID = "PLAY";
PlayState * PlayState::s_pInstance = 0;
void PlayState::update()
{
	//for (std::vector<GameObject*>::size_type i = 0;
	//	i != m_gameObjects.size(); i++)
	//{
	//	m_gameObjects[i]->update();
	//}
	//WallManager::getInstance()->update();
	//CollisionManager::getInstance()->update();
}
void PlayState::render()
{
	// nothing for now
}

bool PlayState::onEnter()
{
	std::cout << "entering PlayState\n";
	return true;
}

bool PlayState::onExit()
{
	std::cout << "exiting PlayState\n";
	return true;
}