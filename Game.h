//Game class.
#ifndef PROJECT1_GAME_H
#define PROJECT1_GAME_H

#include <iostream>
#include <array>
#include <SFML/Graphics.hpp>

#define SIZE_OF_TEXTURE 20
using namespace std;

class Game {

public:
    Game();

    ~Game();

    void draw(sf::RenderWindow &window);

    void updateFood();

    void update();

protected:
    sf::Texture floorTexture, foodTexture, wallTexture;

    sf::Sprite floorSprite, foodSprite, wallSprite;

    sf::Vector2<float> food1;
    sf::Vector2<float> food2;

    array<float, 4> lengthWall1;
    array<float, 4> widthWall1;

    array<float, 4> lengthWall2;
    array<float, 4> widthWall2;

};

#endif //PROJECT1_GAME_H
