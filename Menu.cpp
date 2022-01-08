#include "Menu.h"

Menu::Menu(float width, float height) {

    //load font for menu.
    if (!font.loadFromFile("CURLZ___.TTF")) {
        cout << "Error loading file" << endl;
        system("pause");
    }

    //Create Welcome text features.
    menu[0].setFont(font);
    menu[0].setFillColor(sf::Color::Cyan);
    menu[0].setString("Welcome to the Snake Game");
    menu[0].setCharacterSize(50);
    menu[0].setPosition(sf::Vector2f((width / 4) - 70, height / (MAX_NUMBER_OF_ITEMS + 6) * 1));

    //Crete Play button features.
    menu[1].setFont(font);
    menu[1].setFillColor(sf::Color::Cyan);
    menu[1].setString("Play");
    menu[1].setCharacterSize(70);
    menu[1].setPosition(sf::Vector2f((width / 2) - 50, height / (MAX_NUMBER_OF_ITEMS + 2) * 2));

    //Crete Option button features.
    menu[2].setFont(font);
    menu[2].setFillColor(sf::Color::White);
    menu[2].setString("Options");
    menu[2].setCharacterSize(70);
    menu[2].setPosition(sf::Vector2f((width / 2) - 100, height / (MAX_NUMBER_OF_ITEMS + 2) * 3));

    //Crete Exit button features.
    menu[3].setFont(font);
    menu[3].setFillColor(sf::Color::White);
    menu[3].setString("Exit");
    menu[3].setCharacterSize(70);
    menu[3].setPosition(sf::Vector2f((width / 2) - 50, height / (MAX_NUMBER_OF_ITEMS + 2) * 4));

    selectedItemIndex = 1;
}

Menu::~Menu() {

}

//To draw menu page.
void Menu::draw(sf::RenderWindow &window) {
    for (int i = 0; i < MAX_NUMBER_OF_ITEMS; ++i) {
        window.draw(menu[i]);
    }
}

//To move up in the menu.
void Menu::moveUp() {
    if (selectedItemIndex - 1 >= 1) {
        menu[selectedItemIndex].setFillColor(sf::Color::White);
        selectedItemIndex--;
        menu[selectedItemIndex].setFillColor(sf::Color::Cyan);
    }
}

//To move down in the menu.
void Menu::moveDown() {
    if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS) {
        menu[selectedItemIndex].setFillColor(sf::Color::White);
        selectedItemIndex++;
        menu[selectedItemIndex].setFillColor(sf::Color::Cyan);
    }
}
