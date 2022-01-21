#include "GameOverWindow.h"

GameOverWindow::GameOverWindow(double newSpeed) {
    //Set speed after restart game.
    speed = newSpeed;
}

GameOverWindow::~GameOverWindow() {

}

void GameOverWindow::draw(sf::RenderWindow &window) {

    //create "GameWindow class"
    GameWindow gameWindow(speed);

    //create "GameOver class"
    GameOver gameOver(800, 600);

    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::KeyReleased:
                    switch (event.key.code) {

                        //To move up in the items.
                        case sf::Keyboard::Up:
                            gameOver.moveUp();
                            break;

                            //To move down in the items.
                        case sf::Keyboard::Down:
                            gameOver.moveDown();
                            break;

                            //To close the window.
                        case sf::Keyboard::Escape:
                            window.close();
                            break;

                        case sf::Keyboard::Return:
                            switch (gameOver.getPressedButton()) {

                                //Play again
                                case 1: {
                                    cout << "Restart button has been pressed" << endl;
                                    gameWindow.draw(window);
                                }
                                    break;

                                    //To close the window.
                                case 2: {
                                    cout << "Exit button has been pressed" << endl;
                                    window.close();
                                }
                                    break;
                            }
                            break;
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
        window.clear();
        gameOver.draw(window);
        window.display();
    }
}