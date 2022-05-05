#include "ShowWin.h"

ShowWin::ShowWin(std::vector<Reel>* reels, int winPlace) :
	ptrReels(reels),
	winNum(1),
	winPlace(winPlace),
	factorS(0.f),
	factorR(0.f)
{
	int winId = reels->at(0).getSymbolID(winPlace);

	for (int i = 1; i < reels->size(); ++i) {
		if (reels->at(i).getSymbolID(winPlace) == winId) {
			++winNum;
		}
		else {
			break;
		}
	}
}

void ShowWin::handleSpins(std::vector<Reel>* reels, float& velocity, float& offset, float time)
{
	factorS = sin(time * 0.0005f);
	factorR = sin(time * 0.1f);
	if (reels->at(0).getScale(winPlace) >= 1.3f) {
		factorS += 0.5f;
		for (int i = 0; i < winNum; ++i) {
			reels->at(i).resetRotation(winPlace);
		}
	}
	else {
		factorS += 1.f;
	}
	for (int i = 0; i < winNum; ++i) {
		reels->at(i).scale(winPlace, factorS);
		reels->at(i).rotate(winPlace, factorR);
	}
}

int ShowWin::handleState(sf::RenderWindow& window, Button& startbtn, Button& stopbtn, float& velocity, sf::Clock& spinClock)
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
		if (event.type == sf::Event::MouseButtonPressed)
		{
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				sf::Vector2i mouse = sf::Mouse::getPosition(window);

				if (startbtn.select(mouse)) {
					for (int i = 0; i < winNum; ++i) {
						ptrReels->at(i).resetRotation(winPlace);
						ptrReels->at(i).resetScale(winPlace);
					}
					startbtn.deactivate();
					return 1;
				}
			}
		}
	}
	if (winNum >= 3) {
		return 4;
	}
	return 0;
}
