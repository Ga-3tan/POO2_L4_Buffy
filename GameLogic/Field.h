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
#include "Entities/Humanoid.h"
#include "../Utils/Coordinate.h"

std::ostream& operator << (std::ostream& os, Field& field);

class Field {
    std::list<Humanoid*> humanoids;
    std::list<Coordinate> oldDisplayCoords;
    std::size_t gridSize;
    int turn;

    friend std::ostream& operator << (std::ostream& os, Field& field);
    std::size_t getRandomPos() const;

public:
    Field(std::size_t size, std::size_t nbHumans, std::size_t nbVampires);
    int nextTurn();
    void addNewHumanoid(Humanoid* newHumanoid);
    Humanoid* findNearby(const Humanoid* from, const std::type_info& type) const;
    std::size_t size() const;
    std::size_t getNbEntity(const std::type_info& type) const;
    ~Field();
};

#endif //POO2_L4_BUFFY_FIELD_H
