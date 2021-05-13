//
// Created by gaeta on 05.05.2021.
//

#include "Game.h"
#include "GameLogic/Field.h"

void Game::start(std::size_t gridSize) {
    Field field(gridSize);
    while(true) {
        field.nextTurn();
    }
}
