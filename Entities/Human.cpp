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
#include <memory>

Human::Human() : Humanoid(1, 'h', 13 /* PINK */) {}

void Human::setAction(const Field &f) {
    // Moves randomly
    action = moveRandomly(f);
}