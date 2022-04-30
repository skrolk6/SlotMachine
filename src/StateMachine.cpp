#include "StateMachine.h"

StateMachine::StateMachine(float width, float heigth, float minVel, float maxVel, float spinTime) :
    widthW(width),
    heigthW(heigth),
    minVel(minVel),
    maxVel(maxVel),
    velocity(0.f),
    spinTime(spinTime)
{
    Reel reel(1, 0, 0);
    Reel reel1(0, 205, 0);
    Reel reel2(1, 410, 0);
    Reel reel3(0, 615, 0);
    Reel reel4(1, 820, 0);
    reels.emplace_back(reel);
    reels.emplace_back(reel1);
    reels.emplace_back(reel2);
    reels.emplace_back(reel3);
    reels.emplace_back(reel4);

    start.setMaxVel(maxVel);
    spin.setSpinTime(spinTime);
    stop.setMinVel(minVel);

    curstate = &wait;
}

void StateMachine::mainloop()
{
    sf::RenderWindow window(sf::VideoMode((int)widthW, (int)heigthW), "Slot machine");

    Button startbtn(1270, 270, 200, 50, "START");
    Button stopbtn(1270, 400, 200, 50, "STOP");

    sf::RectangleShape bottomBorder(sf::Vector2f(widthW, heigthW - 650));
    bottomBorder.setPosition(0, 650);
    bottomBorder.setFillColor(sf::Color(255, 255, 102));

    sf::RectangleShape topBorder(sf::Vector2f(widthW, heigthW - 650));
    topBorder.setPosition(0, 0);
    topBorder.setFillColor(sf::Color(255, 255, 102));

    sf::Clock clock;
    float time = 0.f;
    float offset = 0.f;

    int stateNum = 0;

    while (window.isOpen())
    {
        time = clock.getElapsedTime().asMicroseconds();
        time /= 1000;
        clock.restart();

        stateNum = curstate->handleState(window, startbtn, stopbtn, velocity, spinClock);
        selectState(stateNum);
        curstate->handleSpins(&reels, velocity, offset, time);

        window.clear(sf::Color(255, 255, 102));
        for (int i = 0; i < reels.size(); ++i) {
            window.draw(reels[i]);
        }
        window.draw(topBorder);
        window.draw(bottomBorder);
        window.draw(startbtn);
        window.draw(stopbtn);
        window.display();
    }
}

void StateMachine::selectState(int stateNum) {
    switch (stateNum) {
    case 0:
        curstate = &wait;
        break;
    case 1:
        curstate = &start;
        spinClock.restart();
        break;
    case 2:
        curstate = &stop;
        break;
    case 3:
        curstate = &spin;
        break;
    default:
        break;
    }
}
