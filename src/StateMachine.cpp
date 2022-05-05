#include "StateMachine.h"

StateMachine::StateMachine(float width, float heigth, float minVel, float maxVel, float spinTime) :
    widthW(width),
    heigthW(heigth),
    minVel(minVel),
    maxVel(maxVel),
    winPlace(0),
    velocity(0.f),
    spinTime(spinTime),
    curState(0)
{
    ptrState = std::make_unique<Wait> (Wait());
}

void StateMachine::mainloop()
{
    sf::RenderWindow window(sf::VideoMode((int)widthW, (int)heigthW), "Slot machine");

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

    Button startbtn(1270, 270, 200, 50, "START");
    Button stopbtn(1270, 400, 200, 50, "STOP");
    stopbtn.deactivate();

    sf::RectangleShape bottomBorder(sf::Vector2f(widthW, heigthW - 650));
    bottomBorder.setPosition(0, 650);
    bottomBorder.setFillColor(sf::Color(255, 255, 102));

    sf::RectangleShape topBorder(sf::Vector2f(widthW, heigthW - 650));
    topBorder.setPosition(0, 0);
    topBorder.setFillColor(sf::Color(255, 255, 102));

    sf::ConvexShape triangle;
    triangle.setPointCount(3);
    triangle.setPoint(0, sf::Vector2f(0, 0));
    triangle.setPoint(1, sf::Vector2f(0, 50));
    triangle.setPoint(2, sf::Vector2f(50, 25));
    triangle.setOutlineColor(sf::Color::Red);
    triangle.setOutlineThickness(5);
    triangle.setPosition(150, 325);

    sf::Clock clock;
    float time = 0.f;
    float offset = 0.f;

    int nextState = 0;

    while (window.isOpen())
    {
        time = clock.getElapsedTime().asMicroseconds();
        time /= 1000;
        clock.restart();

        ptrState->handleSpins(&reels, velocity, offset, time);
        nextState = ptrState->handleState(window, startbtn, stopbtn, velocity, spinClock);
        selectState(nextState);

        window.clear(sf::Color(255, 255, 102));
        for (int i = 0; i < reels.size(); ++i) {
            window.draw(reels[i]);
        }
        window.draw(topBorder);
        window.draw(bottomBorder);
        window.draw(triangle);
        window.draw(startbtn);
        window.draw(stopbtn);
        window.display();
    }
}

void StateMachine::selectState(int nextState) {
    if (curState != nextState) {
        switch (nextState) {
        case 0:
            ptrState = std::make_unique<Wait>(Wait());
            break;
        case 1:
            ptrState = std::make_unique<StartSpin>(StartSpin(maxVel));
            break;
        case 2:
            ptrState = std::make_unique<Spin>(Spin(spinTime));
            spinClock.restart();
            break;
        case 3:
            ptrState = std::make_unique<StopSpin>(StopSpin(minVel));
            break;
        case 4:
            winPlace = ptrState->getWinNum();
            ptrState = std::make_unique<ShowWin>(ShowWin(&reels, winPlace));
            break;
        default:
            break;
        }
        curState = nextState;
    }
}