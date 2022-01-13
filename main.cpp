//Snake Game with SFML
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Menu.h"
#include "Option.h"

using namespace std;

int main() {

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    //Build game page.
    sf::RenderWindow window(sf::VideoMode(800, 600), "Snake Game",
                            sf::Style::Default, settings);

    //Create "Menu class" for the game menu.
    Menu menu(800, 600);

    //Create "Option class" for the game options.
    Option option(800, 600);

    //For play music
    sf::Music music;
    if (!music.openFromFile("music.ogg")) {
        cout << "Error loading file" << endl;
    }
    music.setVolume(100);
    music.play();
    music.setLoop(true);

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
                            switch (menu.getPressedItem()) {

                                //Play the game.
                                case 1: {
                                    std::cout << "Play button has been pressed" << std::endl;
                                    while (window.isOpen()) {
                                        sf::Event event{};
                                        while (window.pollEvent(event)) {
                                            switch (event.type) {
                                                case sf::Event::Closed:
                                                    window.close();
                                                    break;
                                                default:
                                                    break;
                                            }
                                        }
                                        window.clear();
                                        window.display();
                                    }
                                }
                                    break;

                                    //Go to options page.
                                case 2: {
                                    std::cout << "Option button has been pressed" << std::endl;

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
                                                                    std::cout << "Mute button has been pressed"
                                                                              << std::endl;
                                                                    music.stop();
                                                                }
                                                                    break;
                                                                case 2: {
                                                                    std::cout << "Unmute button has been pressed"
                                                                              << std::endl;
                                                                    music.play();
                                                                    music.setLoop(true);
                                                                }
                                                                    break;

                                                                    //Speed setting.
                                                                case 3:
                                                                    std::cout << "Fast button has been pressed"
                                                                              << std::endl;
                                                                    break;
                                                                case 4:
                                                                    std::cout << "Slow button has been pressed"
                                                                              << std::endl;
                                                                    break;

                                                                    //Back to menu.
                                                                case 5: {
                                                                    std::cout << "Back button has been pressed"
                                                                              << std::endl;
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
                                }
                                Back:
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
    return 0;
}

