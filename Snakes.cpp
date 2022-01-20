#include "Snakes.h"

Snakes::Snakes() : body1(std::list<sf::Sprite>(4)), body2(std::list<sf::Sprite>(4)), wall1(std::list<sf::Sprite>(4)),
                   wall2(std::list<sf::Sprite>(4)) {

    head1 = --body1.end();
    tail1 = body1.begin();

    head2 = --body2.end();
    tail2 = body2.begin();

    if (!body1Texture.loadFromFile("4.png")) {
        cout << "Error loading file";
    }
    float x = (rand() % 38) * 20;
    float y = (rand() % 28) * 20;
    for (auto &piece1: body1) {
        piece1.setTexture(body1Texture);
        piece1.setPosition({x, y});
        x += 20.f;
    }

    if (!body2Texture.loadFromFile("5.png")) {
        cout << "Error loading file";
    }
    float w = (rand() % 38) * 20;
    float z = (rand() % 28) * 20;
    for (auto &piece2: body2) {
        piece2.setTexture(body2Texture);
        piece2.setPosition({w, z});
        z += 20.f;
    }

    if (!wall1Texture.loadFromFile("3.png")) {
        cout << "Error loading file";
    }
    float a = (rand() % 37) * 20;
    float b = (rand() % 30) * 20;

    for (auto &piece1: wall1) {
        piece1.setTexture(wall1Texture);
        piece1.setPosition({a, b});
        a += 20.f;
    }

    if (!wall2Texture.loadFromFile("3.png")) {
        cout << "Error loading file";
    }
    float c = (rand() % 40) * 20;
    float d = (rand() % 27) * 20;

    for (int i = -3; i <= 3; ++i) {
        if (c == a + i) c = (rand() % 40) * 20;

        if (d == b + i) d = (rand() % 27) * 20;
    }

    for (auto &piece2: wall2) {
        piece2.setTexture(wall1Texture);
        piece2.setPosition({c, d});
        d += 20.f;
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

    sf::Vector2f T = head1->getPosition();
    if (T.x == -20) head1->setPosition(40 * 20, T.y);
    if (T.x == 40 * 20) head1->setPosition(0, T.y);
    if (T.y == -20) head1->setPosition(T.x, 40 * 20);
    if (T.y == 40 * 20) head1->setPosition(T.x, 0);

}

void Snakes::move2(const sf::Vector2f &direction2) {
    tail2->setPosition(head2->getPosition() + direction2);
    head2 = tail2;
    ++tail2;

    if (tail2 == body2.end()) {
        tail2 = body2.begin();
    }

    sf::Vector2f M = head2->getPosition();
    if (M.x == -20) head2->setPosition(40 * 20, M.y);
    if (M.x == 40 * 20) head2->setPosition(0, M.y);
    if (M.y == -20) head2->setPosition(M.x, 30 * 20);
    if (M.y == 30 * 20) head2->setPosition(M.x, 0);

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

bool Snakes::isSelfIntersecting() const {
    bool flag = false;

    for (auto piece1 = body1.begin(); piece1 != body1.end(); ++piece1) {
        if (head1 != piece1) {
            flag = isOn1(*piece1);

            if (flag) {
                break;
            }
        }

        for (auto piece2 = body2.begin(); piece2 != body2.end(); ++piece2) {
            if (head2 != piece2) {
                flag = isOn2(*piece2);

                if (flag) {
                    break;
                }
            }
        }
    }

    return flag;
}

bool Snakes::collisionOfSnakes() const {
    bool flag = false;

    for (auto piece1 = body2.begin(); piece1 != body2.end(); ++piece1) {
        if (head2 != piece1) {
            flag = isOn1(*piece1);

            if (flag) {
                break;
            }
        }

        for (auto piece2 = body1.begin(); piece2 != body1.end(); ++piece2) {
            if (head1 != piece2) {
                flag = isOn2(*piece2);

                if (flag) {
                    break;
                }
            }
        }
    }

    return flag;
}

bool Snakes::snakeHitWall1() const {
    bool flag = false;

    for (auto piece1 = wall2.begin(); piece1 != wall2.end(); ++piece1) {

        if (wall2.begin() != piece1) {
            flag = isOn1(*piece1);

            if (flag) {
                break;
            }
        }

        for (auto piece2 = wall1.begin(); piece2 != wall1.end(); ++piece2) {
            if (wall1.begin() != piece2) {
                flag = isOn1(*piece2);

                if (flag) {
                    break;
                }
            }
        }

    }
    return flag;
}

bool Snakes::snakeHitWall2() const {
    bool flag = false;

    for (auto piece3 = wall2.begin(); piece3 != wall2.end(); ++piece3) {

        if (wall2.begin() != piece3) {
            flag = isOn2(*piece3);

            if (flag) {
                break;
            }
        }

        for (auto piece4 = wall1.begin(); piece4 != wall1.end(); ++piece4) {
            if (wall1.begin() != piece4) {
                flag = isOn2(*piece4);

                if (flag) {
                    break;
                }
            }
        }

    }

    return flag;
}

void Snakes::draw(sf::RenderTarget &target, sf::RenderStates states) const {

    for (auto &piece1: body1) {
        target.draw(piece1);
    }

    for (auto &piece2: body2) {
        target.draw(piece2);
    }

    for (auto &piece1: wall1) {
        target.draw(piece1);
    }

    for (auto &piece2: wall2) {
        target.draw(piece2);
    }
}