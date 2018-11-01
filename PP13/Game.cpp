#pragma once
#include "Game.h"

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
		m_gameObjects.push_back(new Player(new LoaderParams(0, 0, 128, 82, "animate")));
		m_gameObjects.push_back(new Enemy(new LoaderParams(300, 300, 128, 82, "animate")));
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
}

void Game::render() {
	SDL_RenderClear(renderer);

	for (std::vector<GameObject*>::size_type i = 0;
		i != m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}

	SDL_RenderPresent(renderer);
}

void Game::clean() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	TheInputHandler::Instance()->clean();
}

