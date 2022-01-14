#include "Game.h"

Game::Game() {

    //Load texture for floor.
    if (!floorTexture.loadFromFile("1.png")) {
        cout << "Error loading file";
    }
    floorTexture.setSmooth(true);
    floorSprite.setTexture(floorTexture);

    //Load texture for food.
    if (!foodTexture.loadFromFile("2.png")) {
        cout << "Error loading file";
    }
    foodTexture.setSmooth(true);
    foodSprite.setTexture(foodTexture);

    //Load texture for wall.
    if (!wallTexture.loadFromFile("3.png")) {
        cout << "Error loading file";
    }
    wallTexture.setSmooth(true);
    wallSprite.setTexture(wallTexture);

    //Set foods location.
    food1.x = (rand() % 40) * SIZE_OF_TEXTURE;
    food1.y = (rand() % 30) * SIZE_OF_TEXTURE;

    food2.x = (rand() % 40) * SIZE_OF_TEXTURE;
    food2.y = (rand() % 30) * SIZE_OF_TEXTURE;

    //Swt walls location.
    lengthWall1[0] = (rand() % 40) * SIZE_OF_TEXTURE;
    widthWall1[0] = (rand() % 30) * SIZE_OF_TEXTURE;

    for (int i = 0; i < 4; ++i) {
        lengthWall1[i] = lengthWall1[i - 1] + SIZE_OF_TEXTURE;
        widthWall1[i] = widthWall1[0];
    }

    lengthWall2[0] = (rand() % 40) * SIZE_OF_TEXTURE;
    widthWall2[0] = (rand() % 30) * SIZE_OF_TEXTURE;

    for (int i = 0; i < 4; ++i) {
        lengthWall2[i] = lengthWall2[0];
        widthWall2[i] = widthWall2[i - 1] + SIZE_OF_TEXTURE;
    }
}

Game::~Game() {

}

void Game::updateFood() {

}

void Game::update() {

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
    foodSprite.setPosition(food1);
    window.draw(foodSprite);

    foodSprite.setPosition(food2);
    window.draw(foodSprite);

    //Draw walls.
    for (int i = 0; i < 4; ++i) {
        wallSprite.setPosition(lengthWall1[i], widthWall1[i]);
        window.draw(wallSprite);
    }

    for (int i = 0; i < 4; ++i) {
        wallSprite.setPosition(lengthWall2[i], widthWall2[i]);
        window.draw(wallSprite);
    }

}
