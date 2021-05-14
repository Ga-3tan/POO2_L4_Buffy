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

    while(true) {
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        field.nextTurn();
        std::cout << field;
    }
}
