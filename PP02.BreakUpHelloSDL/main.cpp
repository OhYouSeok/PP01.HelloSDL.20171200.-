#include <SDL.h>
SDL_Window* g_pWindow = 0;
SDL_Renderer* g_pRenderer = 0;
void init(){}
void render(){
	SDL_SetRenderDrawColor(g_pRenderer, 0, 0, 127, 255);
	SDL_RenderClear(g_pRenderer);
	SDL_RenderPresent(g_pRenderer);
}
void update(){}
void handleEvents(){}
void clean(){}

bool g_bRunning = false;

int main()
{
	init();
	while (g_bRunning) {
		handleEvents();
		update();
		render();
	}
	clean();
	return 0;
}

bool init(const char *title, int xpos, int ypos, int width, int height, int flags) {
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0) {
		g_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

		if (g_pWindow != 0)
		{
			g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0);
		}
		else { return false; }
	}
	return true;
}

int main(int argc, char* argv[]) {
	if (init("Game FrameWork", SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		1024, 768, SDL_WINDOW_SHOWN)) {
		g_bRunning = true;
	}
	else { return 1; }
	while (g_bRunning) {
		render();
	}
	SDL_Quit();
	return 0;
}
//include는 cpp 파일 단위로, lib는 그렇게 못함 
//동적 라이브러리는 링크할때 안들어가고, 정적 라이브러리는 들어감
// 정적은 어플에 붙어있고, 동적은 따로 메모리에 들어가있다. 동적은 메모리를 효율적으로 사용할수있다.
//동적은 컴파일 필요없이 수정이 용이하다.