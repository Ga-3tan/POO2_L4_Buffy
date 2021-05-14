/*
 -----------------------------------------------------------------------------------
 Laboratoire : POO2_L4_Buffy
 Fichier     : Human.cpp.c
 Auteur(s)   : Marco Maziero
 Date        : 12.05.2021

 But         : <‡ completer>

 Remarque(s) : <‡ completer>

 Compilateur : MinGW-g++
 -----------------------------------------------------------------------------------
*/

#include "Human.h"
#include "../GameLogic/Move.h"
#include <memory>

Human::Human(std::size_t gridSize) : Humanoid(gridSize, 'h', 13 /* PINK */) {}

void Human::setAction(const Field &f) {
    // Checks borders and moves
    std::size_t xDest, yDest;
    do {
        std::size_t xMov = rand() % 3 - 1;
        std::size_t yMov = rand() % 3 - 1;
        if(xMov == 0 && yMov == 0) continue;

        xDest = xPos + xMov;
        yDest = yPos + yMov;
    } while(xDest <= 0 || xDest >= f.size() - 1 ||
            yDest <= 0 || yDest >= f.size() - 1);

    action = std::make_shared<Move>(this, xDest, yDest);
}
