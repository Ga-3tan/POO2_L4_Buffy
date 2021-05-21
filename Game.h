#ifndef POO2_L4_BUFFY_GAME_H
#define POO2_L4_BUFFY_GAME_H

#include <cstddef>

/**
 * Represents an instance of the buffy game
 *
 * @name Game
 * @file Game.h
 * @authors Gaétan Zwick, Marco Maziero
 * @date 21.05.2021
 */
class Game {
private:
    static const std::size_t NB_SIMULATIONS;
    std::size_t gridSize;
    std::size_t nbHumans;
    std::size_t nbVampires;

    /**
     * Calculates the % of buffy success by
     * starting NB_SUMULATIONS simulations
     * @return The percentage of Buffy success
     */
    double calculateBuffySuccess() const;
public:
    /**
     * Game constructor. Takes the program
     * arguments as parameters
     * @param gridSize The size of the game grid
     * @param nbHumans The number of human entities
     * @param nbVampires The number of vampire entities
     */
    Game(std::size_t gridSize, std::size_t nbHumans, std::size_t nbVampires);

    /**
     * Starts the game
     */
    void start() const;
};


#endif //POO2_L4_BUFFY_GAME_H
