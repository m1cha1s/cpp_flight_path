#include <iostream>
#include <SFML/Graphics.hpp>
#include <flight_path.hpp>

sf::Clock dc;
sf::Time dt;

int main(int, char**) {
    sf::RenderWindow window(sf::VideoMode(500, 500), "Flight path");
    fp::Flight_path path(10.0, 30.0, 10.0, 10.0);
    path.calcValues();
    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed :
                window.close();
                break;
            
            default:
                break;
            }
        }

        if(dc.getElapsedTime().asSeconds() > 0.1)
        {
            dt = dc.restart();
            path.calcValues();
        }

        window.clear();
        path.drawPath(window);
        window.display();

    }
}
