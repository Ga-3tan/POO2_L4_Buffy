#ifndef POO2_L4_BUFFY_ACTION_H
#define POO2_L4_BUFFY_ACTION_H

class Action;

#include "../Field.h"
#include "../Entities/Humanoid.h"

/**
 * Represents an action that can be stored and executed
 * (Command pattern)
 *
 * @name Action
 * @file Action.h
 * @authors Gaétan Zwick, Marco Maziero
 * @date 21.05.2021
 */
class Action {
protected:
    Humanoid* actionReciever;
public:
    /**
     * The constructor
     * @param actionReciever The humanoid receiving the effects of the action
     */
    Action(Humanoid* actionReciever);

    /**
     * Executes the stored action
     * @param field The field to modify
     */
    virtual void execute(Field &field) = 0;

    /**
     * Virtual destructor needed because of inheritance
     */
    virtual ~Action() = default;
};


#endif //POO2_L4_BUFFY_ACTION_H