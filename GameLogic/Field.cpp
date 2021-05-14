//
// Created by gaeta on 05.05.2021.
//

#include <cmath>
#include "Field.h"
#include "../Entities/Buffy.h"
#include "../Entities/Vampire.h"
#include "../Entities/Human.h"
#include <limits>
#include <windows.h>
#include <ctime>

std::ostream& operator << (std::ostream& os, const Field& field) {
    setCursorPosition(0, 0);

    for (std::size_t i = 0; i < field.gridSize; ++i) {
        for (std::size_t j = 0; j < field.gridSize; ++j) {
            if (i == 0 && j == 0 ||
                i == field.gridSize - 1 && j == field.gridSize - 1 ||
                i == 0 && j == field.gridSize - 1 ||
                i == field.gridSize - 1 && j == 0)
                os << '+';
            else if (i == 0 || i == field.gridSize - 1)
                os << '-';
            else if (j == 0 || j == field.gridSize - 1)
                os << '|';
            else
                os << ' ';
        }
        os << std::endl;
    }

    // Displays all humanoids
    for (Humanoid* h : field.humanoids) {
        setCursorPosition(h->x(), h->y());
        os << *h;
    }

    setCursorPosition(0, field.size());
    return os;
}

void setCursorPosition(std::size_t x, std::size_t y) {
    COORD cursorPosition;
    cursorPosition.X = x;
    cursorPosition.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
}

Field::Field(std::size_t size) : gridSize(size), turn(0) {
    srand (time(NULL));

    Buffy* b = new Buffy(gridSize);
    humanoids.push_back(b);

    for (int i = 0; i < 10; ++i) {
        Vampire* h = new Vampire(gridSize);

        humanoids.push_back(h);
    }

    for (int i = 0; i < 10; ++i) {
        Human* h = new Human(gridSize);

        humanoids.push_back(h);
    }
}

int Field::nextTurn() {
    // Déterminer les prochaines actions
    for (Humanoid* humanoid : humanoids) {
        humanoid->setAction(*this);
    }

    // Executer les actions
    for (Humanoid* humanoid : humanoids) {
        humanoid->executeAction(*this);
    }

    // Enlever les humanoides tués
    for (std::list<Humanoid*>::iterator it = humanoids.begin(); it != humanoids.end();) {
        if (!(*it)->isAlive()) {
            Humanoid* toDelete = *it;
            it = humanoids.erase(it); // suppression de l’élément dans la liste
            delete toDelete; // destruction de l’humanoide référencé
        } else {
            it++;
        }
    }
    return turn++;
}

Humanoid* Field::findNearby(const Humanoid* from, const std::type_info& type) const {
    Humanoid *nearest = nullptr;
    std::size_t fromX = from->x();
    std::size_t fromY = from->y();
    double closestDistance = std::numeric_limits<double>::max();

    for (Humanoid* h : humanoids) {
        if (typeid(*h) == type) {
            std::size_t otherX = h->x();
            std::size_t otherY = h->y();

            // Distance between two coordinates
            double tempClosestDistance = hypot(abs(int(otherX - fromX)), abs(int(otherY - fromY)));
            if (tempClosestDistance < closestDistance) {
                closestDistance = tempClosestDistance;
                nearest = h;
            }
        }
    }
    return nearest;
}

std::size_t Field::size() const {
    return gridSize;
}

bool Field::isPositionOccupied(std::size_t x, std::size_t y) const {
    bool occupied = false;
    for (Humanoid* h : humanoids) {
        if (h->x() == x && h->y() == y) {
            occupied = true;
            break;
        }
    }
    return occupied;
}
