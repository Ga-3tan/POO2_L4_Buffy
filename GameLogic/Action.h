//
// Created by gaeta on 05.05.2021.
//

#ifndef POO2_L4_BUFFY_ACTION_H
#define POO2_L4_BUFFY_ACTION_H

// sinon "... does not name a type"
class Humanoid;
class Field;

#include "Field.h"
#include "../Entities/Humanoid.h"

class Action {
protected:
    Humanoid* actor; // TODO weak ptr ?
public:
    Action(Humanoid* actor);
    virtual void execute(const Field& field) = 0;
};


#endif //POO2_L4_BUFFY_ACTION_H
