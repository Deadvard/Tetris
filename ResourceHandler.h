#ifndef RESOURCEHANDLER_H
#define RESOURCEHANDLER_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <fstream>

class ResourceHandler
{
public:
	ResourceHandler();
	virtual ~ResourceHandler();

	//Returns the font of the game
	sf::Font& getFont();

	//Returns the background texture of the game
	sf::Texture& getBgTexture();

	//Returns the texture used for the grid of the game
	sf::Texture& getGridTexture();

	//Returns the texture used for the menu buttons
	sf::Texture& getButtonTexture();

	//Turn music on or off
	void setMusicState();

	//Add new result to scoreboard
	void addNewResult(int result);

	//Save scoreboard on file
	void saveOnFile(std::string filename) const;

	//Load scoreboard from file
	void readFromFile(std::string filename);

	const static int length = 10;
	int scoreBoard[length];

private:	

	sf::Font font;
	sf::Texture bgTexture;
	sf::Texture grid;
	sf::Texture buttonTexture;
	sf::Music gameMusic;
};

#endif // !RESOURCEHANDLER_H
