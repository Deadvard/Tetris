#include "InputHandler.h"

InputHandler::InputHandler()
{
	pressingLMB = false;
	pressingESC = false;
	speedButton = false;
	rotateButton = false;
	pressingLeft = false;
	pressingRight = false;
}

InputHandler::~InputHandler()
{

}

void InputHandler::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{
	if (key == sf::Keyboard::S)
		speedButton = isPressed;
	else if (key == sf::Keyboard::W)
		rotateButton = isPressed;
	else if (key == sf::Keyboard::A)
		pressingLeft = isPressed;
	else if (key == sf::Keyboard::D)
		pressingRight = isPressed;
	else if (key == sf::Keyboard::Escape)
		pressingESC = isPressed;
}

void InputHandler::handlePlayerInput(sf::Mouse::Button button, bool isPressed)
{
	if (button == sf::Mouse::Left)
		pressingLMB = isPressed;
}

bool InputHandler::getPressingLMB() const
{
	return this->pressingLMB;
}

bool InputHandler::getPressingESC() const
{
	return this->pressingESC;
}

bool InputHandler::getSpeedButton() const
{
	return this->speedButton;
}

bool InputHandler::getRotateButton() const
{
	return this->rotateButton;
}

bool InputHandler::getPressingLeft() const
{
	return this->pressingLeft;
}

bool InputHandler::getPressingRight() const
{
	return this->pressingRight;
}