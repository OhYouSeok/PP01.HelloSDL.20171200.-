#include "MenuState.h"
#include "Player.h"
#include "Game.h"
const std::string MenuState::s_menuID = "MENU";
MenuState * MenuState::s_pInstance = 0;

void MenuState::update()
{
	// nothing for now
}

void MenuState::render()
{
	// nothing for now
}

bool MenuState::onEnter()
{
	std::cout << "entering MenuState\n";
	if (!TheTextureManager::Instance()->load("assets/1.png", "animate", TheGame::Instance()->getRenderer())) {
	}
	m_gameObjects.push_back(new Player(new LoaderParams(0, 0, 128, 82, "animate")));

	for (std::vector<GameObject*>::size_type i = 0;
		i != m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}

	return true;
}

bool MenuState::onExit()
{
	std::cout << "exiting MenuState\n";
	return true;
}