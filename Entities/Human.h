/*
 -----------------------------------------------------------------------------------
 Laboratoire : POO2_L4_Buffy
 Fichier     : Human.h
 Auteur(s)   : Marco Maziero
 Date        : 12.05.2021

 But         : <‡ completer>

 Remarque(s) : <‡ completer>

 Compilateur : MinGW-g++
 -----------------------------------------------------------------------------------
*/

#ifndef POO2_L4_BUFFY_HUMAN_H
#define POO2_L4_BUFFY_HUMAN_H

#include "Humanoid.h"

class Human : public Humanoid {
public:
    Human();
    void setAction(const Field& f) override;
};

#endif //POO2_L4_BUFFY_HUMAN_H