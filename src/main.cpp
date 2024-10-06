#include "Background.h"
#include "Menu.h"
#include "Player.h"
#include <SFML/Graphics.hpp>

// TODO: maybe add settings option
enum GameState {
  MENU,
  PLAYING,
  EXIT,
};

using namespace sf;

int main() {
  RenderWindow window(VideoMode(800, 600), "Jetpack Joyride Clone");

  // entities
  Player player;
  Background background(200.0f, "static/notpixel.png");

  // states
  GameState gameState = MENU;
  Menu menu(window.getSize().x, window.getSize().y);

  Clock clock;

  while (window.isOpen()) {
    Event event;
    while (window.pollEvent(event)) {
      if (event.type == Event::Closed)
        window.close();

      if (gameState == MENU) {
        // menu input handling
        if (event.type == Event::KeyPressed) {
          if (event.key.code == Keyboard::Up) {
            menu.moveUp();
          }
          if (event.key.code == Keyboard::Down) {
            menu.moveDown();
          }
          if (event.key.code == Keyboard::Enter) {
            int selectedOption = menu.getSelectedOption();
            if (selectedOption == 0) {
              gameState = PLAYING; // start
            } else if (selectedOption == 1) {
              window.close(); // exit
            }
          }
        }
      }
    }

    float deltaTime = clock.restart().asSeconds();

    if (gameState == PLAYING) {
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

      // if escape key is pressed return menu
      if (Keyboard::isKeyPressed(Keyboard::M)) {
        gameState = MENU;
      }
    } else if (gameState == MENU) {
      // render menu
      window.clear();
      menu.draw(window);
      window.display();
    }
  }

  return 0;
}
