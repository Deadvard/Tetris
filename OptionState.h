#ifndef OPTIONSTATE_H
#define OPTIONSTATE_H

#include "GameState.h"
#include "Button.h"


class OptionState : public GameState
{
public:
	OptionState(sf::RenderWindow& window, InputHandler* ih, ResourceHandler* rh);
	virtual ~OptionState();
	
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
	
	//Changes fullscreen mode on and off
	void setScreenMode(sf::RenderWindow& window, bool mode);

	bool fullscreenOn;
	std::string screenMode;
	std::string currentRes;

	int resX;
	int resY;
	unsigned int index;

	std::vector<sf::VideoMode> modes;

	bool changeFullscreen;
	bool changeResolution;
	bool changeVolume;
	bool startMenu;


	sf::Text text;

	Button fullscreenButton;
	Button resolutionButton;
	Button volumeButton;
	Button backButton;
};

#endif // !OPTIONSTATE_H
