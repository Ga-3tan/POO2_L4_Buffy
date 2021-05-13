//
// Created by gaeta on 05.05.2021.
//

#include <cmath>
#include "Field.h"
#include <limits>

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
    for (std::list<Humanoid*>::iterator it = humanoids.begin(); it != humanoids.end(); ) {
        if (!(*it)->isAlive()) {
            Humanoid* toDelete = *it;
            it = humanoids.erase(it); // suppression de l’élément dans la liste
            delete toDelete; // destruction de l’humanoide référencé
        }
        else {
            it++;
        }
    }
    return turn++;
}

Humanoid* Field::findNearby(Humanoid* from, const std::type_info& type) const {
    Humanoid *nearest = nullptr;
    std::size_t fromX = from->x();
    std::size_t fromY = from->y();
    double closestDistance = std::numeric_limits<double>::max();
    for (Humanoid* h : humanoids) {
        if (typeid(*h) == typeid(type)) {
            std::size_t otherX = h->x();
            std::size_t otherY = h->y();
            // calcul de la distance entre les 2 coordonées
            double tempClosestDistance = hypot(abs(otherX - fromX), abs(otherY - fromY));
            if (tempClosestDistance < closestDistance) {
                closestDistance = tempClosestDistance;
                nearest = h;
            }
        }
    }
    return nearest;
}

Field::Field(std::size_t size) : size(size), map(std::vector<std::vector<char>>(size,std::vector<char>(size,' '))) {

}

// TODO : possibilité de factoriser ça
std::string Field::display() const {
    std::string display = "+";
    for (std::size_t i = 0; i < size; i++ ) display += "-";
    display += "+\n";
    for (std::vector<char> line : map) {
        display += "|";
        for (char c : line) {
            display += c;
        }
        display += "|\n";
    }
    display += "+";
    for (std::size_t i = 0; i < size; i++ ) display += "-";
    display += "+\n";
    return display;
}

void Field::updateDisplay(std::size_t x, std::size_t y, char c) {
    map[x][y] = c;
}

