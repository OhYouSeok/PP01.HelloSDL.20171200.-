#include "Game.h"

Game::Game() {};
Game::~Game() {};

bool Game::init(std::string title, int xpos, int ypos, int width, int height, bool fullscreen) {
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		window = SDL_CreateWindow(title.c_str(), xpos, ypos, width, height, fullscreen);
		renderer = SDL_CreateRenderer(window, -1, 0);
		m_bRunning = true;

		SDL_SetRenderDrawColor(renderer, 50, 0, 0, 255);

		if (!TheTextureManager::Instance()->load("assets/animate-alpha.png", "animate", renderer)) {
		}
		m_go = new GameObject();
		m_player = new Player();
		m_enemy = new Enemy();

		m_go->load(100, 100, 128, 82,1,1, "animate");
		m_player->load(300, 300, 128, 82,1,1, "animate");
		m_enemy->load(0, 0, 128, 82,1,1, "animate");

		m_gameObjects.push_back(m_go);
		m_gameObjects.push_back(m_player);
		m_gameObjects.push_back(m_enemy);
		return true;
	}
	else {
		return false;
	}

}

void Game::handleEvents() {
	SDL_Event event;
	if (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_KEYUP:
			m_bRunning = false;
			break;
		default:
			break;

		}
	}
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
		m_gameObjects[i]->draw(renderer);
	}

	SDL_RenderPresent(renderer);
}

void Game::clean() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
}

