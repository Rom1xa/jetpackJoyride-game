#include "Background.h"
#include "Player.h"
#include <SFML/Graphics.hpp>

using namespace sf;
int main() {
  RenderWindow window(VideoMode(800, 600), "Jetpack Joyride Clone");

  Player player;
  Background background(200.0f, "static/background.jpg");

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

    // update background
    background.update(deltaTime);

    // render game
    window.clear();
    background.draw(window);
    player.draw(window);
    window.display();
  }

  return 0;
}
