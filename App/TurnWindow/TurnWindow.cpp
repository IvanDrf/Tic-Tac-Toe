#include "TurnWindow.hpp"

#include "../Window.hpp"

namespace {
const short kWinYDistance{13 * kDistance};
}

TurnWindow::TurnWindow() {
    if (!font_.loadFromFile("../WindowFiles/Kanok.ttf")) {
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

    win_.setPosition(2 * kDistance, kWinYDistance);
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
