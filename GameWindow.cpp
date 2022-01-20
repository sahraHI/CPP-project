#include "GameWindow.h"

GameWindow::GameWindow(double newSpeed) : snake1Direction({20, 0}), snake2Direction({0, 20}), Time(sf::Time::Zero) {
    speed = newSpeed;
}

GameWindow::~GameWindow() {

}

void GameWindow::draw(sf::RenderWindow &window) {

    Game game;

    Snakes snakes;

    GameOver gameOver(800, 600);

    GameOverWindow gameOverWindow(speed);

    sf::Clock clock;

    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::KeyReleased: {
                    sf::Vector2f newDirection1 = snake1Direction;
                    sf::Vector2f newDirection2 = snake2Direction;
                    switch (event.key.code) {
                        case sf::Keyboard::Up:
                            newDirection1 = {0, -20};
                            break;

                        case sf::Keyboard::Down:
                            newDirection1 = {0, 20};
                            break;

                        case sf::Keyboard::Left:
                            newDirection1 = {-20, 0};
                            break;

                        case sf::Keyboard::Right:
                            newDirection1 = {20, 0};
                            break;
                        case sf::Keyboard::W:
                            newDirection2 = {0, -20};
                            break;

                        case sf::Keyboard::S:
                            newDirection2 = {0, 20};
                            break;

                        case sf::Keyboard::A:
                            newDirection2 = {-20, 0};
                            break;

                        case sf::Keyboard::D:
                            newDirection2 = {20, 0};
                            break;
                        case sf::Keyboard::Space: {
                            PauseGame pauseGame;
                            pauseGame.drawPaus(window);
                        }
                            break;
                        default:
                            break;
                    }
                    if (std::abs(snake1Direction.x) != std::abs(newDirection1.x) ||
                        std::abs(snake1Direction.y) != std::abs(newDirection1.y)) {
                        snake1Direction = newDirection1;
                    }
                    if (std::abs(snake2Direction.x) != std::abs(newDirection2.x) ||
                        std::abs(snake2Direction.y) != std::abs(newDirection2.y)) {
                        snake2Direction = newDirection2;
                    }
                }
                    break;

                case sf::Event::Closed:
                    window.close();
                    break;
                default:
                    break;
            }
        }
        Time += clock.restart();
        if (Time.asSeconds() > speed) {

            snakes.move1(snake1Direction);
            snakes.move2(snake2Direction);

            if (snakes.isOn1(game.food1Sprite)) {
                snakes.grow1(snake1Direction);
                game.updateFood1();
            } else if (snakes.isOn1(game.food2Sprite)) {
                snakes.grow1(snake1Direction);
                game.updateFood2();
            } else if (snakes.snakeHitWall1()) {
                gameOverWindow.draw(window);
            }

            if (snakes.isOn2(game.food1Sprite)) {
                snakes.grow2(snake2Direction);
                game.updateFood1();
            } else if (snakes.isOn2(game.food2Sprite)) {
                snakes.grow2(snake2Direction);
                game.updateFood2();
            } else if (snakes.snakeHitWall2()) {
                gameOverWindow.draw(window);
            }

            if (snakes.isSelfIntersecting()) {
                gameOverWindow.draw(window);
            } else if (snakes.collisionOfSnakes()) {
                gameOverWindow.draw(window);
            }

            Time = sf::Time::Zero;
        }
        window.clear();
        game.draw(window);
        window.draw(snakes);
        window.display();
    }
}