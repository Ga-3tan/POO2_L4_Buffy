#ifndef POO2_L4_BUFFY_HUMANOID_H
#define POO2_L4_BUFFY_HUMANOID_H

class Humanoid;

#include <cstdio>
#include <iostream>
#include <memory>
#include "../Actions/Action.h"
#include "../../Utils/Coordinate.h"

/**
 * The stream operator can be used to display a humanoid
 * @param out The output stream to modify
 * @param h The humanoid to display
 * @return The modified output stream
 */
std::ostream& operator << (std::ostream& out, const Humanoid& h);

/**
 * Represents a humanoid and its actions
 *
 * @name Humanoid
 * @file Humanoid.h
 * @authors Gaétan Zwick, Marco Maziero
 * @date 21.05.2021
 */
class Humanoid {
    /**
     * The stream operator can be used to display a humanoid
     * @param out The output stream to modify
     * @param h The humanoid to display
     * @return The modified output stream
     */
    friend std::ostream& operator << (std::ostream& out, const Humanoid& h);
protected:
    bool alive;
    Coordinate position;
    std::shared_ptr<Action> action;

    /**
     * Constructor used to initialize the class attributes
     */
    Humanoid();

    /**
     * Generates a random move on the given field
     * @param f The game field
     * @return The created move action
     */
    std::shared_ptr<Action> moveRandomly(const Field& f);

    /**
     * Chases a specific type of humanoid
     * @param f The game field
     * @param humanoidType The type of humanoid to chase
     * @return The created action (move, kill, ...)
     */
    std::shared_ptr<Action> chaseHumanoid(const Field& f, const std::type_info& humanoidType);

    /**
     * Creates an action for attacking a humanoid
     * @param victim The victim of the attack
     * @return The created move (kill, convert, ...)
     */
    virtual std::shared_ptr<Action> attackHumanoid(Humanoid* victim);

    /**
     * Gets the char representing the humanoid in the console
     * @return The humanoid char
     */
    virtual char getDisplayChar() const = 0;

    /**
     * Gets the color representing the humanoid in the console
     * @return The humanoid color
     */
    virtual std::size_t getDisplayColor() const = 0;

    /**
     * Gets the humanoid speed on the game board
     * @return The speed
     */
    virtual std::size_t getSpeed() const = 0;
public:
    /**
     * Retrieves the x-axis position of the humanoid
     * @return The x position
     */
    std::size_t x() const;

    /**
     * Retrieves the y-axis position of the humanoid
     * @return The y position
     */
    std::size_t y() const;

    /**
     * Sets the new position of the humanoid
     * @param x The new x position
     * @param y The new y position
     */
    void setPosition(std::size_t x, std::size_t y);

    /**
     * Checks if the current humanoid is alive
     * @return The humanoid state
     */
    bool isAlive() const;

    /**
     * Kills the humanoid
     */
    void die();

    /**
     * Sets the next action to execute
     * @param f The field where the action takes place
     */
    virtual void setAction(const Field& f) = 0;

    /**
     * Executes the action on the given field
     * @param f The field to modify
     */
    void executeAction(Field &f);

    /**
     * Virtual destructor needed because of inheritance
     */
    virtual ~Humanoid() = default;
};

#endif //POO2_L4_BUFFY_HUMANOID_H