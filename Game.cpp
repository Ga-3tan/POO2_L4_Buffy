//
// Created by gaeta on 05.05.2021.
//

#include "Game.h"
#include "GameLogic/Field.h"
#include <iostream>
#include <chrono>
#include <thread>


void Game::start(std::size_t gridSize) {
    Field field(gridSize);
    std::cout << field;

    std::string input;
    std::size_t turn = 0;
    do {
        // Displays the game
        std::cout << field;

        std::cout << "[" << turn << "] q>uit s>tatistics n>ext: ";
        getline(std::cin, input, '\n');
        std::cin.clear();

        // TODO : How do we know when the game is over ?
        if (input == "n")
            turn = field.nextTurn();

    } while (input != "q");
}
