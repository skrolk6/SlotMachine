#pragma once
#include "State.h"

class Spin : public State {
public:
	Spin(float spinTime);
	virtual void handleSpins(std::vector<Reel>* reels, float& velocity, float& offset, float time) override;
	virtual int handleState(sf::RenderWindow& window, Button& startbtn, Button& stopbtn, float& velocity, sf::Clock& spinClock) override;
private:
	float spinTime;
};