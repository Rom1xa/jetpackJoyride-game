#pragma once

#include <SFML/Graphics.hpp>

#define MAX_MENU_ITEMS 2

class Menu {
public:
  Menu(float width, float height);
  ~Menu();

  void draw(sf::RenderWindow &window);
  void moveUp();
  void moveDown();
  int getSelectedOption() const { return selectedOptionIndex; }

private:
  int selectedOptionIndex;
  sf::Font font;
  sf::Text menuItems[MAX_MENU_ITEMS];
};
