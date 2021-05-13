//
// Created by gaeta on 05.05.2021.
//

#ifndef POO2_L4_BUFFY_FIELD_H
#define POO2_L4_BUFFY_FIELD_H

#include <typeinfo>
#include <list>
#include <vector>
#include "../Entities/Humanoid.h"
#include <string>
#include <iostream>


class Field {
    std::vector<std::vector<char>> map;
    std::list<Humanoid*> humanoids;
    std::size_t size;
    int turn{0};
public:
    Field(std::size_t size);
    int nextTurn();
    Humanoid* findNearby(Humanoid* from, const std::type_info& type) const;
    void updateDisplay(std::size_t x, std::size_t y, char c);
    std::ostream& display(std::ostream& os) const;
};

std::ostream& operator << (std::ostream& os, const Field& field);

#endif //POO2_L4_BUFFY_FIELD_H
