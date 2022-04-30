#include "Spin.h"

void Spin::handleSpins(std::vector<Reel>* reels, float& velocity, float& offset, float time)
{
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

int Spin::handleState(sf::RenderWindow& window, Button& startbtn, Button& stopbtn, float& velocity, sf::Clock& spinClock)
{
    float time = spinClock.getElapsedTime().asSeconds();
    if (time >= spinTime) {
        return 2;
    }
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
        if (event.type == sf::Event::MouseButtonPressed)
        {
            if (event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2i mouse = sf::Mouse::getPosition(window);

                if (stopbtn.select(mouse)) {
                    return 2;
                }
            }
        }
    }
    return 3;
}
