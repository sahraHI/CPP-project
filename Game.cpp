#include "Game.h"

Game::Game() {

    //Load texture for floor.
    if (!floorTexture.loadFromFile("1.png")) {
        cout << "Error loading file";
    }
    floorSprite.setTexture(floorTexture);

    //Load texture for food.
    if (!food1Texture.loadFromFile("2.png")) {
        cout << "Error loading file";
    }
    food1Sprite.setTexture(food1Texture);
    food1.x = (rand() % 40) * SIZE_OF_TEXTURE;
    food1.y = (rand() % 30) * SIZE_OF_TEXTURE;
    food1Sprite.setPosition(food1);

    if (!food2Texture.loadFromFile("6.jpg")) {
        cout << "Error loading file";
    }
    food2Sprite.setTexture(food2Texture);
    food2.x = (rand() % 40) * SIZE_OF_TEXTURE;
    food2.y = (rand() % 30) * SIZE_OF_TEXTURE;
    food2Sprite.setPosition(food2);

}

Game::~Game() {

}

void Game::updateFood1() {
    food1.x = (rand() % 40) * SIZE_OF_TEXTURE;
    food1.y = (rand() % 30) * SIZE_OF_TEXTURE;
    food1Sprite.setPosition(food1);
}

void Game::updateFood2() {
    food2.x = (rand() % 40) * SIZE_OF_TEXTURE;
    food2.y = (rand() % 30) * SIZE_OF_TEXTURE;
    food2Sprite.setPosition(food2);
}

//To draw game page.
void Game::draw(sf::RenderWindow &window) {

    //Draw floor.
    for (int i = 0; i < 40; ++i) {
        for (int j = 0; j < 30; ++j) {
            floorSprite.setPosition(i * SIZE_OF_TEXTURE, j * SIZE_OF_TEXTURE);
            window.draw(floorSprite);
        }
    }

    //Draw foods.
    window.draw(food1Sprite);
    window.draw(food2Sprite);

}
