//Menu class.
#ifndef TEST_TEST_H
#define TEST_TEST_H

#include <iostream>
#include <SFML/Graphics.hpp>

#define MAX_NUMBER_OF_ITEMS 4
using namespace std;

class Menu {
public:
    Menu(float width, float height);

    ~Menu();

    void draw(sf::RenderWindow &window);

    void moveUp();

    void moveDown();

    int getPressedItem() { return selectedItemIndex; }

private:
    int selectedItemIndex;
    sf::Font font;
    sf::Text menu[MAX_NUMBER_OF_ITEMS];
};

#endif //TEST_TEST_H
