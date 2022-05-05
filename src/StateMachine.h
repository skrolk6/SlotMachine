#pragma once
#include "StartSpin.h"
#include "StopSpin.h"
#include "Wait.h"
#include "Spin.h"
#include "ShowWin.h"
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
	std::unique_ptr<State> ptrState;
	int curState;
	int winPlace;
	float velocity;
	float minVel;
	float maxVel;
	float widthW;
	float heigthW;
};