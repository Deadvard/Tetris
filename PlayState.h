#ifndef PLAYSTATE_H
#define PLAYSTATE_H

#include "GameState.h"
#include "GameMode.h"

class PlayState : public GameState
{
public:
	PlayState(sf::RenderWindow& window, InputHandler* ih, ResourceHandler* rh);
	virtual ~PlayState();
	
	//Updates current state
	void update(sf::RenderWindow& window, sf::Time timeSinceLastUpdate);
	
	//Draws current state
	void draw(sf::RenderWindow& window);

private:
	GameMode gm;

	bool escPressed;
	int size;

	sf::Text text;

	sf::Sprite grid;

};

#endif // !PLAYSTATE_H
