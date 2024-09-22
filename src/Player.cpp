#include "Player.h"
#include <SFML/Window/Keyboard.hpp>
#include <iostream>

Player::Player()
    : frameWidth(135), frameHeight(130), currentFrame(0), frameDuration(0.1f),
      animationTimer(0.0f), totalFrames(4), isOnGround(true),
      ceilingLimit(100) {
  if (!texture.loadFromFile("static/BarryFullSpriteSheet.png")) {
    std::cerr << "Error loading player texture" << std::endl;
  } else {
    sprite.setTexture(texture);
    sprite.setTextureRect(
        sf::IntRect(0, 0, frameWidth, frameHeight)); // initial frame
  }

  sprite.setPosition(100, 500); // start pos
  velocity = sf::Vector2f(0, 0);
}

void Player::handleInput() {
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(sf::Keyboard::U))) {
    // activate jetpack
    if (sprite.getPosition().y > ceilingLimit) {
      velocity.y = jetpackPower;
      isOnGround = false;
    }
  }
}

void Player::update(float deltaTime, const sf::RenderWindow &window) {
  // apply gravity only when not on ground
  if (!isOnGround) {
    //  gravity
    velocity.y += gravity * deltaTime;

    // limit fall speed
    if (velocity.y > maxFallSpeed)
      velocity.y = maxFallSpeed;
  }

  // update player pos
  sprite.move(0, velocity.y * deltaTime);

  // is on the floor
  if (sprite.getPosition().y + sprite.getGlobalBounds().height >=
      window.getSize().y - 50) {
    sprite.setPosition(sprite.getPosition().x,
                       window.getSize().y - sprite.getGlobalBounds().height -
                           50);
    isOnGround = true;
    velocity.y = 0; // stop falling
  }
  // hit the ceiling
  else if (sprite.getPosition().y <= ceilingLimit) {
    sprite.setPosition(sprite.getPosition().x,
                       ceilingLimit); // snap to the ceiling
    velocity.y = 0;
  } else {
    isOnGround = false;
  }

  updateAnimation(deltaTime);
}

void Player::updateAnimation(float deltaTime) {
  animationTimer += deltaTime;
  if (animationTimer >= frameDuration) {
    if (isOnGround) {
      currentFrame = (currentFrame + 1) % 4;
      sprite.setTextureRect(
          sf::IntRect(currentFrame * frameWidth, 0, frameWidth, frameHeight));
    } else {
      currentFrame = (currentFrame + 1) % 4;
      sprite.setTextureRect(sf::IntRect(currentFrame * frameWidth, frameHeight,
                                        frameWidth, frameHeight));
    }
    animationTimer = 0.0f; // reset timer
  }
}

void Player::draw(sf::RenderWindow &window) { window.draw(sprite); }
