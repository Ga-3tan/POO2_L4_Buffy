//
// Created by gaeta on 12.05.2021.
//

#include "Kill.h"

Kill::Kill(Humanoid *actor) : Action(actor) {}

void Kill::execute(Field &field) {
    // TODO : check if target hasn't already moved before ?
    // TODO : check if target hasn't been already killed before ?
    actionReciever->die();
    // TODO : update "game show grid" ? a 2D char grid with only representation of entities
}