#pragma once

#include <SFML/Graphics.hpp>

class TurnWindow {
 private:
    sf::Text turn_;
    sf::Text win_;
    sf::Font font_;

    sf::RectangleShape shape_;

 public:
    TurnWindow();

    void UpdateTurn(const short turnNumber);
    void DrawCurrentTurn(sf::RenderWindow& window) const;

    void UpdateWinner(sf::RenderWindow& window, std::string winner);

    void Clear();
};
