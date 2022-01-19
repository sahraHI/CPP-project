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

//Load texture for wall.
    if (!wall1Texture.loadFromFile("3.png")) {
        cout << "Error loading file";
    }
    wall1Sprite.setTexture(wall1Texture);
    lengthWall1[0] = (rand() % 40) * SIZE_OF_TEXTURE;
    widthWall1[0] = (rand() % 30) * SIZE_OF_TEXTURE;

    for (int i = 0; i < 4; ++i) {
        lengthWall1[i] = lengthWall1[i - 1] + SIZE_OF_TEXTURE;
        widthWall1[i] = widthWall1[0];
    }
    if (!wall2Texture.loadFromFile("3.png")) {
        cout << "Error loading file";
    }
    wall2Sprite.setTexture(wall2Texture);
    lengthWall2[0] = (rand() % 40) * SIZE_OF_TEXTURE;
    widthWall2[0] = (rand() % 30) * SIZE_OF_TEXTURE;

    for (int i = 0; i < 4; ++i) {
        lengthWall2[i] = lengthWall2[i - 1] + SIZE_OF_TEXTURE;
        widthWall2[i] = widthWall2[0];
    }
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

    //Draw walls.
    for (int i = 0; i < 4; ++i) {
        wall1Sprite.setPosition(lengthWall1[i], widthWall1[i]);
        window.draw(wall1Sprite);
    }

    for (int i = 0; i < 4; ++i) {
        wall2Sprite.setPosition(lengthWall2[i], widthWall2[i]);
        window.draw(wall2Sprite);
    }
}
