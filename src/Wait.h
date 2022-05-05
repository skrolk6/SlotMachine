#pragma once
#include "State.h"

class Wait : public State {
public:
	virtual void handleSpins(std::vector<Reel>* reels, float& velocity, float& offset, float time) {}
	virtual int handleState(sf::RenderWindow& window, Button& startbtn, Button& stopbtn,float& velocity, sf::Clock& spinClock) override;
};