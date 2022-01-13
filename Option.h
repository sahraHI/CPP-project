//Option class.
#ifndef PROJECT1_OPTION_H
#define PROJECT1_OPTION_H

#include <iostream>
#include <SFML/Graphics.hpp>

#define MAX_NUMBER_OF_OPTIONS 8
using namespace std;

class Option {
public:
    Option(float width, float height);

    ~Option();

    void draw(sf::RenderWindow &window);

    void moveUp();

    void moveDown();

    int getPressedOption() { return selectedOption; }


private:
    int selectedOption;

    sf::Font font;

    sf::Text option[MAX_NUMBER_OF_OPTIONS];
};

#endif //PROJECT1_OPTION_H
