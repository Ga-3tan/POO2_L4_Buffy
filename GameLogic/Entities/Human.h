#ifndef POO2_L4_BUFFY_HUMAN_H
#define POO2_L4_BUFFY_HUMAN_H

#include "Humanoid.h"

/**
 * Represents a human, it moves randomly and can be killed by vampires
 *
 * @name Human
 * @file Human.h
 * @authors Gaétan Zwick, Marco Maziero
 * @date 21.05.2021
 */
class Human : public Humanoid {
private:
    static const char DISPLAY_CHAR;
    static const std::size_t DISPLAY_COLOR;
    static const std::size_t SPEED;

    /**
     * Gets the char representing the humanoid in the console
     * @return The humanoid char
     */
    char getDisplayChar() const override;

    /**
     * Gets the color representing the humanoid in the console
     * @return The humanoid color
     */
    std::size_t getDisplayColor() const override;

    /**
     * Gets the humanoid speed on the game board
     * @return The speed
     */
    std::size_t getSpeed() const override;
public:
    /**
     * Sets the next action to execute
     * The human moves randomly and is
     * chased by vampires that try to convert it
     * @param f The field where the action takes place
     */
    void setAction(const Field& f) override;
};

#endif //POO2_L4_BUFFY_HUMAN_H