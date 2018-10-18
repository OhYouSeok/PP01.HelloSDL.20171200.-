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
		m_go.load(100, 100, 128, 82,1,1, "animate");
		m_player.load(300, 300, 128, 82,1,1, "animate");
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
	m_go.update();
	m_player.update();
}

void Game::render() {
	SDL_RenderClear(renderer);

	m_go.draw(renderer);
	m_player.draw(renderer);

	SDL_RenderPresent(renderer);
}

void Game::clean() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
}

