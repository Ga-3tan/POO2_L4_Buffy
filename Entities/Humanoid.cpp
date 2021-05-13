//
// Created by gaeta on 05.05.2021.
//

#include "Humanoid.h"

std::size_t Humanoid::x() const {
    return xPos;
}

std::size_t Humanoid::y() const {
    return yPos;
}

bool Humanoid::isAlive() const {
    return alive;
}

void Humanoid::executeAction(const Field &f) {

}

void Humanoid::setPosition(std::size_t x, std::size_t y) {
    this->xPos = x;
    this->yPos = y;
}
