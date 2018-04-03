#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <SFML/Graphics.hpp>
#include "InputHandler.h"
#include "ResourceHandler.h"

class GameState
{
public:
	GameState(sf::RenderWindow& window, InputHandler* ih, ResourceHandler* rh);
	virtual ~GameState();
	virtual void update(sf::RenderWindow& window, sf::Time timeSinceLastUpdate) = 0;
	virtual void draw(sf::RenderWindow& window) = 0;

	//Used to draw the background
	void drawBg(sf::RenderWindow& window);

	//Returns the current state
	static int getState();

	//Changes the current state
	static void setState(int newState);
	
	//Returns a pointer to the input handler
	InputHandler* getInput();

	//Returns a pointer to the resource handler
	ResourceHandler* getResource();

private:

	InputHandler* ih;
	ResourceHandler* rh;
	
	sf::Sprite bg;

	static int currentState;
		
};

#endif // !GAMESTATE_H


