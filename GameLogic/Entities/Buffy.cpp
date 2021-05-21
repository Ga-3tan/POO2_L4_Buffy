//
// Created by gaeta on 05.05.2021.
//

#include "Buffy.h"
#include "Vampire.h"
#include <memory>

// Static initializations
const char Buffy::DISPLAY_CHAR = 'B';
const std::size_t Buffy::DISPLAY_COLOR = 14; // Yellow
const std::size_t Buffy::SPEED = 2;

void Buffy::setAction(const Field &f) {
    // Chases vampire or moves randomly
    std::shared_ptr<Action> buffyMove = chaseHumanoid(f, typeid(Vampire));

    if (buffyMove == nullptr)
        buffyMove = moveRandomly(f);

    action = buffyMove;
}

char Buffy::getDisplayChar() const {
    return DISPLAY_CHAR;
}

std::size_t Buffy::getDisplayColor() const {
    return DISPLAY_COLOR;
}

std::size_t Buffy::getSpeed() const {
    return SPEED;
}