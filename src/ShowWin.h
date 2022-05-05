#pragma once
#include "State.h"
#include "math.h"

class ShowWin : public State {
public:
	ShowWin(std::vector<Reel>* reels, int winPlace);
	virtual void handleSpins(std::vector<Reel>* reels, float& velocity, float& offset, float time) override;
	virtual int handleState(sf::RenderWindow& window, Button& startbtn, Button& stopbtn, float& velocity, sf::Clock& spinClock) override;

private:
	std::vector<Reel>* ptrReels;
	int winNum;
	int winPlace;
	float factorS;
	float factorR;
};