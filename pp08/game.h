#include "TextureManager.h"

class Game {
public:
	Game();
	~Game();

	bool init(std::string title, int xpos, int ypos, int width, int height, bool fullscreen);
	void update();
	void render();
	void clean();
	void handleEvents();
	bool running() { return m_bRunning; }

private:
	bool m_bRunning;
	SDL_Window * window;
	SDL_Renderer * renderer;

	int currentRow = 1;
	int currentFrame = 1;
};
#pragma once
