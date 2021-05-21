//
// Created by gaeta on 05.05.2021.
//

#include <cmath>
#include "Vampire.h"
#include "Human.h"
#include "../Actions/Convert.h"

Vampire::Vampire() : Humanoid(1, 'V', 9 /* BLUE */) {}

void Vampire::setAction(const Field &f) {
    action = chaseHumanoid(f, typeid(Human));
}

std::shared_ptr<Action> Vampire::attackHumanoid(Humanoid* victim) {
    // Converts an enemy instead of killing it
    return std::make_shared<Convert>(victim);
}
