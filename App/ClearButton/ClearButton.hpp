#pragma once

#include <SFML/Graphics.hpp>

class ClearButton {
 private:
    sf::Text text_;
    sf::Font font_;

    sf::RectangleShape shape_;

 public:
    ClearButton();
    void DrawButton(sf::RenderWindow& window) const;

    bool MouseClicked(sf::Vector2f& mousePosition) const;
};
