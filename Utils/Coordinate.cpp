//
// Created by gaeta on 05.05.2021.
//

#include "Coordinate.h"

Coordinate::Coordinate(std::size_t x, std::size_t y) : x(x), y(y) {}

size_t Coordinate::getX() const {
    return x;
}

void Coordinate::setX(size_t x) {
    Coordinate::x = x;
}

size_t Coordinate::getY() const {
    return y;
}

void Coordinate::setY(size_t y) {
    Coordinate::y = y;
}

bool Coordinate::operator==(const Coordinate &rhs) const {
    return x == rhs.x &&
           y == rhs.y;
}

bool Coordinate::operator!=(const Coordinate &rhs) const {
    return !(rhs == *this);
}
