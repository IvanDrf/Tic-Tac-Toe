#include "Field.hpp"

#include "../Window.hpp"

Field::Field() : clicking_(false) {
    if (!font_.loadFromFile("../WindowFiles/Kanok.ttf")) {
        throw std::runtime_error("Font could not be found");
    }

    value_.setFont(font_);
    value_.setCharacterSize(4 * kCharacterSize);
    value_.setString("");
    value_.setFillColor(sf::Color::White);

    shape_.setSize(sf::Vector2f(kFieldSize, kFieldSize));
    shape_.setFillColor(sf::Color(kDefaultRed, kDefaultGreen, kDefaultBlue));
}

Field* Field::CreateFields() {
    Field* fields{new Field[kFieldAmount]};

    for (short i = 0; i < kFieldAmount; ++i) {
        fields[i].SetFieldPosition(static_cast<float>(i % 3) * (kFieldSize + kDistance), static_cast<float>(i / 3) * (kFieldSize + kDistance));
    }

    return fields;
}

void Field::SetFieldPosition(const float x, const float y) {
    value_.setPosition(x + kFieldSize / 2, kTurnWindowHeight + y + kFieldSize / 2);
    shape_.setPosition(x, kTurnWindowHeight + y);
}

void Field::DrawTurn(sf::RenderWindow& window, char value) {
    value_.setString(value);
    DrawField(window);
}

void Field::DrawField(sf::RenderWindow& window) {
    sf::FloatRect valueBounds{value_.getGlobalBounds()};
    value_.setOrigin(valueBounds.width / 2 + kDistance / 2, valueBounds.height / 2 + 2 * kDistance + kDistance / 2);

    window.draw(shape_);
    window.draw(value_);
}

void Field::DrawFields(sf::RenderWindow& window, Field* fields) {
    for (short i = 0; i < kFieldAmount; ++i) {
        fields[i].DrawField(window);
    }
}

bool Field::MouseClicked(sf::Vector2f& mousePosition) const {
    return shape_.getGlobalBounds().contains(mousePosition);
}

bool Field::EmptyField() const {
    return value_.getString() == "";
}

std::string Field::Win(const Field* fields) {
    if (!fields[kMainDiagonal[0]].EmptyField() && fields[kMainDiagonal[0]] == fields[kMainDiagonal[1]] &&
        fields[kMainDiagonal[0]] == fields[kMainDiagonal[2]]) {
        return fields[kMainDiagonal[0]].value_.getString();
    }

    if (!fields[kSideDiagonal[0]].EmptyField() && fields[kSideDiagonal[0]] == fields[kSideDiagonal[1]] &&
        fields[kSideDiagonal[0]] == fields[kSideDiagonal[2]]) {
        return fields[kSideDiagonal[0]].value_.getString();
    }

    for (short i = 0; i < 3; ++i) {
        if (!fields[3 * i].EmptyField() && fields[3 * i] == fields[3 * i + 1] && fields[3 * i] == fields[3 * i + 2]) {
            return fields[3 * i].value_.getString();
        }

        if (!fields[i].EmptyField() && fields[i] == fields[i + 3] && fields[i] == fields[i + 3 * 2]) {
            return fields[i].value_.getString();
        }
    }

    return "NO";
}

void Field::Clear(Field* fields) {
    for (short i = 0; i < kFieldAmount; ++i) {
        fields[i].value_.setString("");
    }
}

bool operator==(const Field& fieldA, const Field& fieldB) {
    return fieldA.value_.getString() == fieldB.value_.getString();
}
