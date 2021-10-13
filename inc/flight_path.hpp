#ifndef FLIGHT_PATH_HPP
#define FLIGHT_PATH_HPP

#include <SFML/Graphics.hpp>

namespace fp
{
    class Flight_path
    {
    private:
        double V0;
        double angle;
        double g = 9.8;
        double h = 0;

        double V0x;
        double V0y;

        double H;
        double t1;
        double t2;
        double S1;

        double t3;
        double S2;

        double deg2rad(double deg);
    public:
        Flight_path(double V0, double angle, double g, double h);
        ~Flight_path();

        // void update(double dt);
        void calcValues();
        double calcY(double X);
        void drawPath(sf::RenderWindow& window);
    };   
} // namespace fp


#endif