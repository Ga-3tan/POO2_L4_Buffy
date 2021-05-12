//
// Created by gaeta on 05.05.2021.
//

#ifndef POO2_L4_BUFFY_FIELD_H
#define POO2_L4_BUFFY_FIELD_H


#include "../Entities/Humanoid.h"
#include <typeinfo>
#include <list>

class Field {
    std::list<Humanoid*> humanoids;
    std::size_t size;
public:
    Field(std::size_t size);
    int nextTurn();
    Humanoid* findNearby(Humanoid* from, const std::type_info& type);
};


#endif //POO2_L4_BUFFY_FIELD_H
