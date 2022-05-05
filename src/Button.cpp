#include "Button.h"

Button::Button(double x, double y, double width, double height, std::string text) :
	x(x),
	y(y),
	width(width),
	height(height),
	text(text),
	isActivated(true)
{
	try {
		if (!font.loadFromFile("data/fonts/Bighaustitul extrabold.ttf")) throw std::runtime_error("Failed to load fonts!");
	}
	catch (std::runtime_error & e) {
		std::cout << e.what();
	}

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
	if ((mouse.x > box.getPosition().x && mouse.x < box.getPosition().x + box.getSize().x) && (mouse.y > box.getPosition().y && mouse.y < box.getPosition().y + box.getSize().y)) {
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