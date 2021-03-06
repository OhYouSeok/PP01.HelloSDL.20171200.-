#pragma once
#include "GameState.h"
#include "SDLGameObject.h"

class PlayState : public GameState
{
public:
	bool checkCollision(SDLGameObject* p1, SDLGameObject* p2);
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	void handleEvents();
	virtual std::string getStateID() const { return s_playID; }
	static PlayState * Instance() {
		if (s_pInstance == 0) {
			s_pInstance = new PlayState();
		}
		return s_pInstance;
	}
private:
	static const std::string s_playID;
	SDL_Renderer *renderer;
	static PlayState* s_pInstance;
	std::vector<GameObject*> m_gameObjects;
};
typedef PlayState PlayState;