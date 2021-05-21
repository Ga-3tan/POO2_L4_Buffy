//
// Created by gaeta on 12.05.2021.
//

#ifndef POO2_L4_BUFFY_KILL_H
#define POO2_L4_BUFFY_KILL_H

#include "Action.h"

class Kill : public Action {
public:
    Kill(Humanoid* actor);
    void execute(Field &field) override;
};


#endif //POO2_L4_BUFFY_KILL_H
