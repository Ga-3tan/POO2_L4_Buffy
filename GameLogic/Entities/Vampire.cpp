//
// Created by gaeta on 05.05.2021.
//

#include <cmath>
#include "Vampire.h"
#include "Human.h"
#include "../Actions/Convert.h"

// Static initializations
const char Vampire::DISPLAY_CHAR = 'V';
const std::size_t Vampire::DISPLAY_COLOR = 9; // Blue
const std::size_t Vampire::SPEED = 1;

void Vampire::setAction(const Field &f) {
    action = chaseHumanoid(f, typeid(Human));
}

std::shared_ptr<Action> Vampire::attackHumanoid(Humanoid* victim) {
    // Converts an enemy instead of killing it
    return std::make_shared<Convert>(victim);
}

char Vampire::getDisplayChar() const {
    return DISPLAY_CHAR;
}

std::size_t Vampire::getDisplayColor() const {
    return DISPLAY_COLOR;
}

std::size_t Vampire::getSpeed() const {
    return SPEED;
}