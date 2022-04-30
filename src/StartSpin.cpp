#include "StartSpin.h"

void StartSpin::handleSpins(std::vector<Reel>* reels, float& velocity, float& offset, float time)
{
    if (velocity < maxVel) {
        velocity += 0.0005f;
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

int StartSpin::handleState(sf::RenderWindow& window, Button& startbtn, Button& stopbtn, float& velocity, sf::Clock& spinClock)
{
    if (velocity >= maxVel) {
        velocity = maxVel;
        return 3;
    }
    return 1;
}
