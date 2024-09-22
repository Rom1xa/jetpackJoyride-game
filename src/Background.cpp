#include "Background.h"
#include <iostream>

Background::Background(float scrollSpeed, const std::string &textureFile)
    : scrollSpeed(scrollSpeed) {
  if (!texture.loadFromFile(textureFile)) {
    std::cerr << "error loading texture " << textureFile << std::endl;
  }

  sprite1.setTexture(texture);
  sprite2.setTexture(texture);

  sprite1.setPosition(0, 0);
  sprite2.setPosition(sprite1.getGlobalBounds().width, 0);
}

void Background::update(float deltaTime) {
  // move sprites to left
  sprite1.move(-scrollSpeed * deltaTime, 0);
  sprite2.move(-scrollSpeed * deltaTime, 0);

  // if moves off screen then reposition to the right
  if (sprite1.getPosition().x + sprite1.getGlobalBounds().width < 0) {
    sprite1.setPosition(
        sprite2.getPosition().x + sprite2.getGlobalBounds().width, 0.0f);
  }
  if (sprite2.getPosition().x + sprite2.getGlobalBounds().width < 0) {
    sprite2.setPosition(
        sprite1.getPosition().x + sprite1.getGlobalBounds().width, 0.0f);
  }
}

void Background::draw(sf::RenderWindow &window) {
  window.draw(sprite1);
  window.draw(sprite2);
}
