/*
** ZAPPY PROJECT, 2024
** delivery
** File description:
** main
*/

#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 800), "ZAPPY");
    const int squareSize = 100;
    const int boardSize = 10;
    sf::RectangleShape squares[boardSize][boardSize];

    for (int row = 0; row < boardSize; ++row) {
        for (int col = 0; col < boardSize; ++col) {
            squares[row][col].setSize(sf::Vector2f(squareSize, squareSize));
            squares[row][col].setPosition(col * squareSize, row * squareSize);
            if ((row + col) % 2 == 0) {
                squares[row][col].setFillColor(sf::Color::White);
            } else {
                squares[row][col].setFillColor(sf::Color::Black);
            }
        }
    }

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        for (int row = 0; row < boardSize; ++row) {
            for (int col = 0; col < boardSize; ++col) {
                window.draw(squares[row][col]);
            }
        }
        window.display();
    }

    return 0;
}
