#include "PauseGame.h"

PauseGame::PauseGame() {

    if (!font.loadFromFile("static\\calibri.ttf")) {
        cout << "Error loading font file" << endl;
    }

    //Change  Pause text features.
    pause.setFont(font);
    pause.setFillColor(sf::Color::White);
    pause.setString("Pause");
    pause.setCharacterSize(50);
    pause.setPosition(sf::Vector2f((800 / 2) - 60, (600 / 2) - 50));
}

PauseGame::~PauseGame() {

}

//To draw Pause
void PauseGame::drawPaus(sf::RenderWindow &window) {
    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::KeyReleased:
                    switch (event.key.code) {

                        //To Pause game.
                        case sf::Keyboard::Space:
                            goto unPause;

                            //To close the window.
                        case sf::Keyboard::Escape:
                            window.close();
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
        window.draw(pause);
        window.display();
    }
    unPause:;
}