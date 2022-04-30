#include "Button.h"

Button::Button(double x, double y, double width, double height, std::string text) :
	x(x),
	y(y),
	width(width),
	height(height),
	text(text),
	isActivated(true)
{
	bool isf = font.loadFromFile("../SlotMachine/fonts/Bighaustitul extrabold.ttf");

	txt.setFont(font);
	txt.setCharacterSize(35);
	txt.setFillColor(sf::Color::White);
	txt.setPosition(x + width / 4,y);
	txt.setString(text);

	box.setSize(sf::Vector2f(width, height));
	box.setPosition(x, y);
	box.setFillColor(sf::Color(133, 133, 133));
	box.setOutlineThickness(2);
	box.setOutlineColor(sf::Color(66, 66, 66));
}

bool Button::select(sf::Vector2i mouse)
{
	if (!isActivated) { return false; }
	if ((mouse.x > x && mouse.x < x + width) && (mouse.y > y && mouse.y < y + height)) {
		return  true;
	}
	else {
		return false;
	}
}

void Button::deactivate() {
	txt.setFillColor(sf::Color(100, 100, 100));
	isActivated = false;
}

void Button::activate() {
	txt.setFillColor(sf::Color::White);
	isActivated = true;
}

void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const {

	states.texture = NULL;

	target.draw(box, states);
	target.draw(txt, states);
}