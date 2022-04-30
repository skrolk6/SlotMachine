#pragma once
#include "State.h"

class StopSpin : public State {
public:
	virtual void handleSpins(std::vector<Reel>* reels, float& velocity, float& offset, float time) override;
	virtual int handleState(sf::RenderWindow& window, Button& startbtn, Button& stopbtn, float& velocity, sf::Clock& spinClock) override;
	void setMinVel(float const velocity) { minVel = velocity; }
	virtual ~StopSpin() {}
private:
	float minVel;
};
