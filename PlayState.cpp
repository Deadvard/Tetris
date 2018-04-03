#include "PlayState.h"

PlayState::PlayState(sf::RenderWindow& window, InputHandler* ih, ResourceHandler* rh)
	: GameState(window,ih,rh), gm(window, ih)
{
	this->escPressed = false;

	this->size = window.getSize().y;

	grid.setTexture(getResource()->getGridTexture());
	grid.setOrigin(245, 0);

	text.setFont(getResource()->getFont());
	text.setString("Press Esc to go back to the Menu!");
	text.setPosition(0, 0);
}

PlayState::~PlayState()
{

}

void PlayState::update(sf::RenderWindow& window, sf::Time timeSinceLastUpdate)
{
	grid.setScale(sf::Vector2f(window.getSize().y / 1080.0, window.getSize().y / 1080.0));
	grid.setPosition(window.getSize().x / 2, 0);

	if (window.getSize().y != this->size)
	{
		gm.setGameOver(true);
		this->size = window.getSize().y;
		gm.update(window, timeSinceLastUpdate);
		gm.setGameOver(false);
		GameState::setState(1);
	}
	
	gm.update(window, timeSinceLastUpdate);
	
	if (getInput()->getPressingESC())
	{
		escPressed = true;
	}
	else
	{
		if(escPressed)
		{ 
		escPressed = false;
		window.setMouseCursorVisible(true);
		GameState::setState(0);
		}
	}

	if (gm.gameOver())
	{
		window.setMouseCursorVisible(true);
		getResource()->addNewResult(gm.getLastScore());
		gm.setGameOver(false);	
		GameState::setState(0);
	}

	text.setString("Press Esc to go back to the Menu! " + std::to_string(gm.getScore()));
}

void PlayState::draw(sf::RenderWindow& window)
{
	this->drawBg(window);
	window.draw(this->grid);
	window.draw(text);
	gm.draw(window);
}
