//
// Created by gaeta on 05.05.2021.
//

#ifndef POO2_L4_BUFFY_HUMANOID_H
#define POO2_L4_BUFFY_HUMANOID_H

// sinon "... does not name a type"
class Action;

#include <cstdio>
#include "../GameLogic/Action.h"
#include "../GameLogic/Field.h"

class Humanoid {
private:
    std::size_t xPos, yPos;
    bool alive;
    Action* action;

public:
    std::size_t x() const;
    std::size_t y() const;
    void setPosition(std::size_t x, std::size_t y);
    bool isAlive() const;
    virtual void setAction(const Field& f) = 0;
    void executeAction(const Field& f);
    virtual ~Humanoid() = default;
};

#endif //POO2_L4_BUFFY_HUMANOID_H
