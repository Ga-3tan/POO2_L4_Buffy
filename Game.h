//
// Created by gaeta on 05.05.2021.
//

#ifndef POO2_L4_BUFFY_GAME_H
#define POO2_L4_BUFFY_GAME_H

#include <cstddef>

class Game {
private:
    std::size_t gridSize;
    std::size_t nbHumans;
    std::size_t nbVampires;

    double calculateBuffySuccess(std::size_t nbSimulations) const;
    void clearLineAt(std::size_t pos) const;
public:
    explicit Game(std::size_t gridsize, std::size_t nbHumans, std::size_t nbVampires);
    void start();
};


#endif //POO2_L4_BUFFY_GAME_H
