#include "Window.h"

Window::Window() {
    srand(time(nullptr));

    double speed = 0.1;

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    //Build game page.
    sf::RenderWindow window(sf::VideoMode(800, 600), "Snake Game",
                            sf::Style::Default, settings);

    //Create "Menu class" for the game menu.
    Menu menu(800, 600);


    //For play music
    sf::Music music;
    if (!music.openFromFile("music.ogg")) {
        cout << "Error loading file" << endl;
    }
    music.setVolume(60);
    music.play();
    music.setLoop(true);

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

                            //To click on items.
                        case sf::Keyboard::Return:

                            GameWindow gameWindow(speed);

                            switch (menu.getPressedItem()) {
                                //Play the game.
                                case 1: {
                                    std::cout << "Play button has been pressed" << std::endl;

                                    gameWindow.draw(window);

                                }
                                    break;

                                    //Go to options page.
                                case 2: {
                                    std::cout << "Option button has been pressed" << std::endl;

                                    speed = optionWindow.draw(window, music);


                                }
                                    break;

                                    //Exit the game.
                                case 3:
                                    window.close();
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
        window.clear(sf::Color(70, 0, 70));
        menu.draw(window);
        window.display();

    }
}

Window::~Window() {

}
