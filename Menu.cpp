#include "Menu.h"

Menu::Menu(float width, float height) {

    //Load texture for menu.
    if (!texture.loadFromFile("0.jpg")) {
        cout << "Error loading file";
    }
    texture.setSmooth(true);
    texture.setRepeated(true);

    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0, 0, 800, 600));

    //Load font for menu.
    if (!font.loadFromFile("CURLZ___.TTF")) {
        cout << "Error loading file" << endl;
        system("pause");
    }

    //Change  Welcome text features.
    menu[0].setFont(font);
    menu[0].setFillColor(sf::Color::Black);
    menu[0].setString("Welcome to the Snake Game");
    menu[0].setStyle(sf::Text::Bold);
    menu[0].setCharacterSize(50);
    menu[0].setPosition(sf::Vector2f((width / 4) - 70, ((height / (MAX_NUMBER_OF_ITEMS + 6)) - 20) * 1));

    //Change  Play button features.
    menu[1].setFont(font);
    menu[1].setFillColor(sf::Color(0, 150, 255));
    menu[1].setString("Play");
    menu[0].setStyle(sf::Text::Bold);
    menu[1].setCharacterSize(70);
    menu[1].setPosition(sf::Vector2f((width / 2) - 50, ((height / (MAX_NUMBER_OF_ITEMS + 2)) + 18) * 3));

    //Change  Option button features.
    menu[2].setFont(font);
    menu[2].setFillColor(sf::Color::Black);
    menu[2].setString("Options");
    menu[0].setStyle(sf::Text::Bold);
    menu[2].setCharacterSize(70);
    menu[2].setPosition(sf::Vector2f((width / 2) - 100, ((height / (MAX_NUMBER_OF_ITEMS + 2)) + 5) * 4));

    //Change  Exit button features.
    menu[3].setFont(font);
    menu[3].setFillColor(sf::Color::Black);
    menu[3].setString("Exit");
    menu[0].setStyle(sf::Text::Bold);
    menu[3].setCharacterSize(70);
    menu[3].setPosition(sf::Vector2f((width / 2) - 50, height / (MAX_NUMBER_OF_ITEMS + 2) * 5));

    selectedItemIndex = 1;
}

Menu::~Menu() {

}

//To draw menu page.
void Menu::draw(sf::RenderWindow &window) {
    window.draw(sprite);
    for (int i = 0; i < MAX_NUMBER_OF_ITEMS; ++i) {
        window.draw(menu[i]);
    }
}

//To move up in the menu.
void Menu::moveUp() {
    if (selectedItemIndex - 1 >= 1) {
        menu[selectedItemIndex].setFillColor(sf::Color::Black);
        selectedItemIndex--;
        menu[selectedItemIndex].setFillColor(sf::Color(0, 150, 255));
    }
}

//To move down in the menu.
void Menu::moveDown() {
    if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS) {
        menu[selectedItemIndex].setFillColor(sf::Color::Black);
        selectedItemIndex++;
        menu[selectedItemIndex].setFillColor(sf::Color(0, 150, 255));
    }
}

