//
// Created by gaeta on 05.05.2021.
//

#include <cmath>
#include "Vampire.h"
#include "Human.h"
#include "../GameLogic/Move.h"
#include "../GameLogic/Kill.h"

Vampire::Vampire(std::size_t gridSize) : Humanoid(gridSize, 'V', 9 /* BLUE */) {}

void Vampire::setAction(const Field &f) {
    // TODO : Duplicated code from Buffy.cpp
    Humanoid* nearest = f.findNearby(this, typeid(Human));

    // No vampire to kill
    if (nearest == nullptr) return;

    // Gets the distances
    int distX = nearest->x() - xPos;
    int distY = nearest->y() - yPos;

    // Checks if the humanoid is in kill range
    if (hypot(abs(distX), abs(distY)) <= sqrt(2)) {
        // Kills the humanoid
        action = std::make_shared<Kill>(nearest);
    } else {
        // Moves toward the humanoid
        std::size_t movX = distX == 0 ? 0 : distX > 0 ? 1 : -1;
        std::size_t movY = distY == 0 ? 0 : distY > 0 ? 1 : -1;

        // Doesnt move if cannot move (occupied coords)
        if (f.isPositionOccupied(xPos + movX, yPos + movY)) {
            action.reset();
            return;
        }

        action = std::make_shared<Move>(this, xPos + movX, yPos + movY);
    }
}
