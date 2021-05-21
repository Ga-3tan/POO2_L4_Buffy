#ifndef POO2_L4_BUFFY_FIELD_H
#define POO2_L4_BUFFY_FIELD_H

class Field;

#include <typeinfo>
#include <list>
#include <vector>
#include <string>
#include "Entities/Humanoid.h"
#include "../Utils/Coordinate.h"

/**
 * The stream operator can be used to display a field
 * @param os The output stream to modify
 * @param field The field to display
 * @return A reference to the modified output stream
 */
std::ostream& operator << (std::ostream& os, Field& field);

/**
 * Represents one field in the Buffy game
 * It can be displayed and the turns can be advanced
 *
 * @name Field
 * @file Field.h
 * @authors Gaétan Zwick, Marco Maziero
 * @date 21.05.2021
 */
class Field {
    std::list<Humanoid*> humanoids;
    std::list<Coordinate> oldDisplayCoords;
    std::size_t gridSize;
    int turn;

    /**
     * The stream operator can be used to display a field
     * @param os The output stream to modify
     * @param field The field to display
     * @return A reference to the modified output stream
     */
    friend std::ostream& operator << (std::ostream& os, Field& field);

    /**
     * Generates a random number contained inside the game grid bounds
     * @return The generated number
     */
    std::size_t getRandomPos() const;
public:
    /**
     * Field constructor
     * @param size The filed size
     * @param nbHumans The number of humans to spawn
     * @param nbVampires The number of vampires to spawn
     */
    Field(std::size_t size, std::size_t nbHumans, std::size_t nbVampires);

    /**
     * Plays the next turn by seting the actions and executing them
     * @return Returns the number of the current trun
     */
    int nextTurn();

    /**
     * Adds a new humanoid to the list of humanoids
     * @param newHumanoid The new humanoid to add
     */
    void addNewHumanoid(Humanoid* newHumanoid);

    /**
     * Finds the nearest humanoid belonging to the given class
     * @param from The source humanoid (the one searching)
     * @param type The type of humanoid to search
     * @return The humanoid found (can be nullptr if none was found)
     */
    Humanoid* findNearby(const Humanoid* from, const std::type_info& type) const;

    /**
     * Gives the size of the field
     * @return The size of the field
     */
    std::size_t size() const;

    /**
     * Gives the amount of the specified entity are on the field
     * @param type The type of the wanted entity
     * @return The number of entities found
     */
    std::size_t getNbEntity(const std::type_info& type) const;

    /**
     * Used to destroy dynamically allocated humanoids
     */
    ~Field();
};

#endif //POO2_L4_BUFFY_FIELD_H
