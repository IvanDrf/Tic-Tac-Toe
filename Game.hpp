#pragma once

#include <SFML/Graphics.hpp>

namespace {  // Window Size
const uint kDesktopWidth{sf::VideoMode::getDesktopMode().width};

const uint kWindowWidth{static_cast<uint>(kDesktopWidth * 0.35)};
const uint kWindowHeight{static_cast<uint>(kDesktopWidth * 0.43)};

const float kFieldSize{(kWindowWidth - 10.f) / 3};
const short kFieldAmount{9};
const short kDistance{5};
const short kCharacterSize{20};
}  // namespace

namespace {  // Turn
const float kTurnWindowHeight{kWindowHeight - 3 * (kFieldSize + kDistance) - kDistance};
const float kTurnWindowWidth{2 * kWindowWidth / 3};

const short kMinTurnForWin{5};
const short kMaxTurn{10};
}

namespace {  // RGB Colors
const short kDefaultRed{59};
const short kDefaultGreen{59};
const short kDefaultBlue{59};
}  // namespace

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

class Field {
 private:
    sf::Text value_;
    sf::Font font_;

    sf::RectangleShape shape_;
    sf::Color oldColor_;

    sf::Clock time_;
    bool clicking_;

 public:
    Field();
    static Field* CreateFields();

    void SetFieldPosition(const float x, const float y);

    void DrawTurn(sf::RenderWindow& window, char value);

    void DrawField(sf::RenderWindow& window);
    static void DrawFields(sf::RenderWindow& window, Field* fields);

    bool MouseClicked(sf::Vector2f& mousePosition) const;
    bool EmptyField() const;

    void ChangeColor();
    void ReturnColor();

    static std::string Win(const Field* fields);

    static void Clear(Field* fields);

    friend bool operator==(const Field& fieldA, const Field& fieldB);
};


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
