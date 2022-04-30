#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

class Button : public sf::Drawable{
public:
	std::string text;
private:
	double x;
	double y;

	sf::Text txt;
	sf::Font font;
	double width;
	double height;
	sf::RectangleShape box;
	bool isActivated;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

public:
	Button(double x = 0, double y = 0, double width = 150, double height = 30, std::string text = "Button");
	void deactivate();
	void activate();

	bool select(sf::Vector2i _mouse);
};