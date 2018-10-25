#pragma once
#include "TextureManager.h"
#include "Player.h"
#include "GameObject.h"
#include "Enemy.h"
#include "Monster.h"
#include <vector>

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

	std::vector<GameObject*> m_gameObjects;

	GameObject* m_go;
	GameObject* m_player;
	GameObject* m_enemy;
	GameObject* m_monster;
	GameObject* m_monster2;

};
