#ifndef GAMEMODE_H
#define GAMEMODE_H

#include "SquareBlock.h"
#include "Square.h"
#include "InputHandler.h"
#include <SFML/Graphics.hpp>

class GameMode
{
public:
	GameMode(sf::RenderWindow& window, InputHandler* ih);
	virtual ~GameMode();
	
	//Updates the game logic
	void update(sf::RenderWindow& window, sf::Time timeSinceLastUpdate);	

	//Draws the game
	void draw(sf::RenderWindow& window);
	
	//Returns the score of current session
	int getScore() const;
	
	//Returns the score of last session
	int getLastScore() const;
	
	//Returns if game is over
	bool gameOver() const;
	
	//Set state of game to done
	void setGameOver(bool result);

private:
	//Tests if full row is occupied
	bool rowOccupied(int x, int y);	
	
	//Destroys the selected row of squares
	void destroySquares(int row);

	//Test if square block reached bottom
	void testSquareBlock();
	
	//Create new squares for new block
	void createSquares(int index);
	
	//Deletes the current block (not squares)
	void deleteSquareBlock();
	
	//Expands the array of squares
	void expand();
	
	//Resets game
	void reset(sf::RenderWindow& window);
	
	//Initialize all variables
	void initialize(sf::RenderWindow& window);
	
	//Free all dynamic memory of the game
	void freeMemory();

	int squareSizeX;
	int squareSizeY;
	int score;
	int moves;
	int lastRoundScore;
	
	int squareIndex;

	const static int x = 10;
	const static int y = 25;

	sf::Time timeSinceLastTick;

	bool** occupiedSpot;
	bool isGameOver;

	InputHandler* ih;

	Square*** sq;
	SquareBlock* squareBlock;
};

#endif // !GAMEMODE_H
