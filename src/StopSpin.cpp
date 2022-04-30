#include "StopSpin.h"

void StopSpin::handleSpins(std::vector<Reel>* reels, float& velocity, float& offset, float time)
{
    if (velocity > minVel) {
        velocity -= 0.0005f;
    }
    else if(offset == 200.f || offset == 0.f){
        velocity = 0.f;
    }
    offset += velocity * time;
    for (int i = 0; i < reels->size(); ++i) {
        reels->at(i).makeOffset(offset);
    }
    if (abs(offset >= 200.f)) {
        for (int i = 0; i < reels->size(); ++i) {
            reels->at(i).resetPosition();
            reels->at(i).makeOffset(0.f);
            offset = 0.f;
        }
    }
}

int StopSpin::handleState(sf::RenderWindow& window, Button& startbtn, Button& stopbtn, float& velocity, sf::Clock& spinClock)
{
    if (velocity == 0.f) {
        startbtn.activate();
        return 0;
    }
    return 2;
}
