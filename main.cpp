#include "Game.hpp"

int main(int, char**) {
    sf::RenderWindow window(sf::VideoMode(kWindowWidth, kWindowHeight), "Tic-Tac-Toe");

    Field* fields = Field::CreateFields();
    TurnWindow turnField;

    ClearButton clearButton;

    short playerTurn{1};
    bool endGame{false};

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.clear();
                window.close();
            }

            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2f mousePosition{sf::Mouse::getPosition(window)};

                    for (short i = 0; i < kFieldAmount && !endGame; ++i) {
                        if (fields[i].MouseClicked(mousePosition) && fields[i].EmptyField()) {
                            if (playerTurn % 2 == 0) {
                                fields[i].DrawTurn(window, 'O');
                            } else {
                                fields[i].DrawTurn(window, 'X');
                            }

                            ++playerTurn;
                            turnField.UpdateTurn(playerTurn);
                        }
                    }

                    if (clearButton.MouseClicked(mousePosition)) {
                        turnField.Clear();
                        Field::Clear(fields);

                        playerTurn = 1;
                        endGame = false;
                    }
                }
            }
        }

        if (playerTurn >= kMinTurnForWin - 1) {
            std::string winner{Field::Win(fields)};

            if (winner != "NO") {
                turnField.UpdateWinner(window, winner);
                endGame = true;
            } else if (playerTurn == kMaxTurn) {
                turnField.UpdateWinner(window, "DRAW");
            }
        }

        window.clear();

        turnField.DrawCurrentTurn(window);
        clearButton.DrawButton(window);
        Field::DrawFields(window, fields);

        window.display();
    }

    delete[] fields;
    return 0;
}
