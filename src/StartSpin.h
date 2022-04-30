#pragma once
#include "State.h"

class StartSpin : public State {
public:
	virtual void handleSpins(std::vector<Reel>* reels, float& velocity, float& offset, float time) override;
	virtual int handleState(sf::RenderWindow& window, Button& startbtn, Button& stopbtn, float& velocity, sf::Clock& spinClock) override;
	void setMaxVel(float const velocity) { maxVel = velocity; }
	virtual ~StartSpin() {}
private:
	float maxVel;
};