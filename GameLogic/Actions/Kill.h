#ifndef POO2_L4_BUFFY_KILL_H
#define POO2_L4_BUFFY_KILL_H

#include "Action.h"

/**
 * Action that kills a humanoid
 *
 * @name Kill
 * @file Kill.h
 * @authors Gaétan Zwick, Marco Maziero
 * @date 21.05.2021
 */
class Kill : public Action {
public:
    /**
     * Kills the given victim
     * @param actor The humanoid to kill
     */
    explicit Kill(Humanoid* actor);

    /**
     * Executes the kill action
     * @param field The field to modify
     */
    void execute(Field &field) override;
};


#endif //POO2_L4_BUFFY_KILL_H
