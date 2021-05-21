//
// Created by gaeta on 05.05.2021.
//

#ifndef POO2_L4_BUFFY_HUMANOID_H
#define POO2_L4_BUFFY_HUMANOID_H

class Humanoid;

#include <cstdio>
#include <iostream>
#include <memory>
#include "../Actions/Action.h"
#include "../../Utils/Coordinate.h"


class Humanoid {
    friend std::ostream& operator << (std::ostream& out, const Humanoid& o);
protected:
    Coordinate position;
    bool alive;
    std::shared_ptr<Action> action;

    Humanoid();
    std::shared_ptr<Action> moveRandomly(const Field& f);
    std::shared_ptr<Action> chaseHumanoid(const Field& f, const std::type_info& humanoidType);
    virtual std::shared_ptr<Action> attackHumanoid(Humanoid* victim);

    virtual char getDisplayChar() const = 0;
    virtual std::size_t getDisplayColor() const = 0;
    virtual std::size_t getSpeed() const = 0;
public:
    std::size_t x() const;
    std::size_t y() const;
    void setPosition(std::size_t x, std::size_t y);
    bool isAlive() const;
    void die();
    virtual void setAction(const Field& f) = 0;
    void executeAction(Field &f);
    virtual ~Humanoid() = default;
};

std::ostream& operator << (std::ostream& out, const Humanoid& o);

#endif //POO2_L4_BUFFY_HUMANOID_H