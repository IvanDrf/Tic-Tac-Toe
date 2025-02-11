#include "Game.hpp"

TurnWindow::TurnWindow() {
    if (!font_.loadFromFile("Kanok.ttf")) {
        throw std::runtime_error("Font could not be found");
    }

    turn_.setFont(font_);
    turn_.setCharacterSize(3 * kCharacterSize);
    turn_.setString("Turn: X");
    turn_.setFillColor(sf::Color::Red);

    win_.setFont(font_);
    win_.setCharacterSize(3 * kCharacterSize);
    win_.setString("Winner: ");
    win_.setFillColor(sf::Color::Green);

    win_.setPosition(2 * kDistance, kDistance * 13);
    turn_.setPosition(2 * kDistance, 0);

    shape_.setSize(sf::Vector2f(kTurnWindowWidth, kTurnWindowHeight));
    shape_.setFillColor(sf::Color::Black);
}

void TurnWindow::UpdateTurn(const short turnNumber) {
    if (turnNumber % 2 == 0) {
        turn_.setString("Turn: O");
        turn_.setFillColor(sf::Color::Blue);

        return;
    }


    turn_.setString("Turn: X");
    turn_.setFillColor(sf::Color::Red);
}

void TurnWindow::DrawCurrentTurn(sf::RenderWindow& window) const {
    window.draw(shape_);
    window.draw(turn_);
    window.draw(win_);
}

void TurnWindow::UpdateWinner(sf::RenderWindow& window, std::string winner) {
    turn_.setString("No more turns");
    turn_.setFillColor(sf::Color::Cyan);
    win_.setString("Winner: " + winner);
}

void TurnWindow::Clear() {
    turn_.setString("Turn: X");
    turn_.setFillColor(sf::Color::Red);

    win_.setString("Winner: ");
    win_.setFillColor(sf::Color::Green);
}

Field::Field() {
    if (!font_.loadFromFile("Kanok.ttf")) {
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
        fields[i].SetFieldPosition((i % 3) * (kFieldSize + kDistance), (i / 3) * (kFieldSize + kDistance));
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
    value_.setOrigin(valueBounds.width / 2 + 0.5 * kDistance, valueBounds.height / 2 + 2.5 * kDistance);

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
    if (!fields[0].EmptyField() && fields[0] == fields[4] && fields[0] == fields[8]) {
        return fields[0].value_.getString();
    }

    if (!fields[2].EmptyField() && fields[2] == fields[4] && fields[2] == fields[6]) {
        return fields[2].value_.getString();
    }

    for (short i = 0; i < 3; ++i) {
        if (!fields[3 * i].EmptyField() && fields[3 * i] == fields[3 * i + 1] && fields[3 * i] == fields[3 * i + 2]) {
            return fields[3 * i].value_.getString();
        }

        if (!fields[i].EmptyField() && fields[i] == fields[i + 3] && fields[i] == fields[i + 6]) {
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

ClearButton::ClearButton() {
    if (!font_.loadFromFile("Kanok.ttf")) {
        throw std::runtime_error("Font could not be found");
    }

    text_.setFont(font_);
    text_.setCharacterSize(3 * kCharacterSize);
    text_.setString("Clear");
    text_.setFillColor(sf::Color::Magenta);

    sf::FloatRect textBound{text_.getGlobalBounds()};
    text_.setOrigin(textBound.width / 2, textBound.height / 2);
    text_.setPosition(2 * (kDistance + kFieldSize) + kFieldSize / 2, kTurnWindowHeight / 2 - 3.5 * kDistance);

    shape_.setSize(sf::Vector2f(kFieldSize, kTurnWindowHeight));
    shape_.setFillColor(sf::Color(76, 76, 76));

    shape_.setPosition(2 * (kDistance + kFieldSize), -kDistance);
}

void ClearButton::DrawButton(sf::RenderWindow& window) const {
    window.draw(shape_);
    window.draw(text_);
}

bool ClearButton::MouseClicked(sf::Vector2f& mousePosition) const {
    return shape_.getGlobalBounds().contains(mousePosition);
}
