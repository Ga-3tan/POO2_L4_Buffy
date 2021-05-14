//
// Created by gaeta on 12.05.2021.
//

#include "Move.h"

Move::Move(Humanoid *actor, std::size_t destX, std::size_t destY)
: Action(actor), destX(destX), destY(destY) {}

void Move::execute(Field &field) {
    actionReciever->setPosition(destX, destY);
}
