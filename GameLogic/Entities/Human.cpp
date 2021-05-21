/**
 * @file Human.cpp
 * @authors Gaétan Zwick, Marco Maziero
 * @date 21.05.2021
 */

#include "Human.h"
#include <memory>

// Static initializations
const char Human::DISPLAY_CHAR = 'h';
const std::size_t Human::DISPLAY_COLOR = 13; // Pink
const std::size_t Human::SPEED = 1;

char Human::getDisplayChar() const {
    return DISPLAY_CHAR;
}

std::size_t Human::getDisplayColor() const {
    return DISPLAY_COLOR;
}

std::size_t Human::getSpeed() const {
    return SPEED;
}

void Human::setAction(const Field &f) {
    // Moves randomly
    action = moveRandomly(f);
}