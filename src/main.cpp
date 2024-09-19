#include "Player.h"
#include <SFML/Graphics.hpp>

using namespace sf;
int main() {
  RenderWindow window(VideoMode(800, 600), "Jetpack Joyride Clone");
  Player player;

  Clock clock;

  while (window.isOpen()) {
    Event event;
    while (window.pollEvent(event)) {
      if (event.type == Event::Closed)
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
