/**
 * Main file of the program
 *
 * @name LAB002_Squadron
 * @file main.cpp
 * @authors Gaétan Zwick, Marco Maziero
 * @date 21.05.2021
 */

#include <iostream>
#include <stdexcept>
#include "Game.h"

/**
 * Entry point of the program
 * @param argc The number of arguments
 * @param argv The values of the arguments
 * @return Program exit status code
 */
int main(int argc, char** argv) {
    // Wrong number of arguments
    if (argc < 4) throw std::invalid_argument("Arguments must be : <size> <nbHumans> <nbVampire>");

    // Tries to convert the arguments into integers
    try {
        // Converts arguments
        std::size_t gridSize   = std::stoi(argv[1]);
        std::size_t nbHumans   = std::stoi(argv[2]);
        std::size_t nbVampires = std::stoi(argv[3]);

        // Creates and starts the game
        Game game(gridSize, nbHumans, nbVampires);
        game.start();
    } catch (const std::invalid_argument& e) {
        throw std::invalid_argument("Arguments must be integer values");
    }

    return 0;
}
