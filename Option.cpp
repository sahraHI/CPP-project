#include "Option.h"

Option::Option(float width, float height) {

    //Load font for option.
    if (!font.loadFromFile("calibri.ttf")) {
        cout << "Error loading file" << endl;
        system("pause");
    }

    //Change  Options text features.
    option[0].setFont(font);
    option[0].setFillColor(sf::Color::Yellow);
    option[0].setString("Options");
    option[0].setCharacterSize(80);
    option[0].setPosition(sf::Vector2f(width / 3, height / (MAX_NUMBER_OF_OPTIONS + 5) * 1));

    //Change  Sound button features.
    option[6].setFont(font);
    option[6].setFillColor(sf::Color::White);
    option[6].setString("Sound");
    option[6].setCharacterSize(70);
    option[6].setPosition(sf::Vector2f((width / 2) - 90, height / (MAX_NUMBER_OF_OPTIONS + 2) * 3));

    //Change  Mute button features.
    option[1].setFont(font);
    option[1].setFillColor(sf::Color::Yellow);
    option[1].setString("Mute");
    option[1].setCharacterSize(30);
    option[1].setPosition(sf::Vector2f((width / 2) - 30, ((height / (MAX_NUMBER_OF_OPTIONS + 2)) + 5) * 4));

    //Change  Unmute button features.
    option[2].setFont(font);
    option[2].setFillColor(sf::Color::White);
    option[2].setString("Unmute");
    option[2].setCharacterSize(30);
    option[2].setPosition(sf::Vector2f((width / 2) - 50, ((height / (MAX_NUMBER_OF_OPTIONS + 2)) + 13) * 4));

    //Change  Speed button features.
    option[7].setFont(font);
    option[7].setFillColor(sf::Color::White);
    option[7].setString("Speed");
    option[7].setCharacterSize(70);
    option[7].setPosition(sf::Vector2f((width / 2) - 80, height / (MAX_NUMBER_OF_OPTIONS + 2) * 5));

    //Change  Fast button features.
    option[3].setFont(font);
    option[3].setFillColor(sf::Color::White);
    option[3].setString("Fast");
    option[3].setCharacterSize(30);
    option[3].setPosition(sf::Vector2f((width / 2) - 20, ((height / (MAX_NUMBER_OF_OPTIONS + 2)) + 3) * 6));

    //Change  Slow button features.
    option[4].setFont(font);
    option[4].setFillColor(sf::Color::White);
    option[4].setString("Slow");
    option[4].setCharacterSize(30);
    option[4].setPosition(sf::Vector2f((width / 2) - 25, ((height / (MAX_NUMBER_OF_OPTIONS + 2)) + 9) * 6));

    //Change  Back button features.
    option[5].setFont(font);
    option[5].setFillColor(sf::Color::White);
    option[5].setString("Back");
    option[5].setCharacterSize(70);
    option[5].setPosition(sf::Vector2f((width / 2) - 65, height / (MAX_NUMBER_OF_OPTIONS + 2) * 7));

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
    if (selectedOption + 1 < MAX_NUMBER_OF_OPTIONS - 2) {
        option[selectedOption].setFillColor(sf::Color::White);
        selectedOption++;
        option[selectedOption].setFillColor(sf::Color::Yellow);
    }
}
