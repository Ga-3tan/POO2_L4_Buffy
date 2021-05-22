/**
 * @file Field.cpp
 * @authors Gaétan Zwick, Marco Maziero
 * @date 21.05.2021
 */

#include <cmath>
#include "Field.h"
#include "Entities/Buffy.h"
#include "Entities/Vampire.h"
#include "Entities/Human.h"
#include "../Utils/ConsoleManager.h"
#include <limits>

std::ostream& operator << (std::ostream& os, Field& field) {
    // If first turn, draws the borders
    if (field.turn == 0) {

        // Displays left and right borders
        for (std::size_t i = 0; i < field.size(); ++i) {
            char border = i == 0 || i == field.size() - 1 ? '+' : '|';
            ConsoleManager::setCursorPosition(0, i);
            os << border;
            ConsoleManager::setCursorPosition(field.size() - 1, i);
            os << border;
        }

        // Displays up and bottom borders
        for (std::size_t i = 0; i < field.size(); ++i) {
            char border = i == 0 || i == field.size() - 1 ? '+' : '-';
            ConsoleManager::setCursorPosition(i, 0);
            os << border;
            ConsoleManager::setCursorPosition(i, field.size() - 1);
            os << border;
        }
    } else {

        // Clears old display positions
        while(!field.oldDisplayCoords.empty()) {
            ConsoleManager::setCursorPosition(field.oldDisplayCoords.front().getX(),
                                              field.oldDisplayCoords.front().getY());
            os << ' ';
            field.oldDisplayCoords.pop_front();
        }
    }

    // Displays all humanoids
    for (Humanoid* h : field.humanoids) {
        ConsoleManager::setCursorPosition(h->x(), h->y());
        os << *h;

        // Adds the position to the display coords
        field.oldDisplayCoords.emplace_back(h->x(), h->y());
    }

    return os;
}

std::size_t Field::getRandomPos() const {
    return rand() % (size() - 2) + 1;
}


Field::Field(std::size_t size, std::size_t nbHumans, std::size_t nbVampires)
: gridSize(size), turn(0) {
    // Adds the humans
    for (int i = 0; i < nbHumans; ++i) {
        Humanoid* h = new Human();
        h->setPosition(getRandomPos(), getRandomPos());
        addNewHumanoid(h);
    }

    // Adds the vampires
    for (int i = 0; i < nbVampires; ++i) {
        Humanoid* v = new Vampire();
        v->setPosition(getRandomPos(), getRandomPos());
        addNewHumanoid(v);
    }

    // Adds buffy
    Buffy* b = new Buffy();
    b->setPosition(getRandomPos(), getRandomPos());

    // Puts buffy a the end of the list (to be always drawn at the top
    humanoids.push_back(b);
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

void Field::addNewHumanoid(Humanoid* newHumanoid) {
    humanoids.push_front(newHumanoid);
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

std::size_t Field::getNbEntity(const std::type_info& type) const {
    std::size_t nb = 0;
    for (Humanoid* h : humanoids)
        if (typeid(*h) == type)
            ++nb;

    return nb;
}

Field::~Field() {
    for (Humanoid* h : humanoids)
        delete h;
}