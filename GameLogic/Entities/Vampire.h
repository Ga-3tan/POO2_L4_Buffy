#ifndef POO2_L4_BUFFY_VAMPIRE_H
#define POO2_L4_BUFFY_VAMPIRE_H

#include "Humanoid.h"

/**
 * Represents a vampire, it chases and tries to convert humans
 *
 * @name Vampire
 * @file Vampire.h
 * @authors Gaétan Zwick, Marco Maziero
 * @date 21.05.2021
 */
class Vampire : public Humanoid {
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
     * A vampire chases the humans and
     * tries to convert them into vampires
     * it kills the victim 50% of the time
     * @param f The field where the action takes place
     */
    void setAction(const Field& f) override;

    /**
     * The vampire when attacking does not kill
     * the victim but tries to convert him which
     * can kill him 50% of the time
     * @param victim The victim to convert
     * @return The newly created convert action
     */
    std::shared_ptr<Action> attackHumanoid(Humanoid* victim) override;
};

#endif //POO2_L4_BUFFY_VAMPIRE_H
