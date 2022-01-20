#ifndef PROJECT1_PAUSEGAME_H
#define PROJECT1_PAUSEGAME_H

#include <SFML/Graphics.hpp>

#include <iostream>

using namespace std;

class PauseGame {
public:
    PauseGame();

    ~PauseGame();

    void drawPaus(sf::RenderWindow &window);

    sf::Font font;

    sf::Text pause;

};

#endif //PROJECT1_PAUSEGAME_H
