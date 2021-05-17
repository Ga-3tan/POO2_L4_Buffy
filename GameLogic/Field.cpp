//
// Created by gaeta on 05.05.2021.
//

#include <cmath>
#include "Field.h"
#include "../Entities/Buffy.h"
#include "../Entities/Vampire.h"
#include "../Entities/Human.h"
#include <limits>
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

Field::Field(std::size_t size, std::size_t nbHumans, std::size_t nbVampires)
: gridSize(size), turn(0) {
    srand (time(NULL));

    // Adds buffy
    Buffy* b = new Buffy(gridSize);
    addNewHumanoid(b);

    // Adds the humans
    for (int i = 0; i < nbHumans; ++i) {
        Humanoid* h = new Human(gridSize);
        addNewHumanoid(h);
    }

    // Adds the vampires
    for (int i = 0; i < nbVampires; ++i) {
        Humanoid* v = new Vampire(gridSize);
        addNewHumanoid(v);
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

void Field::addNewHumanoid(Humanoid* newHumanoid) {
    humanoids.push_back(newHumanoid);
}

std::size_t Field::getNbEntity(const std::type_info& type) const {
    std::size_t nb = 0;
    for (Humanoid* h : humanoids)
        if (typeid(*h) == type)
            ++nb;

    return nb;
}
