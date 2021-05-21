/**
 * @file Coordinate.cpp
 * @authors Gaétan Zwick, Marco Maziero
 * @date 21.05.2021
 */

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