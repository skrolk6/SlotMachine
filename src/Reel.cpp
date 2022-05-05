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
	for (auto& i : symlist) {
		i.rect.setTexture(allSymbols[i.id], true);
	}
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
		target.draw(i.rect, states);
	}
}

void Reel::scale(int num, float factor)
{
	std::list<Symbol>::iterator it = symlist.begin();
	std::advance(it, num);
	it->rect.scale(factor, factor);
}

void Reel::rotate(int num, float factor)
{
	std::list<Symbol>::iterator it = symlist.begin();
	std::advance(it, num);
	it->rect.rotate(factor);
}

void Reel::resetRotation(int num)
{
	std::list<Symbol>::iterator it = symlist.begin();
	std::advance(it, num);
	it->rect.setRotation(0.f);
}

void Reel::resetScale(int num)
{
	std::list<Symbol>::iterator it = symlist.begin();
	std::advance(it, num);
	it->rect.setScale(1.f, 1.f);
}

float Reel::getScale(int num)
{
	std::list<Symbol>::iterator it = symlist.begin();
	std::advance(it, num);
	return it->rect.getScale().x;
}

int Reel::getSymbolID(int num)
{
	std::list<Symbol>::iterator it = symlist.begin();
	std::advance(it, num);

	return it->id;
}

void Reel::resetPosition() {
	symlist.pop_back();
	for (auto& i : symlist) {
		i.rect.move(0, offset * direction);
	}
	Symbol sym;
	sym.rect.setOrigin(100, 100);
	sym.rect.setPosition(100, 100);
	sym.id = std::rand() % 4;
	sym.rect.setTexture(allSymbols[sym.id], true);
	symlist.emplace_front(sym);
}

void Reel::setDirection(bool direct)
{
	if (direct == 0) {
		direction = -1;
		initPos = 615;
		float cnt = 0;
		for (auto& i : symlist) {
			i.rect.setOrigin(100, 100);
			i.rect.setPosition(100, 100 + cnt * 200 * -1);
			++cnt;
		}
	}
	else {
		direction = 1;
		initPos = -185;
		float cnt = 0;
		for (auto& i : symlist) {
			i.rect.setOrigin(100, 100);
			i.rect.setPosition(100, 100 +  cnt * 200);
			++cnt;
		}
	}
}

void Reel::setTextures()
{
	for (int i = 1; i < 5; ++i) {
		sf::Image image;
		sf::Texture texture;
		std::string name("data/symbols/sym");
		name += std::to_string(i);
		name += ".png";
		try {
			if (!image.loadFromFile(name)) throw std::runtime_error("Failed to load image!");
		}
		catch (std::runtime_error & e) {
			std::cout << e.what();
			return;
		}
		texture.loadFromImage(image);
		texture.setSmooth(true);
		allSymbols.emplace_back(texture);
	}
}
