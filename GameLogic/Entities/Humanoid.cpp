//
// Created by gaeta on 05.05.2021.
//

#include "Humanoid.h"
#include "../Actions/Move.h"
#include "../Actions/Kill.h"
#include <windows.h>
#include <cmath>

std::ostream& operator << (std::ostream& out, const Humanoid& o) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), o.getDisplayColor() /* Char color */);
    out << o.getDisplayChar();
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 /* Default color */);

    return out;
}

Humanoid::Humanoid() : position(0, 0), alive(true), action(nullptr) {}

std::size_t Humanoid::x() const {
    return position.getX();
}

std::size_t Humanoid::y() const {
    return position.getY();
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

std::shared_ptr<Action> Humanoid::moveRandomly(const Field& f) {
    // Checks borders and moves
    std::size_t xDest, yDest;
    do {
        std::size_t xMov = rand() % 3 - 1;
        std::size_t yMov = rand() % 3 - 1;
        if(xMov == 0 && yMov == 0) continue;

        xDest = x() + xMov;
        yDest = y() + yMov;
    } while(xDest <= 0 || xDest >= f.size() - 2 ||
            yDest <= 0 || yDest >= f.size() - 2);

    return std::make_shared<Move>(this, xDest, yDest);
}

std::shared_ptr<Action> Humanoid::chaseHumanoid(const Field& f, const std::type_info& humanoidType) {
    Humanoid* nearest = f.findNearby(this, humanoidType);
    if (nearest == nullptr) return nullptr;

    // Gets the distances
    int distX = nearest->x() - x();
    int distY = nearest->y() - y();

    // Checks if the humanoid is in kill range
    if (hypot(abs(distX), abs(distY)) <= sqrt(2)) {
        // Kills the humanoid
        return attackHumanoid(nearest);
    } else {
        // Moves toward the humanoid
        std::size_t speed = getSpeed();
        std::size_t movX = distX == 0 ? 0 : distX > 0 ? speed : -speed;
        std::size_t movY = distY == 0 ? 0 : distY > 0 ? speed : -speed;

        // Out of bounds verification
        if (x() + movX <= 0 || x() + movX >= f.size() - 2 ||
            y() + movY <= 0 || y() + movY >= f.size() - 2)
            return nullptr;

        return std::make_shared<Move>(this, x() + movX, y() + movY);
    }
}

void Humanoid::setPosition(std::size_t x, std::size_t y) {
    position.setX(x);
    position.setY(y);
}

std::shared_ptr<Action> Humanoid::attackHumanoid(Humanoid* victim) {
    return std::make_shared<Kill>(victim);
}
