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
private:
    static const char DISPLAY_CHAR;
    static const std::size_t DISPLAY_COLOR;
    static const std::size_t SPEED;

    char getDisplayChar() const override;
    std::size_t getDisplayColor() const override;
    std::size_t getSpeed() const override;
public:
    void setAction(const Field& f) override;

};

#endif //POO2_L4_BUFFY_HUMAN_H