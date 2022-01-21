#include "OptionWindow.h"

OptionWindow::OptionWindow() {

}

OptionWindow::~OptionWindow() {

}

double OptionWindow::draw(sf::RenderWindow &window, sf::Music &music) {

    //Create "Option class" .
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

                            //To close the window.
                        case sf::Keyboard::Escape:
                            window.close();
                            break;

                            //To click on options.
                        case sf::Keyboard::Return:
                            switch (option.getPressedOption()) {

                                //Sound setting.
                                case 1: {
                                    cout << "Mute button has been pressed" << endl;
                                    music.stop();
                                }
                                    break;
                                case 2: {
                                    cout << "Unmute button has been pressed" << endl;
                                    music.play();
                                    music.setLoop(true);
                                }
                                    break;

                                    //Speed setting.
                                case 3: {
                                    cout << "Fast button has been pressed" << endl;
                                    double speed = 0.05;
                                    return speed;
                                }

                                case 4: {
                                    cout << "Slow button has been pressed" << endl;
                                    double speed = 0.1;
                                    return speed;
                                }

                                    //Back to menu.
                                case 5: {
                                    cout << "Back button has been pressed" << endl;
                                    goto Back;
                                }
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
        window.clear(sf::Color(0, 70, 100));
        option.draw(window);
        window.display();
    }
    Back:;
}