#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include <SFML/Graphics.hpp>

class InputHandler
{
public:
	InputHandler();
	virtual ~InputHandler();

	//Handles if key is pressed
	void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);

	//Handles if left mouse button is pressed
	void handlePlayerInput(sf::Mouse::Button button, bool isPressed);

	//Returns if the specific button is currently pressed
	bool getPressingLMB() const;	
	bool getPressingESC() const;		
	bool getSpeedButton() const;		
	bool getRotateButton() const;		
	bool getPressingLeft() const;		
	bool getPressingRight() const;

private:
	bool pressingLMB;
	bool pressingESC;
	bool speedButton;
	bool rotateButton;
	bool pressingLeft;
	bool pressingRight;
};

#endif // !INPUTHANDLER_H
