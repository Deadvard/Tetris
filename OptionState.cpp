#include "OptionState.h"

OptionState::OptionState(sf::RenderWindow& window, InputHandler* ih, ResourceHandler* rh)
	: GameState(window,ih,rh)
{
	this->changeFullscreen = false;
	this->changeResolution = false;
	this->changeVolume = false;	
	this->startMenu = false;

	this->fullscreenOn = true;

	this->modes = sf::VideoMode::getFullscreenModes();

	this->index = 0;

	this->currentRes = "Resolution: " + std::to_string(window.getSize().x) + "x" + std::to_string(window.getSize().y);
	this->screenMode = "Fullscreen: ON";

	fullscreenButton.setTexture(getResource()->getButtonTexture());
	resolutionButton.setTexture(getResource()->getButtonTexture());
	volumeButton.setTexture(getResource()->getButtonTexture());
	backButton.setTexture(getResource()->getButtonTexture());

	volumeButton.setText("Mute");
	backButton.setText("Back");

	text.setFont(getResource()->getFont());
	text.setString("Options!");
	text.setPosition(0, 0);
}

OptionState::~OptionState()
{

}

void OptionState::update(sf::RenderWindow& window, sf::Time timeSinceLastUpdate)
{
	fullscreenButton.resize(2.f, window.getSize().x, window.getSize().y);
	resolutionButton.resize(3.5f, window.getSize().x, window.getSize().y);
	volumeButton.resize(5.f, window.getSize().x, window.getSize().y);
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

void OptionState::draw(sf::RenderWindow& window)
{
	this->drawBg(window);

	text.setString("Options!");
	text.setPosition(0, 0);
	window.draw(this->text);

	fullscreenButton.setText(this->screenMode);
	resolutionButton.setText(this->currentRes);

	this->drawButton(window, fullscreenButton);
	this->drawButton(window, resolutionButton);
	this->drawButton(window, volumeButton);
	this->drawButton(window, backButton);

	
}

void OptionState::drawButton(sf::RenderWindow& window, Button& button)
{
	window.draw(button);
	text.setString(button.getText());
	this->text.setPosition(button.getPosition());
	window.draw(this->text);
}

void OptionState::isButtonPressed(sf::Vector2f mouse)
{
	this->changeFullscreen = fullscreenButton.isPressed(mouse);
	this->changeResolution = resolutionButton.isPressed(mouse);
	this->changeVolume = volumeButton.isPressed(mouse);
	this->startMenu = backButton.isPressed(mouse);
}

void OptionState::result(sf::RenderWindow& window)
{
	if (changeFullscreen)
	{
		changeFullscreen = false;

		if (!fullscreenOn)
		{
			fullscreenOn = true;
			setScreenMode(window, fullscreenOn);
		}

		else
		{
			fullscreenOn = false;
			setScreenMode(window, fullscreenOn);
		}

	}

	else if (changeResolution)
	{
		changeResolution = false;
		if (index < modes.size() - 1)
			index++;
		else
			index = 0;

		currentRes = "Resolution: " + std::to_string(modes[index].width) + "x" + std::to_string(modes[index].height);
	}

	else if (changeVolume)
	{
		changeVolume = false;
		getResource()->setMusicState();
	}
	else if (startMenu)
	{
		startMenu = false;
		setScreenMode(window, fullscreenOn);
		GameState::setState(0);
	}
}

void OptionState::setScreenMode(sf::RenderWindow& window, bool mode)
{
	if (mode)
	{
		window.create(modes[index], "EdvardTetris", sf::Style::Fullscreen);
		this->screenMode = "Fullscreen: ON";
	}

	else
	{
		window.create(modes[index], "EdvardTetris", sf::Style::Default);
		this->screenMode = "Fullscreen: OFF";
	}

}
