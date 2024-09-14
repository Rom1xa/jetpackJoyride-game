#include "Player.h"
#include <SFML/Window/Keyboard.hpp>
#include <iostream>

Player::Player() {
  if (!texture.loadFromFile("static/player.png")) {
    std::cerr << "Error loading player texture" << std::endl;

    sf::RectangleShape placeholder(sf::Vector2f(50.0f, 100.0f));
    placeholder.setFillColor(sf::Color::Red);

  } else {
    sprite.setTexture(texture);
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
  // apply gravity
  velocity.y += gravity * deltaTime;

  // limit fall speed
  if (velocity.y > maxFallSpeed)
    velocity.y = maxFallSpeed;

  // window boundaries
  if (sprite.getPosition().y < 0) {
    sprite.setPosition(sprite.getPosition().x, 0);
    velocity.y = 0;
  }
  if (sprite.getPosition().y + sprite.getGlobalBounds().height >
      window.getSize().y) {
    sprite.setPosition(sprite.getPosition().x,
                       window.getSize().y - sprite.getGlobalBounds().height);
    velocity.y = 0;
  }

  // update player position
  sprite.move(0, velocity.y * deltaTime);
}

void Player::draw(sf::RenderWindow &window) { window.draw(sprite); }
