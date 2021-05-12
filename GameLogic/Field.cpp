//
// Created by gaeta on 05.05.2021.
//

#include <cmath>
#include "Field.h"
#include "../Utils/Coordinate.h"
#include <limits>

int Field::nextTurn() {
    return 0;
}

Humanoid* Field::findNearby(Humanoid* from, const std::type_info& type) {
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

Field::Field(std::size_t size) : size(size) {

}

