#include <iostream>
#include <stdexcept>
#include "Game.h"

int main(int argc, char** argv) {
    if (argc < 4) throw std::invalid_argument("Arguments must be : <size> <nbHumans> <nbVampire>");

    try {
        // Converts arguments
        std::size_t gridSize   = std::stoi(argv[1]);
        std::size_t nbHumans   = std::stoi(argv[2]);
        std::size_t nbVampires = std::stoi(argv[3]);

        Game game(gridSize, nbHumans, nbVampires);
        game.start();
    } catch (const std::invalid_argument& e) {
        throw std::invalid_argument("Arguments must be integer values");
    }

    return 0;
}
