#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "InputHandler.h"
#include "ResourceHandler.h"
#include "GameState.h"
#include "MenuState.h"
#include "PlayState.h"
#include "OptionState.h"
#include "ScoreState.h"
#include <ctime>

class Game
{
public:
	Game();
	virtual ~Game();
	
	//Starts the game
	void run();
	
	//Processes the events
	void processEvents();
	
	//Displays the window and graphics
	void render();

private:
	const static int states = 4;
	sf::RenderWindow window;
	InputHandler* ih;
	ResourceHandler* rh;
	GameState* currentState[states];
	int current;
	const sf::Time timePerFrame = sf::seconds(1.f / 60.f);
};

#endif // !GAME_H