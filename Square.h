#ifndef SQUARE_H
#define SQUARE_H

#include <SFML/Graphics.hpp>

class Square : public sf::RectangleShape
{
public:
	Square(bool** occupiedSpot, int sizeX, int sizeY);
	~Square();

	//Returns a vector that is scaled to the current resolution
	sf::Vector2f scaledVector(float x, float y);
	
	//Tests if square is allowed to move to the new position in the grid and then move
	void moveSquare(int x, int y);

	//Sets the state of the current grid position of the square
	void setGridState(bool result);

	//Sets the position of the square in the grid
	void setGridPos(int x, int y);

	//Set square position in grid relative to current position
	void setGridRel(int x, int y);

	//Returns if position below current is occupied
	bool getGridPos();

	//Returns result of specific grid position relative to current
	bool testGridPos(int x, int y);

	sf::Vector2i position;

private:
	float width;
	float height;

	bool** occupiedSpot;
	
};

#endif // !SQUARE_H
