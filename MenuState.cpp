#include "MenuState.h"

MenuState::MenuState(sf::RenderWindow& window, InputHandler* ih, ResourceHandler* rh)
	: GameState(window,ih,rh)
{
	this->startGame = false;
	this->startOptions = false;
	this->startScore = false;
	this->quitGame = false;

	startButton.setTexture(getResource()->getButtonTexture());
	optionButton.setTexture(getResource()->getButtonTexture());
	scoreButton.setTexture(getResource()->getButtonTexture());
	quitButton.setTexture(getResource()->getButtonTexture());

	text.setFont(getResource()->getFont());

	startButton.setText("Start");
	optionButton.setText("Options");
	scoreButton.setText("Score");
	quitButton.setText("Quit");
}

MenuState::~MenuState()
{

}

void MenuState::update(sf::RenderWindow& window, sf::Time timeSinceLastUpdate)
{		
	startButton.resize(2.f, window.getSize().x, window.getSize().y);
	optionButton.resize(3.5f, window.getSize().x, window.getSize().y);
	scoreButton.resize(5.f, window.getSize().x, window.getSize().y);
	quitButton.resize(6.5f, window.getSize().x, window.getSize().y);

	if (getInput()->getPressingLMB())
	{
		// get the current mouse position in the window
		sf::Vector2i pixelPos = sf::Mouse::getPosition(window);

		// convert it to world coordinates
		sf::Vector2f worldPos = window.mapPixelToCoords(pixelPos);

		this->isButtonPressed(worldPos);

	}
	else
	{
		this->result(window);
	}
}

void MenuState::draw(sf::RenderWindow& window)
{
	this->drawBg(window);
	
	text.setString("Tetris! (Buttons WASD)");
	text.setPosition(0, 0);
	window.draw(this->text);

	this->drawButton(window, startButton);
	this->drawButton(window, optionButton);
	this->drawButton(window, scoreButton);
	this->drawButton(window, quitButton);
}

void MenuState::drawButton(sf::RenderWindow& window, Button& button)
{
	window.draw(button);
	text.setString(button.getText());
	this->text.setPosition(button.getPosition());
	window.draw(this->text);
}

void MenuState::isButtonPressed(sf::Vector2f mouse)
{
	this->startGame = startButton.isPressed(mouse);
	this->startOptions = optionButton.isPressed(mouse);
	this->startScore = scoreButton.isPressed(mouse);
	this->quitGame = quitButton.isPressed(mouse);
}

void MenuState::result(sf::RenderWindow& window)
{
	if (startGame)
	{
		startGame = false;
		window.setMouseCursorVisible(false);
		GameState::setState(1);
	}

	else if (startOptions)
	{
		startOptions = false;
		GameState::setState(2);
	}

	else if (startScore)
	{
		startScore = false;
		GameState::setState(3);
	}
	else if (quitGame)
	{
		getResource()->saveOnFile("Result");
		window.close();
	}
}

