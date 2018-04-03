#include "GameMode.h"

GameMode::GameMode(sf::RenderWindow& window, InputHandler* ih)
{
	this->ih = ih;
	this->isGameOver = false;
	this->score = 0;
	this->initialize(window);
}

GameMode::~GameMode()
{
	this->freeMemory();
}

void GameMode::update(sf::RenderWindow& window, sf::Time timeSinceLastUpdate)
{
	timeSinceLastTick += timeSinceLastUpdate;
	squareSizeX = window.getSize().x;
	squareSizeY = window.getSize().y;

	if (timeSinceLastTick > sf::seconds(.5f))
	{
		if (ih->getRotateButton()
			&& squareBlock->getCenter().x <= 7
			&& squareBlock->getCenter().x >= 2)
		{
			squareBlock->rotate();
		}
			
		squareBlock->move(ih->getSpeedButton(), ih->getPressingLeft(), ih->getPressingRight());

		this->testSquareBlock();

		if (moves == 0)
			squareBlock->move(true, false, false);

		this->testSquareBlock();

		if (moves > 0)
		{
			for (int i = 0; i < squareIndex; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					if (sq[i][j] != nullptr)
					{
						sq[i][j]->setGridState(false);
					}
				}
			}
			
			for (int i = 0; i < squareIndex; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					if (sq[i][j] != nullptr)
					{
						sq[i][j]->moveSquare(0, 1.f);
					}
				}
			}
			moves--;
		}
		timeSinceLastTick = sf::Time::Zero;
	}

	this->testSquareBlock();

	if (isGameOver)
	{
		this->reset(window);
	}
}

void GameMode::draw(sf::RenderWindow& window)
{	
	for (int i = 0; i < squareIndex; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (sq[i][j] != nullptr)
			{
				window.draw(*sq[i][j]);
			}
		}
	}
}

int GameMode::getScore() const
{
	return this->score;
}

int GameMode::getLastScore() const
{
	return this->lastRoundScore;
}

bool GameMode::gameOver() const
{
	return this->isGameOver;
}

void GameMode::setGameOver(bool result)
{
	this->isGameOver = result;
}

//Private

bool GameMode::rowOccupied(int x, int y)
{
	bool result = false;

	if (x <= 0)
	{
		result = true;
	}
	else if (rowOccupied(x - 1, y) && occupiedSpot[y][x])
	{
		result = true;
	}
	else
	{
		result = false;
	}

	return result;
}

void GameMode::destroySquares(int row)
{
	for (int i = 0; i < squareIndex; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (sq[i][j] != nullptr && sq[i][j]->position.y == row)
			{
				this->occupiedSpot[sq[i][j]->position.y][sq[i][j]->position.x] = false;
				delete sq[i][j];
				sq[i][j] = nullptr;
			}
		}
	}
}

void GameMode::testSquareBlock()
{
	if (squareBlock->shouldDelete())
	{
		for (int i = 0; i < x; i++)
		{
			if (this->occupiedSpot[0][i])
			{
				this->isGameOver = true;
			}
		}

		this->deleteSquareBlock();

		for (int i = y - 2; i >= 0; i--)
		{
			if (rowOccupied(x, i))
			{
				destroySquares(i);
				this->score++;
				this->moves++;
			}
		}
	}
}

void GameMode::createSquares(int index)
{
	if (index >= 10)
	{
		this->expand();
	}
	
	sq[index] = new Square*[4];
	
	sq[index][0] = new Square(occupiedSpot, squareSizeX, squareSizeY);
	sq[index][1] = new Square(occupiedSpot, squareSizeX, squareSizeY);
	sq[index][2] = new Square(occupiedSpot, squareSizeX, squareSizeY);
	sq[index][3] = new Square(occupiedSpot, squareSizeX, squareSizeY);

	squareBlock = new SquareBlock(sq[index][0], sq[index][1], sq[index][2], sq[index][3], occupiedSpot);
}

void GameMode::deleteSquareBlock()
{
	delete squareBlock;
	this->createSquares(squareIndex++);
}

void GameMode::expand()
{
	Square*** temp;
	temp = new Square**[squareIndex + 10];

	for (int i = 0; i < squareIndex; i++)
	{
		temp[i] = sq[i];
		
	}
	delete[] sq;
	sq = temp;
}

void GameMode::reset(sf::RenderWindow& window)
{
	this->freeMemory();

	this->initialize(window);
}

void GameMode::initialize(sf::RenderWindow& window)
{
	this->squareIndex = 0;
	this->lastRoundScore = this->score;
	this->score = 0;
	this->moves = 0;
	squareSizeX = window.getSize().x;
	squareSizeY = window.getSize().y;

	sq = new Square**[10];

	occupiedSpot = new bool*[y];

	for (int i = 0; i < y; i++)
	{
		occupiedSpot[i] = new bool[x];

		for (int j = 0; j < x; j++)
		{
			if (i == y - 1)
			{
				occupiedSpot[i][j] = true;
			}
			else
			{
				occupiedSpot[i][j] = false;
			}
		}
	}

	createSquares(squareIndex++);
}

void GameMode::freeMemory()
{
	for (int i = 0; i < squareIndex; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			delete sq[i][j];
		}
		delete[] sq[i];
	}
	delete[] sq;

	delete squareBlock;

	for (int i = 0; i < y; i++)
	{
		delete[] occupiedSpot[i];
	}
	delete[] occupiedSpot;
}

