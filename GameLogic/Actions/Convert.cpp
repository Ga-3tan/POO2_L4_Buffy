/**
 * @file Convert.cpp
 * @authors Gaétan Zwick, Marco Maziero
 * @date 21.05.2021
 */

#include "../Field.h"
#include "Convert.h"
#include "../Entities/Vampire.h"

Convert::Convert(Humanoid *actor) : Action(actor) {}

void Convert::execute(Field &field) {
    std::size_t chance = rand() % 2;

    if (chance) {
        // Converts the humanoid
        Humanoid* converted = new Vampire();
        converted->setPosition(actionReciever->x(), actionReciever->y());
        field.addNewHumanoid(converted);
    }

    // Kills the old humanoid form
    actionReciever->die();
}