#ifndef POO2_L4_BUFFY_CONVERT_H
#define POO2_L4_BUFFY_CONVERT_H

#include "Action.h"

/**
 * Action that tries to convert a humanoid into a vampire
 *
 * @name Convert
 * @file Convert.h
 * @authors Gaétan Zwick, Marco Maziero
 * @date 21.05.2021
 */
class Convert : public Action {
public:
    /**
     * Convert has a 50% chance of killing the given victim
     * @param actor The victim to kill/convert
     */
    explicit Convert(Humanoid* actor);

    /**
     * Executes the convert action
     * @param field The field to modify
     */
    void execute(Field &field) override;
};

#endif //POO2_L4_BUFFY_CONVERT_H
