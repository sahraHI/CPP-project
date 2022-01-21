//Option Window class.
#ifndef PROJECT1_OPTIONWINDOW_H
#define PROJECT1_OPTIONWINDOW_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "Option.h"
#include "GameWindow.h"

using namespace std;

class OptionWindow {
public:
    OptionWindow();

    ~OptionWindow();

    double draw(sf::RenderWindow &window,sf::Music &music);
};

#endif //PROJECT1_OPTIONWINDOW_H
