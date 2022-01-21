//Snake class
#ifndef PROJECT1_SNAKES_H
#define PROJECT1_SNAKES_H

#include <list>
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

class Snakes : public sf::Drawable {
private:
    std::list<sf::Sprite> body1;
    std::list<sf::Sprite>::iterator head1;
    std::list<sf::Sprite>::iterator tail1;

    std::list<sf::Sprite> body2;
    std::list<sf::Sprite>::iterator head2;
    std::list<sf::Sprite>::iterator tail2;

    std::list<sf::Sprite> wall1;
    std::list<sf::Sprite> wall2;

    sf::Texture body1Texture, body2Texture, wall1Texture, wall2Texture;

    int score1, score2;

    sf::Font font;

    sf::Text score[2];

public:
    Snakes();

    ~Snakes();

    void move1(const sf::Vector2f &direction);

    void move2(const sf::Vector2f &direction);

    bool isOn1(const sf::Sprite &other) const;

    bool isOn2(const sf::Sprite &other) const;

    void grow1(const sf::Vector2f &direction);

    void grow2(const sf::Vector2f &direction);

    bool isSelfIntersecting() const;

    bool collisionOfSnakes() const;

    bool snakeHitWall1() const;

    bool snakeHitWall2() const;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};

#endif //PROJECT1_SNAKES_H
