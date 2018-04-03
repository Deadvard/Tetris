#ifndef SQUAREBLOCK_H
#define SQUAREBLOCK_H

#include <SFML/Graphics.hpp>
#include "Square.h"

class SquareBlock
{
public:
	SquareBlock(Square* s1, Square* s2, Square* s3, Square* s4, bool** occupiedSpot);
	virtual ~SquareBlock();
	
	//Moves the current block of squares
	void move(bool down, bool left, bool right);
	
	//Tests if a block has found anything to collide with below it
	void testGridPos();
	
	//Returns the center square of the current block
	sf::Vector2i getCenter();
	
	//Rotetates the current block 90 degrees
	void rotate();
	
	//Returns if current block should be deleted
	bool shouldDelete();

private:
	//Set the state of all squares in the current block
	void setSquareSpotState(bool result);
	
	//Selects a random block
	void randomizeBlock();

	//Creates specifc block of the assigned squares
	void setShapeI();
	void setShapeL();
	void setShapeJ();
	void setShapeS();
	void setShapeZ();
	void setShapeT();
	void setShapeO();

	//Rotates specific block 90 degrees
	void RotateI();
	void RotateL();
	void RotateJ();
	void RotateS();
	void RotateZ();
	void RotateT();
	void RotateO();

	//Set the current color of all squares in this block
	void setColor(sf::Color color);

	int shape;
	int currentRotation;
	static const int size = 4;
	Square* squares[size];
	bool** occupiedSpot;
	bool deleteThis;

};

#endif // !SQUAREBLOCK_H
