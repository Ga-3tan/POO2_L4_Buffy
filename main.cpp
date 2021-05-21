#include <iostream>
#include <stdexcept>
#include "Game.h"

int main(int argc, char** argv) {
    if (argc < 4) throw std::invalid_argument("Arguments must be : <size> <nbHumans> <nbVampire>");

    try {
        // Converts arguments
        std::size_t gridSize   = atoi(argv[1]);
        std::size_t nbHumans   = atoi(argv[1]);
        std::size_t nbVampires = atoi(argv[1]);

        Game game(std::stoi(argv[1]), std::stoi(argv[2]), std::stoi(argv[3]));
        game.start();
    } catch (const std::invalid_argument& e) {
        throw std::invalid_argument("Arguments must be integer values");
    }

    return 0;
}
