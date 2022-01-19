#include <list>
#include <iostream>

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>

using namespace std;

class Snakes : public sf::Drawable
{
private:
    std::list<sf::Sprite> body1;
    std::list<sf::Sprite>::iterator head1;
    std::list<sf::Sprite>::iterator tail1;

    std::list<sf::Sprite> body2;
    std::list<sf::Sprite>::iterator head2;
    std::list<sf::Sprite>::iterator tail2;

    sf::Texture body1Texture;
    sf::Texture body2Texture;

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

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};