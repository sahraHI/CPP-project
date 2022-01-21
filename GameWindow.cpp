#include "GameWindow.h"

GameWindow::GameWindow(double newSpeed) : snake1Direction({20, 0}),
                                          snake2Direction({0, 20}), Time(sf::Time::Zero) {
    speed = newSpeed;  //Selected speed.
}

GameWindow::~GameWindow() {

}

//To draw Game window page.
void GameWindow::draw(sf::RenderWindow &window) {

    //Play game over music.
    sf::Music game_over;
    if (!game_over.openFromFile("static\\game_over.ogg")) {
        cout << "Error loading music file" << endl;
    }
    game_over.setVolume(200);
//    game_over.play();

    //Create "Game class"
    Game game;

    //Create "Snakes class"
    Snakes snakes;

    //Create "GameOver class"
    GameOver gameOver(800, 600);

    //Create "GameOverWindow class"
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

                        //To snake1 move up .
                        case sf::Keyboard::Up:
                            newDirection1 = {0, -20};
                            break;

                            //To snake1 move down .
                        case sf::Keyboard::Down:
                            newDirection1 = {0, 20};
                            break;

                            //To snake1 move left.
                        case sf::Keyboard::Left:
                            newDirection1 = {-20, 0};
                            break;

                            //To snake1 move right.
                        case sf::Keyboard::Right:
                            newDirection1 = {20, 0};
                            break;

                            //To snake2 move up .
                        case sf::Keyboard::W:
                            newDirection2 = {0, -20};
                            break;

                            //To snake2 move down .
                        case sf::Keyboard::S:
                            newDirection2 = {0, 20};
                            break;

                            //To snake2 move left .
                        case sf::Keyboard::A:
                            newDirection2 = {-20, 0};
                            break;

                            //To snake2 move right.
                        case sf::Keyboard::D:
                            newDirection2 = {20, 0};
                            break;

                            //To pause game.
                        case sf::Keyboard::Space: {
                            cout << "Pause button has been pressed" << endl;

                            PauseGame pauseGame;
                            pauseGame.drawPaus(window);
                        }
                            break;

                            //To close the window.
                        case sf::Keyboard::Escape:
                            window.close();
                            break;

                        default:
                            break;
                    }
                    if (abs(snake1Direction.x) != abs(newDirection1.x) ||
                        abs(snake1Direction.y) != abs(newDirection1.y)) {
                        snake1Direction = newDirection1;
                    }
                    if (abs(snake2Direction.x) != abs(newDirection2.x) ||
                        abs(snake2Direction.y) != abs(newDirection2.y)) {
                        snake2Direction = newDirection2;
                    }
                }
                    break;

                    //To close the window.
                case sf::Event::Closed:
                    window.close();
                    break;
                default:
                    break;
            }
        }

        Time += clock.restart();
        //To adjust the speed of snakes
        if (Time.asSeconds() > speed) {

            snakes.move1(snake1Direction);
            snakes.move2(snake2Direction);

            //To grow snake1.
            if (snakes.isOn1(game.food1Sprite)) {
                snakes.grow1(snake1Direction);
                game.updateFood1();
            } else if (snakes.isOn1(game.food2Sprite)) {
                snakes.grow1(snake1Direction);
                game.updateFood2();
            }

            //To grow snake2.
            if (snakes.isOn2(game.food1Sprite)) {
                snakes.grow2(snake2Direction);
                game.updateFood1();
            } else if (snakes.isOn2(game.food2Sprite)) {
                snakes.grow2(snake2Direction);
                game.updateFood2();
            }

            //To game over.
            if (snakes.isSelfIntersecting()) {
                game_over.play();
                gameOverWindow.draw(window);
            } else if (snakes.collisionOfSnakes()) {
                game_over.play();
                gameOverWindow.draw(window);
            } else if (snakes.snakeHitWall1()) {
                game_over.play();
                gameOverWindow.draw(window);
            } else if (snakes.snakeHitWall2()) {
                game_over.play();
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