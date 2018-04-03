#include "Game.h"

Game::Game()
	: window(sf::VideoMode::getDesktopMode(), "EdvardTetris", sf::Style::Fullscreen)
{
	srand(static_cast<unsigned>(time(0)));
	
	this->ih = new InputHandler();
	this->rh = new ResourceHandler();

	this->currentState[0] = new MenuState(window, ih, rh);
	this->currentState[1] = new PlayState(window, ih, rh);
	this->currentState[2] = new OptionState(window, ih, rh);
	this->currentState[3] = new ScoreState(window, ih, rh);

	this->current = 0;
}


Game::~Game()
{
	delete ih;
	delete rh;
	
	for (int i = 0; i < states; i++)
	{
		delete currentState[i];
	}
}

void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	while (window.isOpen())
	{
		processEvents();
		timeSinceLastUpdate += clock.restart();
		
		while (timeSinceLastUpdate > timePerFrame)
		{
			current = GameState::getState();
			processEvents();
			currentState[current]->update(window, timeSinceLastUpdate);
			timeSinceLastUpdate -= timePerFrame;		
		}
		
		render();
	}
}

void Game::processEvents()
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::KeyPressed:
			ih->handlePlayerInput(event.key.code, true);
			break;
		case sf::Event::KeyReleased:
			ih->handlePlayerInput(event.key.code, false);
			break;
		case sf::Event::MouseButtonPressed:
			ih->handlePlayerInput(event.mouseButton.button, true);
			break;
		case sf::Event::MouseButtonReleased:
			ih->handlePlayerInput(event.mouseButton.button, false);		
			break;
		case sf::Event::Closed:
			rh->saveOnFile("Result");
			window.close();
			break;
		}		
	}
}

void Game::render()
{
	window.clear();
	currentState[current]->draw(window);
	window.display();
}

