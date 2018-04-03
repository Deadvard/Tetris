#ifndef SCORESTATE_H
#define SCORESTATE_H

#include "GameState.h"
#include "Button.h"

class ScoreState : public GameState
{
public:
	ScoreState(sf::RenderWindow& window, InputHandler* ih, ResourceHandler* rh);
	virtual ~ScoreState();
	
	//Updates current state
	void update(sf::RenderWindow& window, sf::Time timeSinceLastUpdate);
	
	//Draws current state
	void draw(sf::RenderWindow& window);

private:
	//Draws a specific button
	void drawButton(sf::RenderWindow& window, Button& button);
	
	//Tests if a button is pressed
	void isButtonPressed(sf::Vector2f mouse);

	//Uses the result of the button press to change gamestate if button was pressed
	void result(sf::RenderWindow& window);

	bool startMenu;

	sf::Text text;

	Button backButton;
};

#endif // !SCORESTATE_H

