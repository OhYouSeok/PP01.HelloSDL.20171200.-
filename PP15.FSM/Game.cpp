#pragma once
#include "Game.h"
#include "WallManager.h"
#include "CollisionManager.h"
#include "MenuState.h"
#include "PlayState.h"
Game * Game::s_pInstance = 0;
Game::Game() {};
bool Game::init(std::string title, int xpos, int ypos, int width, int height, bool fullscreen) {
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		window = SDL_CreateWindow(title.c_str(), xpos, ypos, width, height, fullscreen);
		renderer = SDL_CreateRenderer(window, -1, 0);
		m_bRunning = true;

		SDL_SetRenderDrawColor(renderer, 50, 0, 0, 255);
		m_pGameStateMachine = new GameStateMachine();
		m_pGameStateMachine->changeState(MenuState::Instance());
		//if (!TheTextureManager::Instance()->load("assets/1.png", "animate", renderer)) {
		//}
		//m_gameObjects.push_back(new Player(new LoaderParams(0, 0, 128, 82, "animate")));
		return true;
	}
	else {
		return false;
	}

}
void Game::handleEvents()
{
	TheInputHandler::Instance()->update();
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RETURN))
	{
		m_pGameStateMachine->changeState(PlayState::Instance());
	}

}

void Game::update() {


	m_pGameStateMachine->update();

}

void Game::render() {
	SDL_RenderClear(renderer);
	m_pGameStateMachine->render();


	//for (std::vector<GameObject*>::size_type i = 0;
	//	i != m_gameObjects.size(); i++)
	//{
	//	m_gameObjects[i]->draw();
	//}
	//WallManager::getInstance()->draw();


	SDL_RenderPresent(renderer);
}

void Game::clean() {

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	TheInputHandler::Instance()->clean();
}

