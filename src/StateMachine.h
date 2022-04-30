#pragma once
#include "StartSpin.h"
#include "StopSpin.h"
#include "Wait.h"
#include "Spin.h"
#include "Reel.h"

class StateMachine {
public :

	StateMachine(float width, float heigth, float minVel, float maxVel, float spinTime);
	void mainloop();
	void selectState(int stateNum);

private :

	std::vector<Reel> reels;
	sf::Clock spinClock;
	float spinTime;
	State* curstate;
	StartSpin start;
	StopSpin stop;
	Wait wait;
	Spin spin;
	float velocity;
	float minVel;
	float maxVel;
	float widthW;
	float heigthW;
};