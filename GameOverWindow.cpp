#include "GameOverWindow.h"

GameOverWindow::GameOverWindow(double newSpeed) {
    speed = newSpeed;
}

GameOverWindow::~GameOverWindow() {

}

void GameOverWindow::draw(sf::RenderWindow &window) {

    GameWindow gameWindow(speed);

    GameOver gameOver(800, 600);
    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::KeyReleased:
                    switch (event.key.code) {
                        //To move up in the options.
                        case sf::Keyboard::Up:
                            gameOver.moveUp();
                            break;

                            //To move down in the options.
                        case sf::Keyboard::Down:
                            gameOver.moveDown();
                            break;

                        case sf::Keyboard::Return:
                            switch (gameOver.getPressedButton()) {

                                case 1: {
                                    std::cout << "Restart button has been pressed" << std::endl;
                                    gameWindow.draw(window);
                                }
                                    break;
                                case 2: {
                                    std::cout << "Exit button has been pressed" << std::endl;
                                    window.close();
                                }
                                    break;
                            }
                            break;
                    }
                    break;
                case sf::Event::Closed:
                    window.close();
                    break;
                default:
                    break;
            }
        }
        window.clear();
        gameOver.draw(window);
        window.display();
    }
}