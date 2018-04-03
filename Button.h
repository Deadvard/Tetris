#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>

class Button : public sf::Sprite
{
public:
	Button();
	virtual ~Button();

	//Tests if button is pressed
	bool isPressed(sf::Vector2f mouse);
	
	//Resize the button
	void resize(float pos, int width, int height);
	
	//Change the text of the button
	void setText(std::string textString);
	
	//Returns the text of the button
	std::string getText();

	//Returns the size of the button
	sf::Vector2f& getSize();

private:
	std::string text;
	sf::Vector2f size;

};


#endif // !BUTTON_H
