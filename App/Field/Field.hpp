#pragma once

#include <SFML/Graphics.hpp>

namespace {
const short kMainDiagonal[]{0, 4, 8};
const short kSideDiagonal[]{2, 4, 6};
}  // namespace

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
