//
// Created by gaeta on 12.05.2021.
//

#ifndef POO2_L4_BUFFY_MOVE_H
#define POO2_L4_BUFFY_MOVE_H

#include "Action.h"

class Move : public Action {
    std::size_t destX;
    std::size_t destY;
public:
    Move(Humanoid *actor, std::size_t destX, std::size_t destY);

    void execute(const Field &field) override;
};


#endif //POO2_L4_BUFFY_MOVE_H
