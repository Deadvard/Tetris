#include "SquareBlock.h"

SquareBlock::SquareBlock(Square* s1, Square* s2, Square* s3, Square* s4, bool** occupiedSpot)
{
	this->deleteThis = false;
	
	this->squares[0] = s1;
	this->squares[1] = s2;
	this->squares[2] = s3;
	this->squares[3] = s4;

	this->occupiedSpot = occupiedSpot;
	this->currentRotation = 0;

	this->randomizeBlock();
}

SquareBlock::~SquareBlock()
{

}

void SquareBlock::move(bool down, bool left, bool right)
{
	int x = 0;
	int y = 0;
	bool resultLeft = true;
	bool resultRight = true;
	
	if (down)
	{
		y += 1;
	}
	
	for (int i = 0; i < 4; i++)
	{
		if (this->squares[i]->testGridPos(-1,0))
		{
			resultLeft = false;
		}
		if (this->squares[i]->testGridPos(1, 0))
		{
			resultRight = false;
		}
	}
	
	if (left && resultLeft)
	{
		x += -1;
	}
	if (right && resultRight)
	{
		x += 1;
	}

	this->setSquareSpotState(false);
	this->testGridPos();
		
	this->squares[0]->moveSquare(x, y);
	this->squares[1]->moveSquare(x, y);
	this->squares[2]->moveSquare(x, y);
	this->squares[3]->moveSquare(x, y);

	this->setSquareSpotState(false);
	this->testGridPos();
}

void SquareBlock::testGridPos()
{
	if (this->squares[0]->getGridPos() ||
		this->squares[1]->getGridPos() ||
		this->squares[2]->getGridPos() ||
		this->squares[3]->getGridPos())
	{
		this->setSquareSpotState(true);
		this->deleteThis = true;
	}
}

sf::Vector2i SquareBlock::getCenter()
{
	sf::Vector2i temp;
	temp.x = this->squares[1]->position.x;
	temp.y = this->squares[1]->position.y;

	return temp;
}

void SquareBlock::rotate()
{
	switch (this->shape)
	{
	case 0: this->RotateI();
		break;
	case 1: this->RotateL();
		break;
	case 2: this->RotateJ();
		break;
	case 3: this->RotateS();
		break;
	case 4: this->RotateZ();
		break;
	case 5: this->RotateT();
		break;
	case 6: this->RotateO();
		break;
	}

	this->currentRotation++;
}

bool SquareBlock::shouldDelete()
{
	return deleteThis;
}

void SquareBlock::setSquareSpotState(bool result)
{
	this->occupiedSpot[squares[0]->position.y][squares[0]->position.x] = result;
	this->occupiedSpot[squares[1]->position.y][squares[1]->position.x] = result;
	this->occupiedSpot[squares[2]->position.y][squares[2]->position.x] = result;
	this->occupiedSpot[squares[3]->position.y][squares[3]->position.x] = result;
}

void SquareBlock::randomizeBlock()
{
	this->shape = rand() % 7;

	switch (this->shape)
	{
	case 0: this->setShapeI();
		break;
	case 1: this->setShapeL();
		break;
	case 2: this->setShapeJ();
		break;
	case 3: this->setShapeS();
		break;
	case 4: this->setShapeZ();
		break;
	case 5: this->setShapeT();
		break;
	case 6: this->setShapeO();
		break;
	}
}

void SquareBlock::setShapeI()
{	
	this->squares[0]->move(squares[0]->scaledVector(0.f, -1.f));
	this->squares[1]->move(squares[1]->scaledVector(0.f, 0.f));
	this->squares[2]->move(squares[2]->scaledVector(0.f, 1.f));
	this->squares[3]->move(squares[3]->scaledVector(0.f, 2.f));

	this->squares[0]->setGridPos(5,0);
	this->squares[1]->setGridPos(5,1);
	this->squares[2]->setGridPos(5,2);
	this->squares[3]->setGridPos(5,3);

	this->setColor(sf::Color::Cyan);
}

void SquareBlock::setShapeL()
{
	this->squares[0]->move(squares[0]->scaledVector(0.f, -1.f));
	this->squares[1]->move(squares[1]->scaledVector(0.f, 0.f));
	this->squares[2]->move(squares[2]->scaledVector(0.f, 1.f));
	this->squares[3]->move(squares[3]->scaledVector(1.f, 1.f));

	this->squares[0]->setGridPos(5, 0);
	this->squares[1]->setGridPos(5, 1);
	this->squares[2]->setGridPos(5, 2);
	this->squares[3]->setGridPos(6, 2);

	this->setColor(sf::Color::Black);
}

void SquareBlock::setShapeJ()
{
	this->squares[0]->move(squares[0]->scaledVector(0.f, -1.f));
	this->squares[1]->move(squares[1]->scaledVector(0.f, 0.f));
	this->squares[2]->move(squares[2]->scaledVector(0.f, 1.f));
	this->squares[3]->move(squares[3]->scaledVector(-1.f, 1.f));

	this->squares[0]->setGridPos(5, 0);
	this->squares[1]->setGridPos(5, 1);
	this->squares[2]->setGridPos(5, 2);
	this->squares[3]->setGridPos(4, 2);

	this->setColor(sf::Color::Blue);
}

void SquareBlock::setShapeS()
{
	this->squares[0]->move(squares[0]->scaledVector(0.f, -1.f));
	this->squares[1]->move(squares[1]->scaledVector(0.f, 0.f));
	this->squares[2]->move(squares[2]->scaledVector(1.f, 0.f));
	this->squares[3]->move(squares[3]->scaledVector(1.f, 1.f));

	this->squares[0]->setGridPos(5, 0);
	this->squares[1]->setGridPos(5, 1);
	this->squares[2]->setGridPos(6, 1);
	this->squares[3]->setGridPos(6, 2);

	this->setColor(sf::Color::Red);
}

void SquareBlock::setShapeZ()
{
	this->squares[0]->move(squares[0]->scaledVector(0.f, -1.f));
	this->squares[1]->move(squares[1]->scaledVector(0.f, 0.f));
	this->squares[2]->move(squares[2]->scaledVector(-1.f, 0.f));
	this->squares[3]->move(squares[3]->scaledVector(-1.f, 1.f));

	this->squares[0]->setGridPos(5, 0);
	this->squares[1]->setGridPos(5, 1);
	this->squares[2]->setGridPos(4, 1);
	this->squares[3]->setGridPos(4, 2);

	this->setColor(sf::Color::Green);
}

void SquareBlock::setShapeT()
{
	this->squares[0]->move(squares[0]->scaledVector(0.f, -1.f));
	this->squares[1]->move(squares[1]->scaledVector(0.f, 0.f));
	this->squares[2]->move(squares[2]->scaledVector(1.f, -1.f));
	this->squares[3]->move(squares[3]->scaledVector(-1.f, -1.f));

	this->squares[0]->setGridPos(5, 0);
	this->squares[1]->setGridPos(5, 1);
	this->squares[2]->setGridPos(6, 0);
	this->squares[3]->setGridPos(4, 0);

	this->setColor(sf::Color::Magenta);
}

void SquareBlock::setShapeO()
{
	this->squares[0]->move(squares[0]->scaledVector(0.f, -1.f));
	this->squares[1]->move(squares[1]->scaledVector(0.f, 0.f));
	this->squares[2]->move(squares[2]->scaledVector(1.f, -1.f));
	this->squares[3]->move(squares[3]->scaledVector(1.f, 0.f));

	this->squares[0]->setGridPos(5, 0);
	this->squares[1]->setGridPos(5, 1);
	this->squares[2]->setGridPos(6, 0);
	this->squares[3]->setGridPos(6, 1);

	this->setColor(sf::Color::Yellow);
}

//Rotation

void SquareBlock::RotateI()
{
	if (this->currentRotation % 4 == 0)
	{
		this->squares[0]->moveSquare(1, 1);
		this->squares[2]->moveSquare(-1, -1);
		this->squares[3]->moveSquare(-2, -2);
	}
	else if (this->currentRotation % 4 == 1)
	{
		this->squares[0]->moveSquare(-1, 1);
		this->squares[2]->moveSquare(1, -1);
		this->squares[3]->moveSquare(2, -2);
	}	
	else if (this->currentRotation % 4 == 2)
	{
		this->squares[0]->moveSquare(-1, -1);
		this->squares[2]->moveSquare(1, 1);
		this->squares[3]->moveSquare(2, 2);
	}
	else if (this->currentRotation % 4 == 3)
	{
		this->squares[0]->moveSquare(1, -1);
		this->squares[2]->moveSquare(-1, 1);
		this->squares[3]->moveSquare(-2, 2);
	}
}

void SquareBlock::RotateL()
{
	if (this->currentRotation % 4 == 0)
	{
		this->squares[0]->moveSquare(1, 1);
		this->squares[2]->moveSquare(-1, -1);
		this->squares[3]->moveSquare(-2, 0);
	}
	else if (this->currentRotation % 4 == 1)
	{
		this->squares[0]->moveSquare(-1, 1);
		this->squares[2]->moveSquare(1, -1);
		this->squares[3]->moveSquare(0, -2);
	}
	else if (this->currentRotation % 4 == 2)
	{
		this->squares[0]->moveSquare(-1, -1);
		this->squares[2]->moveSquare(1, 1);
		this->squares[3]->moveSquare(2, 0);
	}
	else if (this->currentRotation % 4 == 3)
	{
		this->squares[0]->moveSquare(1, -1);
		this->squares[2]->moveSquare(-1, 1);
		this->squares[3]->moveSquare(0, 2);
	}
}

void SquareBlock::RotateJ()
{
	if (this->currentRotation % 4 == 0)
	{
		this->squares[0]->moveSquare(1, 1);
		this->squares[2]->moveSquare(-1, -1);
		this->squares[3]->moveSquare(0, -2);
	}
	else if (this->currentRotation % 4 == 1)
	{
		this->squares[0]->moveSquare(-1, 1);
		this->squares[2]->moveSquare(1, -1);
		this->squares[3]->moveSquare(2, 0);
	}
	else if (this->currentRotation % 4 == 2)
	{
		this->squares[0]->moveSquare(-1, -1);
		this->squares[2]->moveSquare(1, 1);
		this->squares[3]->moveSquare(0, 2);
	}
	else if (this->currentRotation % 4 == 3)
	{
		this->squares[0]->moveSquare(1, -1);
		this->squares[2]->moveSquare(-1, 1);
		this->squares[3]->moveSquare(-2, 0);
	}
}

void SquareBlock::RotateS()
{
	if (this->currentRotation % 4 == 0)
	{
		this->squares[0]->moveSquare(1, 1);
		this->squares[2]->moveSquare(-1, 1);
		this->squares[3]->moveSquare(-2, 0);
	}
	else if (this->currentRotation % 4 == 1)
	{
		this->squares[0]->moveSquare(-1, 1);
		this->squares[2]->moveSquare(-1, -1);
		this->squares[3]->moveSquare(0, -2);
	}
	else if (this->currentRotation % 4 == 2)
	{
		this->squares[0]->moveSquare(-1, -1);
		this->squares[2]->moveSquare(1, -1);
		this->squares[3]->moveSquare(2, 0);
	}
	else if (this->currentRotation % 4 == 3)
	{
		this->squares[0]->moveSquare(1, -1);
		this->squares[2]->moveSquare(1, 1);
		this->squares[3]->moveSquare(0, 2);
	}
}

void SquareBlock::RotateZ()
{
	if (this->currentRotation % 4 == 0)
	{
		this->squares[0]->moveSquare(1, 1);
		this->squares[2]->moveSquare(1, -1);
		this->squares[3]->moveSquare(0, -2);
	}
	else if (this->currentRotation % 4 == 1)
	{
		this->squares[0]->moveSquare(-1, 1);
		this->squares[2]->moveSquare(1, 1);
		this->squares[3]->moveSquare(2, 0);
	}
	else if (this->currentRotation % 4 == 2)
	{
		this->squares[0]->moveSquare(-1, -1);
		this->squares[2]->moveSquare(-1, 1);
		this->squares[3]->moveSquare(0, 2);
	}
	else if (this->currentRotation % 4 == 3)
	{
		this->squares[0]->moveSquare(1, -1);
		this->squares[2]->moveSquare(-1, -1);
		this->squares[3]->moveSquare(-2, 0);
	}
}

void SquareBlock::RotateT()
{
	if (this->currentRotation % 4 == 0)
	{
		this->squares[0]->moveSquare(1, 1);
		this->squares[2]->moveSquare(0, 2);
		this->squares[3]->moveSquare(2, 0);
	}
	else if (this->currentRotation % 4 == 1)
	{
		this->squares[0]->moveSquare(-1, 1);
		this->squares[2]->moveSquare(-2, 0);
		this->squares[3]->moveSquare(0, 2);
	}
	else if (this->currentRotation % 4 == 2)
	{
		this->squares[0]->moveSquare(-1, -1);
		this->squares[2]->moveSquare(0, -2);
		this->squares[3]->moveSquare(-2, 0);
	}
	else if (this->currentRotation % 4 == 3)
	{
		this->squares[0]->moveSquare(1, -1);
		this->squares[2]->moveSquare(2, 0);
		this->squares[3]->moveSquare(0, -2);
	}
}

void SquareBlock::RotateO()//(5, 0)(5, 1)(6, 0)(6, 1);
{
	if (this->currentRotation % 4 == 0)
	{
		this->squares[0]->moveSquare(1, 1);
		this->squares[2]->moveSquare(0, 2);
		this->squares[3]->moveSquare(-1, 1);
	}
	else if (this->currentRotation % 4 == 1)
	{
		this->squares[0]->moveSquare(-1, 1);
		this->squares[2]->moveSquare(-2, 0);
		this->squares[3]->moveSquare(-1, -1);
	}
	else if (this->currentRotation % 4 == 2)
	{
		this->squares[0]->moveSquare(-1, -1);
		this->squares[2]->moveSquare(0, -2);
		this->squares[3]->moveSquare(1, -1);
	}
	else if (this->currentRotation % 4 == 3)
	{
		this->squares[0]->moveSquare(1, -1);
		this->squares[2]->moveSquare(2, 0);
		this->squares[3]->moveSquare(1, 1);
	}
}

void SquareBlock::setColor(sf::Color color)
{
	this->squares[0]->setFillColor(color);
	this->squares[1]->setFillColor(color);
	this->squares[2]->setFillColor(color);
	this->squares[3]->setFillColor(color);
}
