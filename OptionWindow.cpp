#include "OptionWindow.h"

OptionWindow::OptionWindow() {

}

OptionWindow::~OptionWindow() {

}

double OptionWindow::draw(sf::RenderWindow &window, sf::Music &music) {

    //Create "Option class" for the game options.
    Option option(800, 600);

    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::KeyReleased:
                    switch (event.key.code) {
                        //To move up in the options.
                        case sf::Keyboard::Up:
                            option.moveUp();
                            break;

                            //To move down in the options.
                        case sf::Keyboard::Down:
                            option.moveDown();
                            break;

                            //To click on options.
                        case sf::Keyboard::Return:
                            switch (option.getPressedOption()) {

                                //Sound setting.
                                case 1: {
                                    std::cout << "Mute button has been pressed" << std::endl;
                                    music.stop();
                                }
                                    break;
                                case 2: {
                                    std::cout << "Unmute button has been pressed" << std::endl;
                                    music.play();
                                    music.setLoop(true);
                                }
                                    break;

                                    //Speed setting.
                                case 3: {
                                    std::cout << "Fast button has been pressed" << std::endl;
                                    double speed=0.05;
                                    return speed;
                                }
                                case 4: {
                                    std::cout << "Slow button has been pressed" << std::endl;
                                    double speed=0.1;
                                    return speed;
                                }

                                    //Back to menu.
                                case 5: {
                                    std::cout << "Back button has been pressed" << std::endl;
                                    goto Back;
                                }
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
        window.clear(sf::Color(0, 70, 100));
        option.draw(window);
        window.display();
    }
    Back:;
}