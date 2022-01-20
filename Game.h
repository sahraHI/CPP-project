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

    void updateFood1();

    void updateFood2();

    void draw(sf::RenderWindow &window);

    sf::Sprite floorSprite, food1Sprite,food2Sprite;

private:
    sf::Texture floorTexture, food1Texture,food2Texture;

    sf::Vector2f food1;
    sf::Vector2f food2;

};

#endif //PROJECT1_GAME_H
