//
// Created by gaeta on 05.05.2021.
//

#ifndef POO2_L4_BUFFY_BUFFY_H
#define POO2_L4_BUFFY_BUFFY_H

#include "Humanoid.h"

class Buffy : public Humanoid {
public:
    explicit Buffy();
    void setAction(const Field& f) override;
};

#endif //POO2_L4_BUFFY_BUFFY_H
