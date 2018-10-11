#include "game.h"

Game::Game() {};
Game::~Game() {};

bool Game::init(std::string title, int xpos, int ypos, int width, int height, bool fullscreen) {
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		window = SDL_CreateWindow( title.c_str(), xpos, ypos, width, height, fullscreen);
		renderer = SDL_CreateRenderer(window, -1, 0);
		m_bRunning = true;

		SDL_SetRenderDrawColor(renderer, 50, 0, 0, 255);

		if (!TheTextureManager::Instance()->load("assets/animate-alpha.png", "animate", renderer)) {
		}

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
	currentFrame = int((SDL_GetTicks() / 100 % 6));
}

void Game::render() {
	SDL_RenderClear(renderer);

	TheTextureManager::Instance()->drawFrame("animate", 0, 0, 128, 82, currentRow, currentFrame, renderer, SDL_FLIP_NONE);
	TheTextureManager::Instance()->draw("animate", 100, 100, 128, 82,renderer, SDL_FLIP_NONE);

	SDL_RenderPresent(renderer);
}

void Game::clean() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
}

