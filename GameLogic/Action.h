//
// Created by gaeta on 05.05.2021.
//

#ifndef POO2_L4_BUFFY_ACTION_H
#define POO2_L4_BUFFY_ACTION_H


#include "Field.h"

class Action {
    virtual void execute(const Field& field) = 0;
};


#endif //POO2_L4_BUFFY_ACTION_H
