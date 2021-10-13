#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>
#include "../inc/flight_path.hpp"

using namespace fp;

Flight_path::Flight_path(double V0, double angle, double g, double h)
{
    this->V0 = V0;
    this->angle = deg2rad(angle);
    this->g = g;
    this->h = h;
}

Flight_path::~Flight_path() {}

void Flight_path::calcValues()
{
    V0x = V0*cos(angle);
    V0y = V0*sin(angle);

    H = h+((V0y*V0y)/(2.0*g));

    t1 = V0y/g;
    t2 = sqrt((2.0*H)/g);
    t3 = t2 - t1;

    S1 = V0x*(t1+t2);
    S2 = -V0y*t3;
    std::cout << S1 << "\n";
}

double Flight_path::calcY(double X)
{
    return h+((V0y/V0x)*X)-((g/(2.0*(V0x*V0x)))*(X*X));
}

void Flight_path::drawPath(sf::RenderWindow& window)
{
    for(int x = 0; x < S1; x ++)
    {
        sf::CircleShape point;
        point.setRadius(1);
        double yf = 1.0/2.0;
        point.setFillColor(sf::Color(255, 255, 255));
        if(x==round((S1-S2)/2.0))
        {
            point.setFillColor(sf::Color(255, 0, 0));
            point.setRadius(5);
            yf = 5.0/2.0;
        }
            // point.setRadius(5);
        double y = calcY(x);
        point.setPosition(sf::Vector2f(((x*window.getSize().x)/S1)-yf, window.getSize().y-y-yf));
        window.draw(point);
    }
}

double Flight_path::deg2rad(double deg)
{
    return (deg * M_PI) / 180.0;
}