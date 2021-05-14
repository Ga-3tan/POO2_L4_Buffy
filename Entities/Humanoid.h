//
// Created by gaeta on 05.05.2021.
//

#ifndef POO2_L4_BUFFY_HUMANOID_H
#define POO2_L4_BUFFY_HUMANOID_H

// sinon "... does not name a type"
class Humanoid;

#include <cstdio>
#include <iostream>
#include <memory>
#include "../GameLogic/Action.h"
#include "../GameLogic/Field.h"

class Humanoid {
    friend std::ostream& operator << (std::ostream& out, const Humanoid& o);

protected:
    std::size_t xPos, yPos;
    bool alive;
    std::shared_ptr<Action> action;
    char displayChar;
    unsigned int displayColor;

    Humanoid(char displayChar, char displayColor);
public:
    std::size_t x() const;
    std::size_t y() const;
    void setPosition(std::size_t x, std::size_t y);
    bool isAlive() const;
    virtual void setAction(const Field& f) = 0;
    void executeAction(Field &f);
    virtual ~Humanoid() = default;
};

std::ostream& operator << (std::ostream& out, const Humanoid& o);

#endif //POO2_L4_BUFFY_HUMANOID_H