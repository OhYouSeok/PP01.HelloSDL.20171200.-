#include "GameState.h"
class GameStateMachine
{
public:
	void pushState(GameState *pState);
	void changeState(GameState* pState);
	void popState();
	void update();
	void render();
protected:
	std::vector<GameState*>m_gameStates;
private:
	GameState* m_currentState;
	GameState* m_prevState;
};