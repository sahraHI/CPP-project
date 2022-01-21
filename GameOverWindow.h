//Game over window class
#ifndef PROJECT1_GAMEOVERWINDOW_H
#define PROJECT1_GAMEOVERWINDOW_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"
#include "GameOver.h"
#include "GameWindow.h"

using namespace std;

class GameOverWindow {
public:
    GameOverWindow(double newSpeed);

    ~GameOverWindow();

    void draw(sf::RenderWindow &window);

private:
    double speed;
};

#endif //PROJECT1_GAMEOVERWINDOW_H
