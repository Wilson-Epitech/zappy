/*
** ZAPPY PROJECT, 2024
** delivery
** File description:
** main
*/

#include "../include/GameLoop.hpp"

void handleMouseClick(sf::RenderWindow &window, std::vector<std::vector<Tile>> &tiles, const sf::Vector2i &mousePos, bool &tileSelected, sf::Text &infoText, const std::unordered_map<int, sf::Texture*> &) {
    for (auto &row : tiles) {
        for (auto& tile : row) {
            if (tile.contains(window.mapPixelToCoords(mousePos))) {
                for (auto& otherRow : tiles) {
                    for (auto& otherTile : otherRow) {
                        if (&otherTile != &tile) {
                            otherTile.setSelected(false);
                        }
                    }
                }
                tile.setSelected(true);
                tileSelected = true;
                std::ostringstream oss;
                oss << "Tile Position: (" << tile.getX() << ", " << tile.getY() << ")\t\t\t";
                const std::unordered_map<int, int>& resources = tile.getResources();
                const std::unordered_map<int, int>& characters = tile.getCharacters();
                int totalCharacters = 0;
                for (const auto& pair : characters) {
                    totalCharacters += pair.second;
                }
                oss << "Total Characters: " << totalCharacters << "\n\n";
                oss << "Resources:\n";
                for (size_t i = 0; i < 7; ++i) {
                    if (i < resources.size()) {
                        auto it = std::next(resources.begin(), i);
                        int resourceId = it->first;
                        int quantity = it->second;
                        oss << "Resource " << resourceId << ": " << quantity << "\t\t";
                    }
                }
                infoText.setString(oss.str());
                return;
            }
        }
    }
    tileSelected = false;
}

int main() {
    gameLoop();
    return 0;
}
