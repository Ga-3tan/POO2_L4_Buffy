//
// Created by gaeta on 12.05.2021.
//

#include "Move.h"

void Move::execute(const Field &field) {
    actor->setPosition(destX, destY);
    // TODO : update "game show grid" ? a 2D char grid with only representation of entities
}

Move::Move(Humanoid *actor, std::size_t destX, std::size_t destY) : Action(actor), destX(destX), destY(destY) {

}
