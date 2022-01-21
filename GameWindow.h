#ifndef PROJECT1_GAMEWINDOW_H
#define PROJECT1_GAMEWINDOW_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Window.h"
#include "Game.h"
#include "Snakes.h"
#include "GameOver.h"
#include "GameOverWindow.h"
#include "PauseGame.h"

using namespace std;

class GameWindow {
public:
    GameWindow(double newSpeed);

    ~GameWindow();

    void draw(sf::RenderWindow &window);

private:
    sf::Vector2f snake1Direction;

    sf::Vector2f snake2Direction;

    sf::Time Time;

    double speed;
};

#endif //PROJECT1_GAMEWINDOW_H
