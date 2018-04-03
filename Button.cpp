#include "Button.h"

Button::Button()
	: sf::Sprite()
{
	this->size.x = 640;
	this->size.y = 90;
}

Button::~Button()
{

}

bool Button::isPressed(sf::Vector2f mouse)
{
	sf::Rect<float> rect(this->getPosition(), sf::Vector2f(getSize().x * getScale().x, getSize().y * getScale().y));
	return rect.contains(mouse);
}

void Button::resize(float pos, int width, int height)
{
	float x = (width/2) / size.x;
	float y = (height/8) / size.y;
	
	this->setScale(sf::Vector2f(x, y));
	this->setPosition(sf::Vector2f((width / 8.f) * 2, (height / 8.f) * pos));
}

void Button::setText(std::string textString)
{
	this->text = textString;
}

std::string Button::getText()
{
	return this->text;
}

sf::Vector2f& Button::getSize()
{
	return this->size;
}