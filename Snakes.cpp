#include "Snakes.h"

Snakes::Snakes() : body1(list<sf::Sprite>(4)), body2(list<sf::Sprite>(4)),
                   wall1(list<sf::Sprite>(4)), wall2(list<sf::Sprite>(4)) {

    //To set Snakes part.
    head1 = --body1.end();
    tail1 = body1.begin();

    head2 = --body2.end();
    tail2 = body2.begin();

    //Load texture for snakes.
    if (!body1Texture.loadFromFile("static\\4.png")) {
        cout << "Error loading texture 4 file";
    }
    float x = (rand() % 38) * 20;
    float y = (rand() % 28) * 20;

    for (auto &piece1: body1) {
        piece1.setTexture(body1Texture);
        piece1.setPosition({x, y});
        x += 20.f;
    }

    if (!body2Texture.loadFromFile("static\\5.png")) {
        cout << "Error loading texture 5 file";
    }
    float w = (rand() % 38) * 20;
    float z = (rand() % 28) * 20;

    for (auto &piece2: body2) {
        piece2.setTexture(body2Texture);
        piece2.setPosition({w, z});
        z += 20.f;
    }

    //Load texture for walls.
    if (!wall1Texture.loadFromFile("static\\6.png")) {
        cout << "Error loading texture 6 file";
    }
    float a = (rand() % 37) * 20;
    float b = (rand() % 30) * 20;

    for (auto &piece1: wall1) {
        piece1.setTexture(wall1Texture);
        piece1.setPosition({a, b});
        a += 20.f;
    }

    if (!wall2Texture.loadFromFile("static\\6.png")) {
        cout << "Error loading texture 6 file";
    }
    float c = (rand() % 40) * 20;
    float d = (rand() % 27) * 20;

    //To check the distance of the walls.
    for (int i = -3; i <= 3; ++i) {
        if (c == a + i) c = (rand() % 40) * 20;
        if (d == b + i) d = (rand() % 27) * 20;
    }

    for (auto &piece2: wall2) {
        piece2.setTexture(wall1Texture);
        piece2.setPosition({c, d});
        d += 20.f;
    }

    //The initial score of snakes.
    score1 = 0;
    score2 = 0;

    if (!font.loadFromFile("static\\calibri.ttf")) {
        cout << "Error loading fon file" << endl;
    }

    //Change  Score1 text features.
    score[0].setFont(font);
    score[0].setFillColor(sf::Color::Yellow);
    score[0].setString("Score1: " + to_string(score1));
    score[0].setCharacterSize(15);
    score[0].setPosition(sf::Vector2f(730, 0));

    //Change  Score2 text features.
    score[1].setFont(font);
    score[1].setFillColor(sf::Color::Cyan);
    score[1].setString("Score2: " + to_string(score2));
    score[1].setCharacterSize(15);
}

Snakes::~Snakes() {

}

//To move snake1.
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

//To move snake1.
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

//To grow snake1.
void Snakes::grow1(const sf::Vector2f &direction) {
    sf::Sprite newPiece;
    newPiece.setTexture(*(body1.begin()->getTexture()));
    newPiece.setPosition(head1->getPosition() + direction);

    head1 = body1.insert(++head1, newPiece);

    //To increase snake1 score.
    score1 += 1;
    score[0].setString("Score1: " + to_string(score1));

    //Play eating voice.
    if (!eating.openFromFile("static\\eating.ogg")) {
        cout << "Error loading music file" << endl;
    }
    eating.setVolume(50);
    eating.play();
}

//To grow snake2.
void Snakes::grow2(const sf::Vector2f &direction) {
    sf::Sprite newPiece;
    newPiece.setTexture(*(body2.begin()->getTexture()));
    newPiece.setPosition(head2->getPosition() + direction);

    head2 = body2.insert(++head2, newPiece);

    //To increase snake2 score.
    score2 += 1;
    score[1].setString("Score2: " + to_string(score2));

    //Play eating voice.
    if (!eating.openFromFile("static\\eating.ogg")) {
        cout << "Error loading music file" << endl;
    }
    eating.setVolume(200);
    eating.play();
}

//Death by hit himself.
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

//Death by snakes colliding with each other.
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

//Death due to snake1 hitting the wall.
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

//Death due to snake2 hitting the wall.
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

//To draw snakes, walls and scores.
void Snakes::draw(sf::RenderTarget &target, sf::RenderStates states) const {

    //Draw snake1
    for (auto &piece1: body1) {
        target.draw(piece1);
    }

    //Draw snake2
    for (auto &piece2: body2) {
        target.draw(piece2);
    }

    //Draw wall1
    for (auto &piece1: wall1) {
        target.draw(piece1);
    }

    //Draw wall2
    for (auto &piece2: wall2) {
        target.draw(piece2);
    }

    //Draw scores
    for (int i = 0; i < 2; ++i) {
        target.draw(score[i]);
    }
}