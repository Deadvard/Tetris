#include "ResourceHandler.h"

ResourceHandler::ResourceHandler()
{
	if (!this->font.loadFromFile("Bubblegum.ttf"))
		throw std::runtime_error("Unable to load the font file");

	if (!this->bgTexture.loadFromFile("bg.png"))
		throw std::runtime_error("Unable to load the texture file");

	if (!this->grid.loadFromFile("grid.png"))
		throw std::runtime_error("Unable to load the texture file");

	if (!this->buttonTexture.loadFromFile("Button.png"))
		throw std::runtime_error("Unable to load the texture file");

	if (!gameMusic.openFromFile("Tetris.wav"))
		throw std::runtime_error("Unable to load the music file");

	gameMusic.setLoop(true);
	gameMusic.play();	
}

ResourceHandler::~ResourceHandler()
{

}

sf::Font& ResourceHandler::getFont()
{
	return this->font;
}

sf::Texture& ResourceHandler::getBgTexture()
{
	return this->bgTexture;
}

sf::Texture& ResourceHandler::getGridTexture()
{
	return this->grid;
}

sf::Texture& ResourceHandler::getButtonTexture()
{
	return this->buttonTexture;
}

void ResourceHandler::setMusicState()
{
	if (gameMusic.getStatus() == gameMusic.Paused)
		gameMusic.play();

	else
		gameMusic.pause();
}

void ResourceHandler::addNewResult(int result)
{
	int index = -1;
	
	for (int i = 0; i < this->length && index == -1; i++)
	{
		if (result > scoreBoard[i])
		{
			index = i;
		}
	}
	for (int i = this->length-2; i > index; i--)
	{
		scoreBoard[i] = scoreBoard[i - 1];
	}
	
	if (index != -1)
	{
		scoreBoard[index] = result;
	}
}
	

void ResourceHandler::saveOnFile(std::string filename) const
{
	std::ofstream outData;

	filename = filename + ".dat";

	outData.open(filename.data(), std::ios::out | std::ios::binary);

	if (!outData.fail())
	{
		for (int i = 0; i < this->length; i++)
		{
			outData.write((char*)(&scoreBoard[i]), sizeof(scoreBoard[i]));
		}
	}
	outData.close();
}

void ResourceHandler::readFromFile(std::string filename)
{
	std::ifstream inData;

	filename = filename + ".dat";

	inData.open(filename.data(), std::ios_base::in | std::ios_base::binary);

	if (!inData.fail())
	{
		for (int i = 0; i < this->length; i++)
		{
			inData.read((char*)(&scoreBoard[i]), sizeof(scoreBoard[i]));
		}
	}
	inData.close();
}