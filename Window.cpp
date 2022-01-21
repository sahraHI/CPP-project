#include "Window.h"

Window::Window() {

    double speed = 0.1;   //Default speed

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    //Build game page.
    sf::RenderWindow window(sf::VideoMode(800, 600), "Snake Game",
                            sf::Style::Default, settings);

    //Create "Menu class" for the game menu.
    Menu menu(800, 600);

    //Play music
    sf::Music music;
    if (!music.openFromFile("static\\music.ogg")) {
        cout << "Error loading music file" << endl;
    }
    music.setVolume(60);
    music.play();
    music.setLoop(true);

    //Crete Option page
    OptionWindow optionWindow;

    // run the program as long as the window is open.
    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::KeyReleased:
                    switch (event.key.code) {

                        //To move up in the menu.
                        case sf::Keyboard::Up:
                            menu.moveUp();
                            break;

                            //To move down in the menu.
                        case sf::Keyboard::Down:
                            menu.moveDown();
                            break;

                            //To close the window.
                        case sf::Keyboard::Escape:
                            window.close();
                            break;

                            //To click on items.
                        case sf::Keyboard::Return:

                            //Crete Game page.
                            GameWindow gameWindow(speed);

                            switch (menu.getPressedItem()) {

                                //Play the game.
                                case 1: {
                                    cout << "Play button has been pressed" << endl;

                                    //To display the game screen.
                                    gameWindow.draw(window);
                                }
                                    break;

                                    //Go to options page.
                                case 2: {
                                    cout << "Option button has been pressed" << endl;

                                    //To display the option screen.
                                    speed = optionWindow.draw(window, music);
                                }
                                    break;

                                    //Exit the game.
                                case 3: {
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
        menu.draw(window);
        window.display();
    }
}

Window::~Window() {

}
