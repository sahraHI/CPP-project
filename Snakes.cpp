#include "Snakes.h"

Snakes::Snakes() : body1(std::list<sf::Sprite>(4)),body2(std::list<sf::Sprite>(4)) {
    head1 = --body1.end();
    tail1 = body1.begin();

    head2 = --body2.end();
    tail2 = body2.begin();

    if (!body1Texture.loadFromFile("4.png")) {
        cout << "Error loading file";
    }
    float x = (rand() % 40) * 20;
    float y = (rand() % 30) * 20;
    for (auto &piece1: body1) {
        piece1.setTexture(body1Texture);
        piece1.setPosition({x, y});
        x += 20.f;
    }

    if (!body2Texture.loadFromFile("5.png")) {
        cout << "Error loading file";
    }
    float w = (rand() % 40) * 20;
    float z = (rand() % 30) * 20;
    for (auto &piece2: body2) {
        piece2.setTexture(body2Texture);
        piece2.setPosition({w, z});
        x += 20.f;
    }
}

Snakes::~Snakes() {

}

void Snakes::move1(const sf::Vector2f &direction1) {
    tail1->setPosition(head1->getPosition() + direction1);
    head1 = tail1;
    ++tail1;

    if (tail1 == body1.end()) {
        tail1 = body1.begin();
    }
}

void Snakes::move2(const sf::Vector2f &direction2) {
    tail2->setPosition(head2->getPosition() + direction2);
    head2 = tail2;
    ++tail2;

    if (tail2 == body2.end()) {
        tail2 = body2.begin();
    }
}

bool Snakes::isOn1(const sf::Sprite &other) const {
    return other.getGlobalBounds().intersects(head1->getGlobalBounds());
}

bool Snakes::isOn2(const sf::Sprite &other) const {
    return other.getGlobalBounds().intersects(head2->getGlobalBounds());
}

void Snakes::grow1(const sf::Vector2f &direction) {
    sf::Sprite newPiece;
    newPiece.setTexture(*(body1.begin()->getTexture()));
    newPiece.setPosition(head1->getPosition() + direction);

    head1 = body1.insert(++head1, newPiece);

}

void Snakes::grow2(const sf::Vector2f &direction) {
    sf::Sprite newPiece;
    newPiece.setTexture(*(body2.begin()->getTexture()));
    newPiece.setPosition(head2->getPosition() + direction);

    head2 = body2.insert(++head2, newPiece);

}

void Snakes::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    for (auto &piece1: body1) {
        target.draw(piece1);
    }

    for (auto &piece2: body2) {
        target.draw(piece2);
    }
}