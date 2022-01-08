#include "Options.h"

Option::Option(float width, float height) {

    //load font for option.
    if (!font.loadFromFile("calibri.ttf")) {
        cout << "Error loading file" << endl;
        system("pause");
    }

    //Create Options text features.
    option[0].setFont(font);
    option[0].setFillColor(sf::Color::Yellow);
    option[0].setString("Options");
    option[0].setCharacterSize(80);
    option[0].setPosition(sf::Vector2f((width / 3), height / (MAX_NUMBER_OF_OPTIONS + 5) * 1));

    //Crete Sound button features.
    option[1].setFont(font);
    option[1].setFillColor(sf::Color::Yellow);
    option[1].setString("Sound");
    option[1].setCharacterSize(70);
    option[1].setPosition(sf::Vector2f((width / 2) - 90, height / (MAX_NUMBER_OF_OPTIONS + 2) * 2));

    //Crete Speed button features.
    option[2].setFont(font);
    option[2].setFillColor(sf::Color::White);
    option[2].setString("Speed");
    option[2].setCharacterSize(70);
    option[2].setPosition(sf::Vector2f((width / 2) - 90, height / (MAX_NUMBER_OF_OPTIONS + 2) * 3));

    //Crete Back button features.
    option[3].setFont(font);
    option[3].setFillColor(sf::Color::White);
    option[3].setString("Back");
    option[3].setCharacterSize(70);
    option[3].setPosition(sf::Vector2f((width / 2) - 70, height / (MAX_NUMBER_OF_OPTIONS + 2) * 4));

    selectedOption = 1;
}

Option::~Option() {

}

//To draw option page.
void Option::draw(sf::RenderWindow &window) {
    for (int i = 0; i < MAX_NUMBER_OF_OPTIONS; ++i) {
        window.draw(option[i]);
    }
}

//To move up in the options.
void Option::moveUp() {
    if (selectedOption - 1 >= 1) {
        option[selectedOption].setFillColor(sf::Color::White);
        selectedOption--;
        option[selectedOption].setFillColor(sf::Color::Yellow);
    }
}

//To move down in the options.
void Option::moveDown() {
    if (selectedOption + 1 < MAX_NUMBER_OF_OPTIONS) {
        option[selectedOption].setFillColor(sf::Color::White);
        selectedOption++;
        option[selectedOption].setFillColor(sf::Color::Yellow);
    }
}


