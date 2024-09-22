#pragma once

#include <SFML/Graphics.hpp>

class Background {
public:
  Background(float scrollSpeed, const std::string &textureFile);
  void update(float deltaTime);
  void draw(sf::RenderWindow &window);

private:
  sf::Texture texture;
  sf::Sprite sprite1, sprite2;
  float scrollSpeed;
};
