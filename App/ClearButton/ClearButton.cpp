#include "ClearButton.hpp"

#include "../Window.hpp"

ClearButton::ClearButton() {
    if (!font_.loadFromFile("../WindowFiles/Kanok.ttf")) {
        throw std::runtime_error("Font could not be found");
    }

    text_.setFont(font_);
    text_.setCharacterSize(3 * kCharacterSize);
    text_.setString("Clear");
    text_.setFillColor(sf::Color::Magenta);

    sf::FloatRect textBound{text_.getGlobalBounds()};
    text_.setOrigin(textBound.width / 2, textBound.height / 2);
    text_.setPosition(2 * (kDistance + kFieldSize) + kFieldSize / 2, kTurnWindowHeight / 2 - 2 * kDistance - kDistance / 2);

    shape_.setSize(sf::Vector2f(kFieldSize, kTurnWindowHeight));
    shape_.setFillColor(sf::Color(kClearButtonRed, kClearButtonGreen, kClearButtonBlue));

    shape_.setPosition(2 * (kDistance + kFieldSize), -kDistance);
}

void ClearButton::DrawButton(sf::RenderWindow& window) const {
    window.draw(shape_);
    window.draw(text_);
}

bool ClearButton::MouseClicked(sf::Vector2f& mousePosition) const {
    return shape_.getGlobalBounds().contains(mousePosition);
}
