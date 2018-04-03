#include "Square.h"

Square::Square(bool** occupiedSpot, int sizeX, int sizeY)
{
	width = sizeY / 22.0;
	height = sizeY / 22.0;
	this->occupiedSpot = occupiedSpot;

	this->setFillColor(sf::Color::Blue);
	this->setSize(sf::Vector2f(width, height));
	this->setPosition(sizeX/2, -height);
}

Square::~Square()
{

}

sf::Vector2f Square::scaledVector(float x, float y)
{
	return sf::Vector2f(x*width, y*height);
}

void Square::moveSquare(int x, int y)
{
	if(!occupiedSpot[this->position.y + y][this->position.x + x])
	{		
		this->move(sf::Vector2f(x*width, y*height));
		this->position.x += x;
		this->position.y += y;			
	}
	occupiedSpot[this->position.y][this->position.x] = true;
}

void Square::setGridState(bool result)
{
	occupiedSpot[this->position.y][this->position.x] = result;
}

void Square::setGridPos(int x, int y)
{
	this->position.x = x;
	this->position.y = y;
}

void Square::setGridRel(int x, int y)
{
	this->position.x += x;
	this->position.y += y;
}

bool Square::getGridPos()
{
	return occupiedSpot[this->position.y + 1][this->position.x];
}

bool Square::testGridPos(int x, int y)
{
	return occupiedSpot[this->position.y + y][this->position.x + x];
}