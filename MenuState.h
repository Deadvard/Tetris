#ifndef MENUSTATE_H
#define MENUSTATE_H

#include "GameState.h"
#include "Button.h"

class MenuState : public GameState
{
public:
	MenuState(sf::RenderWindow& window, InputHandler* ih, ResourceHandler* rh);
	virtual ~MenuState();
	
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

	bool startGame;
	bool startOptions;
	bool startScore;
	bool quitGame;

	sf::Text text;

	Button startButton;
	Button optionButton;
	Button scoreButton;
	Button quitButton;
};

#endif // !MENUSTATE_H