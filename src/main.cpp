#include "Player.h"
#include <SFML/Graphics.hpp>

int main() {
  sf::RenderWindow window(sf::VideoMode(800, 600), "Jetpack Joyride Clone");
  Player player;

  sf::Clock clock;

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();
    }

    float deltaTime = clock.restart().asSeconds();

    // handle input and update player
    player.handleInput();
    player.update(deltaTime, window);

    // render game
    window.clear();
    player.draw(window);
    window.display();
  }

  return 0;
}
