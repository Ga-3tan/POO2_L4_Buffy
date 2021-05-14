//
// Created by gaeta on 05.05.2021.
//

#ifndef POO2_L4_BUFFY_FIELD_H
#define POO2_L4_BUFFY_FIELD_H

class Field;

#include <typeinfo>
#include <list>
#include <vector>
#include <string>
#include "../Entities/Humanoid.h"

std::ostream& operator << (std::ostream& os, const Field& field);
void setCursorPosition(std::size_t x, std::size_t y);

class Field {
    std::list<Humanoid*> humanoids;
    std::size_t gridSize;
    int turn;

    friend std::ostream& operator << (std::ostream& os, const Field& field);
public:
    Field(std::size_t size);
    int nextTurn();
    Humanoid* findNearby(const Humanoid* from, const std::type_info& type) const;
    bool isPositionOccupied(std::size_t x, std::size_t y) const;
    std::size_t size() const;
};

#endif //POO2_L4_BUFFY_FIELD_H
