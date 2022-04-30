#pragma once
#include <SFML/Graphics.hpp>
#include <list>
#include <vector>
#include <iostream>
#include <cmath>

class Reel : public sf::Drawable, public sf::Transformable
{
public:

	Reel(bool direct, float x, float y);
	void resetPosition();
	void makeOffset(const float offset) { this->offset = offset; }
	float getOffset() { return offset; }
	void setDirection(bool direct);
	void setTextures();


private:

	struct Symbol {
		int id;
		sf::Sprite rect;
	};

	sf::RectangleShape mainRect;
	float offset;
	float initPos;
	float direction;
	std::list <Symbol> symlist;
	std::vector <sf::Texture> allSymbols;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void drawSymbols(sf::RenderTarget& target, sf::RenderStates states) const;
 
};