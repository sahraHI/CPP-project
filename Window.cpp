#include "Window.h"

Window::Window() : snake1Direction({20, 0}),snake2Direction({0, 20}), Time(sf::Time::Zero) {
    srand(time(nullptr));

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    //Build game page.
    sf::RenderWindow window(sf::VideoMode(800, 600), "Snake Game",
                            sf::Style::Default, settings);

    //Create "Menu class" for the game menu.
    Menu menu(800, 600);

    //Create "Option class" for the game options.
    Option option(800, 600);

    //Create "Game class" for game page.
    Game game;

    Snakes snakes;

    //For play music
    sf::Music music;
    if (!music.openFromFile("music.ogg")) {
        cout << "Error loading file" << endl;
    }
    music.setVolume(100);
    music.play();
    music.setLoop(true);

    sf::Clock clock;

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
                            switch (menu.getPressedItem()) {

                                //Play the game.
                                case 1: {
                                    std::cout << "Play button has been pressed" << std::endl;

                                    while (window.isOpen()) {
                                        sf::Event event{};
                                        while (window.pollEvent(event)) {
                                            switch (event.type) {
                                                case sf::Event::KeyReleased:
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
                                                    //                                                case sf::Event::Closed:
//                                                    window.close();
//                                                    break;
//                                                default:
//                                                    break;
                                            }
                                        }
                                        Time += clock.restart();
                                        if (Time.asSeconds() > 0.1) {

//                                            bool isOnWall = false;
//                                            for (auto &wall : m_walls)
//                                            {
//                                                if (snakes.isOn(game.wallSprite))
//                                                {
//                                                    // go to game over
//                                                    break;
//                                                }
//                                            }
                                            snakes.move1(snake1Direction);
                                            if (snakes.isOn1(game.food1Sprite)) {
                                                snakes.grow1(snake1Direction);
                                                game.updateFood1();
                                            }
                                            else if(snakes.isOn1(game.food2Sprite)){
                                                snakes.grow1(snake1Direction);
                                                game.updateFood2();
                                            }
                                            snakes.move2(snake2Direction);
                                            if (snakes.isOn2(game.food1Sprite)) {
                                                snakes.grow2(snake2Direction);
                                                game.updateFood1();
                                            }
                                            else if(snakes.isOn2(game.food2Sprite)){
                                                snakes.grow2(snake2Direction);
                                                game.updateFood2();
                                            }
                                            Time = sf::Time::Zero;
                                        }
                                        window.clear();
                                        game.draw(window);
                                        window.draw(snakes);
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
}

Window::~Window() {

}