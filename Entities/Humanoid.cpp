//
// Created by gaeta on 05.05.2021.
//

#include "Humanoid.h"
#include <windows.h>

std::ostream& operator << (std::ostream& out, const Humanoid& o) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), o.displayColor /* Char color */);
    out << o.displayChar;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 /* Default color */);

    return out;
}

Humanoid::Humanoid(std::size_t gridSize, char displayChar, char displayColor)
: alive(true), displayChar(displayChar), displayColor(displayColor), action(nullptr) {

    // TODO : Cannot spawn onto another humanoid
    xPos = rand() % (gridSize - 2) + 1;
    yPos = rand() % (gridSize - 2) + 1;
}

std::size_t Humanoid::x() const {
    return xPos;
}

std::size_t Humanoid::y() const {
    return yPos;
}

bool Humanoid::isAlive() const {
    return alive;
}

void Humanoid::die() {
    alive = false;
}

void Humanoid::executeAction(Field &f) {
    if (action)
        action->execute(f);
}

void Humanoid::setPosition(std::size_t x, std::size_t y) {
    this->xPos = x;
    this->yPos = y;
}