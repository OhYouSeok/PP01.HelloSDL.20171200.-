#pragma once
#include "Game.h"
#include "WallManager.h"
#include "CollisionManager.h"
Game * Game::s_pInstance = 0;
Game::Game() {};
bool Game::init(std::string title, int xpos, int ypos, int width, int height, bool fullscreen) {
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		window = SDL_CreateWindow(title.c_str(), xpos, ypos, width, height, fullscreen);
		renderer = SDL_CreateRenderer(window, -1, 0);
		m_bRunning = true;

		SDL_SetRenderDrawColor(renderer, 50, 0, 0, 255);

		if (!TheTextureManager::Instance()->load("assets/1.png", "animate", renderer)) {
		}
		if (!TheTextureManager::Instance()->load("assets/1111.png", "bullet", renderer)) {
		}
		if (!TheTextureManager::Instance()->load("assets/2.png", "Wall", renderer)) {
		}
		if (!TheTextureManager::Instance()->load("assets/qwe.png", "BreakWall", renderer)) {
		}
		m_gameObjects.push_back(new Player(new LoaderParams(0, 0, 128, 82, "animate")));
		WallManager::getInstance()->PushBackWall(new Wall(new LoaderParams(500, 20, 100, 100, "Wall")));
		return true;
	}
	else {
		return false;
	}

}
void Game::handleEvents()
{
	TheInputHandler::Instance()->update();
}

void Game::update() {
	for (std::vector<GameObject*>::size_type i = 0;
		i != m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
	WallManager::getInstance()->update();
	CollisionManager::getInstance()->update();
}

void Game::render() {
	SDL_RenderClear(renderer);

	for (std::vector<GameObject*>::size_type i = 0;
		i != m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
	WallManager::getInstance()->draw();
	SDL_RenderPresent(renderer);
}

void Game::clean() {
	m_bRunning = false;
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	TheInputHandler::Instance()->clean();
}

