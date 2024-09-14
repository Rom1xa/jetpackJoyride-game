#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>

class Player {
public:
  Player();

  void update(float deltaTime, const sf::RenderWindow &window);
  void handleInput();
  void draw(sf::RenderWindow &window);

private:
  sf::Texture texture;
  sf::Sprite sprite;

  sf::Vector2f velocity;
  const float gravity = 980.0f;       // Gravity constant (pixels per second^2)
  const float jetpackPower = -500.0f; // Jetpack power (upward force)
  const float maxFallSpeed = 600.0f;  // Maximum falling speed
};

#endif
