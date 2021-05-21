//
// Created by gaeta on 05.05.2021.
//

#ifndef POO2_L4_BUFFY_BUFFY_H
#define POO2_L4_BUFFY_BUFFY_H

#include "Humanoid.h"

class Buffy : public Humanoid {
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

#endif //POO2_L4_BUFFY_BUFFY_H
