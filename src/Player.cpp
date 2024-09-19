#include "Player.h"
#include <SFML/Window/Keyboard.hpp>
#include <iostream>

Player::Player()
    : frameWidth(135), frameHeight(130), currentFrame(0), frameDuration(0.1f),
      animationTimer(0.0f), totalFrames(4) {
  if (!texture.loadFromFile("static/BarryFullSpriteSheet.png")) {
    std::cerr << "Error loading player texture" << std::endl;

    sf::RectangleShape placeholder(sf::Vector2f(frameWidth, frameHeight));
    placeholder.setFillColor(sf::Color::Red);

  } else {
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0, 0, frameWidth, frameHeight));
  }

  sprite.setPosition(100, 300); // start pos
  velocity = sf::Vector2f(0, 0);
}

void Player::handleInput() {
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(sf::Keyboard::U))) {
    // activate jetpack
    velocity.y = jetpackPower;
  }
}

void Player::update(float deltaTime, const sf::RenderWindow &window) {
  //  gravity
  velocity.y += gravity * deltaTime;

  // limit fall speed
  if (velocity.y > maxFallSpeed)
    velocity.y = maxFallSpeed;

  // update player pos
  sprite.move(0, velocity.y * deltaTime);

  // animation
  animationTimer += deltaTime;
  if (animationTimer >= frameDuration) {
    currentFrame = (currentFrame + 1) % totalFrames;
    sprite.setTextureRect(
        sf::IntRect(currentFrame * frameWidth, 0, frameWidth, frameHeight));
    animationTimer = 0.0f;
  }

  // window boundaries
  if (sprite.getPosition().y < 0) {
    sprite.setPosition(sprite.getPosition().x, 0); // top
    velocity.y = 0;
  }

  if (sprite.getPosition().y + sprite.getGlobalBounds().height >
      window.getSize().y) {
    sprite.setPosition(sprite.getPosition().x,
                       window.getSize().y -
                           sprite.getGlobalBounds().height); // bottom
    velocity.y = 0;
  }
}

void Player::draw(sf::RenderWindow &window) { window.draw(sprite); }
