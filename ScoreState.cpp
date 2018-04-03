#include "ScoreState.h"

ScoreState::ScoreState(sf::RenderWindow& window, InputHandler* ih, ResourceHandler* rh)
	: GameState(window, ih, rh)
{
	this->startMenu = false;
	
	backButton.setTexture(getResource()->getButtonTexture());

	backButton.setText("Back");

	text.setFont(getResource()->getFont());
	text.setString("Score Board!");
	text.setPosition(0, 0);

	getResource()->readFromFile("Result");
}

ScoreState::~ScoreState()
{

}

void ScoreState::update(sf::RenderWindow& window, sf::Time timeSinceLastUpdate)
{

	backButton.resize(6.5f, window.getSize().x, window.getSize().y);

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
		result(window);
	}
}

void ScoreState::draw(sf::RenderWindow& window)
{
	this->drawBg(window);

	text.setString("Score Board!");
	text.setPosition(0, 0);
	window.draw(this->text);

	for (int i = 0; i < getResource()->length; i++)
	{
		text.setString(std::to_string(getResource()->scoreBoard[i]));
		text.setPosition(0, (i+1)*30);
		window.draw(this->text);
	}

	this->drawButton(window, backButton);
}

//Private

void ScoreState::drawButton(sf::RenderWindow& window, Button& button)
{
	window.draw(button);
	text.setString(button.getText());
	this->text.setPosition(button.getPosition());
	window.draw(this->text);
}

void ScoreState::isButtonPressed(sf::Vector2f mouse)
{
	this->startMenu = backButton.isPressed(mouse);
}

void ScoreState::result(sf::RenderWindow& window)
{	
	if (this->startMenu)
	{
		this->startMenu = false;
		GameState::setState(0);
	}
}
