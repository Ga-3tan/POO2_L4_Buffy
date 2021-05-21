//
// Created by gaeta on 05.05.2021.
//

#ifndef POO2_L4_BUFFY_GAME_H
#define POO2_L4_BUFFY_GAME_H

#include <cstddef>

class Game {
private:
    static const std::size_t NB_SIMULATIONS = 10000;
    std::size_t gridSize;
    std::size_t nbHumans;
    std::size_t nbVampires;

    double calculateBuffySuccess() const;
public:
    explicit Game(std::size_t gridsize, std::size_t nbHumans, std::size_t nbVampires);
    void start() const;
};


#endif //POO2_L4_BUFFY_GAME_H
