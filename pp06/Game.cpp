#include "Game.h"
#include <SDL_image.h>

bool Game::init(const char*title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, fullscreen);
	m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
	SDL_Surface* pTempSurface = IMG_Load("assets/animate-alpha.png");
	m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer,
		pTempSurface);
	SDL_FreeSurface(pTempSurface);
	SDL_SetRenderDrawColor(m_pRenderer, 255, 0, 0, 255);
	SDL_QueryTexture(m_pTexture, NULL, NULL, &m_sourceRectangle.w, &m_sourceRectangle.h);
	m_sourceRectangle.w = 128;
	m_sourceRectangle.h = 82;

	m_destinationRectangle.x = m_sourceRectangle.x = 0;
	m_destinationRectangle.y = m_sourceRectangle.y = 0;
	m_destinationRectangle.w = m_sourceRectangle.w;
	m_destinationRectangle.h = m_sourceRectangle.h;
	return true;
}

void Game::render() {
	SDL_RenderClear(m_pRenderer);
	SDL_RenderCopy(m_pRenderer, m_pTexture,
		&m_sourceRectangle, &m_destinationRectangle);
	SDL_RenderPresent(m_pRenderer); // draw to the screen
}
void Game::update() {
	m_sourceRectangle.x = 128 * int(((SDL_GetTicks() / 100) % 6));

}
void Game::clean() {
	std::cout << "cleaning game\n";
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}

void Game::handleEvents() {
	SDL_Event event;
	if (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:
			m_bRunning = false;
			break;
		default:
			break;
		}
	}
}