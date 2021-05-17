//
// Created by gaeta on 05.05.2021.
//

#include "Buffy.h"
#include "Vampire.h"
#include <memory>

Buffy::Buffy(std::size_t gridSize) : Humanoid(gridSize, 2, 'B', 14 /* YELLOW */) {}

void Buffy::setAction(const Field &f) {
    // Chases vampire or moves randomly
    std::shared_ptr<Action> buffyMove = chaseHumanoid(f, typeid(Vampire));

    if (buffyMove == nullptr)
        buffyMove = moveRandomly(f);

    action = buffyMove;
}