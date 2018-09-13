#include <SDL.h>
#include <iostream>
class Game
{
public:
	Game(){	}
	~Game(){}
	bool init(const char*title, int xpos, int ypos, int width, int height, bool fullscreen);
	void render();
	void update() {};
	void clean();
	void handleEvents();
	bool running(){ return m_bRunning; }
private:
	SDL_Window * m_pWindow;
	SDL_Renderer* m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);;
	bool m_bRunning;
};
