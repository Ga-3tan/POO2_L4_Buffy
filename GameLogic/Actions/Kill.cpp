//
// Created by gaeta on 12.05.2021.
//

#include "Kill.h"

Kill::Kill(Humanoid *actor) : Action(actor) {}

void Kill::execute(Field &field) {
    actionReciever->die();
}