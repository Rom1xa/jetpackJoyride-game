#include "Menu.h"
#include <iostream>

Menu::Menu(float width, float height) {
  if (!font.loadFromFile("static/fonts/Roboto-Bold.ttf")) {
    std::cerr << "error loading font" << std::endl;
  }

  // Start game option
  menuItems[0].setFont(font);
  menuItems[0].setFillColor(sf::Color::Red);
  menuItems[0].setString("Start Game");
  menuItems[0].setPosition(sf::Vector2f(width / 2 - 50, height / 2 - 50));

  // Exit option
  menuItems[1].setFont(font);
  menuItems[1].setFillColor(sf::Color::White);
  menuItems[1].setString("Exit");
  menuItems[1].setPosition(sf::Vector2f(width / 2 - 50, height / 2));

  // TODO: maybe add settings option

  selectedOptionIndex = 0;
}

Menu::~Menu() {}

void Menu::draw(sf::RenderWindow &window) {
  for (int i = 0; i < MAX_MENU_ITEMS; i++) {
    window.draw(menuItems[i]);
  }
}

void Menu::moveUp() {
  if (selectedOptionIndex - 1 >= 0) {
    menuItems[selectedOptionIndex].setFillColor(sf::Color::White);
    selectedOptionIndex--;
    menuItems[selectedOptionIndex].setFillColor(sf::Color::Red);
  }
}

void Menu::moveDown() {
  if (selectedOptionIndex + 1 < MAX_MENU_ITEMS) {
    menuItems[selectedOptionIndex].setFillColor(sf::Color::White);
    selectedOptionIndex++;
    menuItems[selectedOptionIndex].setFillColor(sf::Color::Red);
  }
}
