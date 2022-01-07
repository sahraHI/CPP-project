//Snake Game with SFML
#include <SFML/Graphics.hpp>
#include "Menu.h"

using namespace std;

int main() {
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(800, 600), "Snake Game", sf::Style::Default, settings);

    Menu menu(800, 600);

    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::KeyReleased:
                    switch (event.key.code) {
                        case sf::Keyboard::Up:
                            menu.moveUp();
                            break;
                        case sf::Keyboard::Down:
                            menu.moveDown();
                            break;
                        case sf::Keyboard::Return:
                            switch (menu.getPressedItem()) {
                                case 1:
                                    std::cout << "Play button has been pressed" << std::endl;
                                    break;
                                case 2:
                                    std::cout << "Option button has been pressed" << std::endl;
                                    break;
                                case 3:
                                    window.close();
                                    break;

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

        window.clear();
        menu.draw(window);
        window.display();
    }

    return 0;
}

