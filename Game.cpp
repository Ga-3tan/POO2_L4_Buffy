//
// Created by gaeta on 05.05.2021.
//

#include "Game.h"
#include "GameLogic/Field.h"

void Game::start() {
    Field field;
    while(true) {
        field.nextTurn();
    }
}
