//Window class.
#ifndef PROJECT1_WINDOW_H
#define PROJECT1_WINDOW_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#include "Menu.h"
#include "Option.h"
#include "Game.h"
#include "Snakes.h"

using namespace std;

class Window {
public:

    Window();

    ~Window();

private:
    sf::Vector2f snake1Direction;
    sf::Vector2f snake2Direction;
    sf::Time Time;
};

#endif //PROJECT1_WINDOW_H
