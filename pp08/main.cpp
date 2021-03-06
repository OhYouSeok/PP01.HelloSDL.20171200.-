#include "game.h"
#include "SDL.h"

Game * g_game = 0;

int main(int argc, char* argv[]) {
	g_game = new Game();
	g_game->init("PP08", 100, 100, 1024, 720, false);
	while (g_game->running()) {
		g_game->handleEvents();
		g_game->update();
		g_game->render();
	}
	g_game->clean();
	return 0;
}