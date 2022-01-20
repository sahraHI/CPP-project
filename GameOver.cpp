#include "GameOver.h"

GameOver::GameOver(float width, float height) {

    //Load texture for game over page.
    if (!texture.loadFromFile("8.jpg")) {
        cout << "Error loading file";
    }
    texture.setSmooth(true);
    texture.setRepeated(true);

    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0, 0, 800, 600));

    //Load font for game over page.
    if (!font.loadFromFile("ROCC____.TTF")) {
        cout << "Error loading file" << endl;
        system("pause");
    }

    //Change  Game over text features.
    menu[0].setFont(font);
    menu[0].setFillColor(sf::Color(200,30,0));
    menu[0].setString("Game over");
    menu[0].setStyle(sf::Text::Underlined);
    menu[0].setCharacterSize(70);
    menu[0].setPosition(sf::Vector2f((width / 3)+20 , ((height / (MAX_NUMBER_Of_BUTTON + 6)) - 50) * 1));

    //Change  Restart button features.
    menu[1].setFont(font);
    menu[1].setFillColor(sf::Color::Black);
    menu[1].setString("Restart");
    menu[1].setCharacterSize(40);
    menu[1].setPosition(sf::Vector2f((width / 2) - 30, ((height / (MAX_NUMBER_Of_BUTTON + 2)) ) * 1));

    //Change  Exit button features.
    menu[2].setFont(font);
    menu[2].setFillColor(sf::Color(200,30,0));
    menu[2].setString("Exit");
    menu[2].setCharacterSize(40);
    menu[2].setPosition(sf::Vector2f((width / 2) - 30, ((height / (MAX_NUMBER_Of_BUTTON + 2))+50) * 1));

    selectedButtonIndex = 1;
}

GameOver::~GameOver() {

}

//To draw menu page.
void GameOver::draw(sf::RenderWindow &window) {
    window.draw(sprite);
    for (int i = 0; i < MAX_NUMBER_Of_BUTTON; ++i) {
        window.draw(menu[i]);
    }
}

//To move up in the menu.
void GameOver::moveUp() {
    if (selectedButtonIndex - 1 >= 1) {
        menu[selectedButtonIndex].setFillColor(sf::Color(200,30,0));
        selectedButtonIndex--;
        menu[selectedButtonIndex].setFillColor(sf::Color::Black);
    }
}

//To move down in the menu.
void GameOver::moveDown() {
    if (selectedButtonIndex + 1 < MAX_NUMBER_Of_BUTTON) {
        menu[selectedButtonIndex].setFillColor(sf::Color(200,30,0));
        selectedButtonIndex++;
        menu[selectedButtonIndex].setFillColor(sf::Color::Black);
    }
}

