//Game over class
#ifndef PROJECT1_GAMEOVER_H
#define PROJECT1_GAMEOVER_H

#include <iostream>
#include <SFML/Graphics.hpp>

#define MAX_NUMBER_Of_BUTTON 3
using namespace std;

class GameOver {
public:
    GameOver(float width, float height);

    ~GameOver();

    void draw(sf::RenderWindow &window);

    void moveUp();

    void moveDown();

    int getPressedButton() { return selectedButtonIndex; }

private:
    int selectedButtonIndex;

    sf::Texture texture;

    sf::Sprite sprite;

    sf::Font font;

    sf::Text menu[MAX_NUMBER_Of_BUTTON];
};

#endif //PROJECT1_GAMEOVER_H
