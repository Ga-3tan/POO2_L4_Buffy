//
// Created by gaeta on 12.05.2021.
//

#ifndef POO2_L4_BUFFY_MOVE_H
#define POO2_L4_BUFFY_MOVE_H

#include "Action.h"

class Move : public Action {
    void execute(const Field& field) override;
};


#endif //POO2_L4_BUFFY_MOVE_H
