/**
 * @file Game.cpp
 * @authors Gaétan Zwick, Marco Maziero
 * @date 21.05.2021
 */

#include "Game.h"
#include "GameLogic/Entities/Vampire.h"
#include "GameLogic/Entities/Human.h"
#include "GameLogic/Field.h"
#include "Utils/ConsoleManager.h"
#include <iostream>
#include <iomanip>
#include <cmath>

// Static initializations
const std::size_t Game::NB_SIMULATIONS = 100000;

double Game::calculateBuffySuccess() const {
    double nbBuffyWins = 0;

    // Sets up the console log message
    int nbDigits = NB_SIMULATIONS > 0 ? (int) log10 ((double) NB_SIMULATIONS) + 1 : 1;
    std::string s = "Calculating statistics, simulation : ";
    ConsoleManager::setCursorPosition(0, gridSize + 1);
    std::cout << s << std::setw(nbDigits) << "" << "/" << NB_SIMULATIONS;

    // Executes the simulations
    for (std::size_t i = 1; i <= NB_SIMULATIONS; ++i) {
        // Displays the simulation number
        ConsoleManager::setCursorPosition(s.length(), gridSize + 1);
        std::cout << std::left << std::setw(nbDigits) << i;

        // Creates the field and iterates through each turn until the game ends
        Field field(gridSize, nbHumans, nbVampires);
        do {
            field.nextTurn();
        } while (field.getNbEntity(typeid(Vampire)) != 0);

        // There are humans alive, buffy wins the game
        if (field.getNbEntity(typeid(Human)) > 0) ++nbBuffyWins;
    }

    // Returns the percentage of wins
    return nbBuffyWins / (double)NB_SIMULATIONS * 100.;
}

Game::Game(std::size_t gridSize, std::size_t nbHumans, std::size_t nbVampires)
: gridSize(gridSize), nbHumans(nbHumans), nbVampires(nbVampires) {
    // Sets the seed for the randomizer
    srand (time(NULL));
}

void Game::start() const {
    Field field(gridSize, nbHumans, nbVampires);
    std::cout << field;
    ConsoleManager::setCursorPosition(0, field.size());

    // Game loop
    std::string input;
    std::size_t turn = 0;
    do {
        // Registers user input
        ConsoleManager::setCursorPosition(0, field.size());
        std::cout << "[" << turn << "] q>uit s>tatistics n>ext: ";
        getline(std::cin, input, '\n');
        std::cin.clear();

        // Processes user input
        if (input == "n") {
            // Plays next turn and displays the game grid
            turn = field.nextTurn();
            std::cout << field;
        } else if (input == "s") {
            double result = calculateBuffySuccess();
            ConsoleManager::setCursorPosition(0, gridSize + 2);
            std::cout << "Percentage of Buffy wins : " << result << "%" << std::endl;
        }

    } while (input != "q");

    // Checks if the game is over
    if (field.getNbEntity(typeid(Vampire)) == 0) {
        // Displays ending message
        ConsoleManager::setCursorPosition(0, field.size() + 1);
        std::cout << "The game is over, Buffy successfully killed all the vampires !" << std::endl;
        if (field.getNbEntity(typeid(Human)) != 0)
            std::cout << "Buffy has won ! There are human survivors !" << std::endl;
        input = "q";
    }
}