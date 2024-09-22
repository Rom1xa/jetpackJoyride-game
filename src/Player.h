#pragma once

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
  bool isOnGround;

  // animation properties
  int frameWidth;       // width of a single frame in the spritesheet
  int frameHeight;      // height of a single frame
  int currentFrame;     // the current frame
  float frameDuration;  // how long each frame lasts
  float animationTimer; // timer to control frame switching
  int totalFrames;      // total number of frames
  int ceilingLimit;

  void updateAnimation(float deltaTime);
};
