//
// Created by gaeta on 05.05.2021.
//

#include "Buffy.h"
#include "Vampire.h"
#include "../GameLogic/Kill.h"
#include "../GameLogic/Move.h"
#include <cmath>
#include <memory>

Buffy::Buffy(std::size_t gridSize) : Humanoid(gridSize, 'B', 14 /* YELLOW */) {}

void Buffy::setAction(const Field &f) {
    Humanoid* nearest = f.findNearby(this, typeid(Vampire));

    // No vampire to kill
    if (nearest == nullptr) {
        // TODO : Duplicated code from Human.cpp
        // Checks borders and moves
        std::size_t xDest, yDest;
        do {
            std::size_t xMov = rand() % 3 - 1;
            std::size_t yMov = rand() % 3 - 1;
            if(xMov == 0 && yMov == 0) continue;

            xDest = xPos + xMov;
            yDest = yPos + yMov;
        } while(xDest <= 0 || xDest >= f.size() - 1 ||
                yDest <= 0 || yDest >= f.size() - 1 ||
                f.isPositionOccupied(xDest, yDest)); // TODO : Only present in Buffy.cpp not in Human.cpp

        action = std::make_shared<Move>(this, xDest, yDest);
        return;
    }

    // Gets the distances
    int distX = nearest->x() - xPos;
    int distY = nearest->y() - yPos;

    // Checks if the humanoid is in kill range
    if (hypot(abs(distX), abs(distY)) <= sqrt(2)) {
        // Kills the humanoid
        action = std::make_shared<Kill>(nearest);
    } else {
        // Moves toward the humanoid
        std::size_t movX = distX == 0 ? 0 : distX > 0 ? 2 : -2;
        std::size_t movY = distY == 0 ? 0 : distY > 0 ? 2 : -2;

        // Doesnt move if cannot move (occupied coords)
        if (f.isPositionOccupied(xPos + movX, yPos + movY)) {
            action.reset();
            return;
        }

        action = std::make_shared<Move>(this, xPos + movX, yPos + movY);
    }
}