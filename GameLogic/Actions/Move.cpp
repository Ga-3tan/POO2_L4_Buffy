/**
 * @file Move.cpp
 * @authors Gaétan Zwick, Marco Maziero
 * @date 21.05.2021
 */

#include "Move.h"

Move::Move(Humanoid* actor, std::size_t destX, std::size_t destY)
: Action(actor), destX(destX), destY(destY) {}

void Move::execute(Field &field) {
    actionReciever->setPosition(destX, destY);
}
