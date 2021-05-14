//
// Created by gaeta on 05.05.2021.
//

#ifndef POO2_L4_BUFFY_ACTION_H
#define POO2_L4_BUFFY_ACTION_H

class Action;

#include "Field.h"
#include "../Entities/Humanoid.h"

class Action {
protected:
    Humanoid* actionReciever;
public:
    Action(Humanoid* actionReciever);
    virtual void execute(Field &field) = 0;
};


#endif //POO2_L4_BUFFY_ACTION_H