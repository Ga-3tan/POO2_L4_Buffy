#ifndef POO2_L4_BUFFY_MOVE_H
#define POO2_L4_BUFFY_MOVE_H

class Move;

#include "Action.h"

/**
 * Action that can move a humanoid
 *
 * @name Move
 * @file Move.h
 * @authors Gaétan Zwick, Marco Maziero
 * @date 21.05.2021
 */
class Move : public Action {
    std::size_t destX;
    std::size_t destY;
public:
    /**
     * Prepares the movement of the humanoid
     * @param actor The humanoid that will receive the action effects
     * @param destX The x destination position
     * @param destY The y destination position
     */
    Move(Humanoid* actor, std::size_t destX, std::size_t destY);

    /**
     * Executes the move action
     * @param field The field to modify
     */
    void execute(Field &field) override;
};


#endif //POO2_L4_BUFFY_MOVE_H
