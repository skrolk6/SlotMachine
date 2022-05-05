#pragma once
#include "Reel.h"
#include "Button.h"

class State {
public:

	virtual void handleSpins(std::vector<Reel>* reels, float& velocity, float& offset, float time) = 0;
	virtual int handleState(sf::RenderWindow& window, Button& startbtn, Button& stopbtn, float &velocity, sf::Clock& spinClock) = 0;
	virtual int getWinNum() { return 0; }

	virtual ~State() = default;
};