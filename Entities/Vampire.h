//
// Created by gaeta on 05.05.2021.
//

#ifndef POO2_L4_BUFFY_VAMPIRE_H
#define POO2_L4_BUFFY_VAMPIRE_H

#include "Vampire.h"

class Vampire : public Humanoid {
public:
    void setAction(const Field& f) override;
};

#endif //POO2_L4_BUFFY_VAMPIRE_H
