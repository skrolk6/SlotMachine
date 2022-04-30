#include "Reel.h"

Reel::Reel(bool direct, float x, float y) :
	offset(0),
	initPos(0.f),
	direction(0.f)
{
	this->setPosition(x, y);
	setTextures();
	for (int i = 0; i < 4; ++i) {
		Symbol sym;
		sym.id = std::rand() % 4;
		symlist.emplace_back(sym);
	}
	setDirection(direct);
	mainRect.setSize(sf::Vector2f(200, 600));
	mainRect.setFillColor(sf::Color::White);
}

void Reel::draw(sf::RenderTarget& target, sf::RenderStates states) const 
{

	states.transform *= getTransform();
	states.transform.translate(200, 50);

	target.draw(mainRect, states);
	drawSymbols(target, states);
}

void Reel::drawSymbols(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform.translate(0, offset * direction + initPos);

	for (auto& i : symlist) {
		sf::Sprite rect = i.rect;
		rect.setTexture(allSymbols[i.id]);
		target.draw(rect, states);
	}
}

void Reel::resetPosition() {
	symlist.pop_back();
	for (auto& i : symlist) {
		i.rect.move(0, offset * direction);
	}
	Symbol sym;
	sym.rect.setPosition(0, 0);
	sym.id = std::rand() % 4;
	symlist.emplace_front(sym);
}

void Reel::setDirection(bool direct)
{
	if (direct == 0) {
		direction = -1;
		initPos = 615;
		int cnt = 0;
		for (auto& i : symlist) {
			i.rect.setPosition(0, cnt * 200 * -1);
			++cnt;
		}
	}
	else {
		direction = 1;
		initPos = -185;
		int cnt = 0;
		for (auto& i : symlist) {
			i.rect.setPosition(0, cnt * 200);
			++cnt;
		}
	}
}

void Reel::setTextures()
{
	for (int i = 1; i < 5; ++i) {
		sf::Image image;
		sf::Texture texture;
		std::string name("../SlotMachine/symbols/sym");
		name += std::to_string(i);
		name += ".png";
		image.loadFromFile(name);
		texture.loadFromImage(image);
		allSymbols.emplace_back(texture);
	}
}
