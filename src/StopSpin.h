#pragma once
#include "State.h"

class StopSpin : public State {
public:
	StopSpin(float minVel);
	virtual void handleSpins(std::vector<Reel>* reels, float& velocity, float& offset, float time) override;
	virtual int handleState(sf::RenderWindow& window, Button& startbtn, Button& stopbtn, float& velocity, sf::Clock& spinClock) override;
	int getWinNum() { return this->winPlace; }
private:
	float minVel;
	int winPlace;
};
