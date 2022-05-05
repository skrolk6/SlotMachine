#include "Wait.h"

int Wait::handleState(sf::RenderWindow& window, Button& startbtn, Button& stopbtn, float& velocity, sf::Clock& spinClock) {
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

                if (startbtn.select(mouse)) {
                    startbtn.deactivate();
                    return 1;
                }
            }
        }
    }
    return 0;
}