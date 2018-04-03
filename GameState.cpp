#include "GameState.h"

int GameState::currentState = 0;

GameState::GameState(sf::RenderWindow& window, InputHandler* ih, ResourceHandler* rh)
{
	this->ih = ih;
	this->rh = rh;
	
	bg.setTexture(rh->getBgTexture());
}

GameState::~GameState()
{

}

void GameState::drawBg(sf::RenderWindow& window)
{
	window.draw(this->bg);
}

int GameState::getState()
{
	return GameState::currentState;
}

void GameState::setState(int newState)
{
	GameState::currentState = newState;
}

InputHandler* GameState::getInput()
{
	return this->ih;
}

ResourceHandler* GameState::getResource()
{
	return this->rh;
}
