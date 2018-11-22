#include "PlayState.h"
#include "Game.h"
const std::string PlayState::s_playID = "PLAY";
PlayState * PlayState::s_pInstance = 0;
void PlayState::update()
{
	SDL_RenderClear(TheGame::Instance()->getRenderer());
	SDL_RenderPresent(TheGame::Instance()->getRenderer());
	// nothing for now
}
void PlayState::render()
{
	// nothing for now
}
bool PlayState::onEnter()
{
	std::cout << "entering PlayState\n";
	return true;
}

bool PlayState::onExit()
{
	std::cout << "exiting PlayState\n";
	return true;
}