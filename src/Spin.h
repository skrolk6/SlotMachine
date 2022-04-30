#pragma once
#include "State.h"

class Spin : public State {
public:
	virtual void handleSpins(std::vector<Reel>* reels, float& velocity, float& offset, float time) override;
	virtual int handleState(sf::RenderWindow& window, Button& startbtn, Button& stopbtn, float& velocity, sf::Clock& spinClock) override;
	void setSpinTime(float const time) { spinTime = time; }
	virtual ~Spin() {}
private:
	float spinTime;
};