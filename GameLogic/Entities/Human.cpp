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

// Static initializations
const char Human::DISPLAY_CHAR = 'h';
const std::size_t Human::DISPLAY_COLOR = 13; // Pink
const std::size_t Human::SPEED = 1;

void Human::setAction(const Field &f) {
    // Moves randomly
    action = moveRandomly(f);
}

char Human::getDisplayChar() const {
    return DISPLAY_CHAR;
}

std::size_t Human::getDisplayColor() const {
    return DISPLAY_COLOR;
}

std::size_t Human::getSpeed() const {
    return SPEED;
}