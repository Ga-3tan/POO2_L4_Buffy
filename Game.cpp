//
// Created by gaeta on 05.05.2021.
//

#include "Game.h"
#include "Entities/Vampire.h"
#include "Entities/Human.h"
#include "GameLogic/Field.h"
#include <iostream>
#include <windows.h>

Game::Game(std::size_t gridSize, std::size_t nbHumans, std::size_t nbVampires)
: gridSize(gridSize), nbHumans(nbHumans), nbVampires(nbVampires) {}

void setCursorPosition(std::size_t x, std::size_t y) {
    COORD cursorPosition;
    cursorPosition.X = x;
    cursorPosition.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
}

void Game::start() {
    Field field(gridSize, nbHumans, nbVampires);
    std::cout << field;

    std::string input;
    std::size_t turn = 0;
    do {
        // Registers user input
        clearLineAt(gridSize);
        std::cout << "[" << turn << "] q>uit s>tatistics n>ext: ";
        getline(std::cin, input, '\n');
        std::cin.clear();

        // Processes user input
        if (input == "n") {
            turn = field.nextTurn();
            if (field.getNbEntity(typeid(Vampire)) == 0) input = "q";
        } else if (input == "s") {
            double result = calculateBuffySuccess(50000) * 100.;
            clearLineAt(gridSize + 2);
            std::cout << "Percentage of Buffy wins : " << result << "%" << std::endl;
        }

        // Displays the game
        std::cout << field;

    } while (input != "q");

    std::cout << "There are no more vampires, the game has ended !" << std::endl;
}

double Game::calculateBuffySuccess(std::size_t nbSimulations) const {
    double nbBuffyWins = 0;
    for (std::size_t i = 1; i <= nbSimulations; ++i) {
        setCursorPosition(0, gridSize + 1);
        std::cout << "Calculating statistics, simulation : " << i << "/" << nbSimulations << "    " << std::endl;

        Field field(gridSize, nbHumans, nbVampires);
        do {
            field.nextTurn();
        } while (field.getNbEntity(typeid(Vampire)) != 0);

        if (field.getNbEntity(typeid(Human)) > 0) ++nbBuffyWins;
    }

    // Returns the percentage of wins
    return nbBuffyWins / (double)nbSimulations;
}

void Game::clearLineAt(std::size_t pos) const {
    setCursorPosition(0, pos);
    std::cout << "                                                     ";
    setCursorPosition(0, pos);
}
