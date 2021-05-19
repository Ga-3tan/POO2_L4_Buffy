//
// Created by gaeta on 05.05.2021.
//

#ifndef POO2_L4_BUFFY_VAMPIRE_H
#define POO2_L4_BUFFY_VAMPIRE_H

#include "Humanoid.h"

class Vampire : public Humanoid {
public:
    explicit Vampire();
    void setAction(const Field& f) override;
    std::shared_ptr<Action> attackHumanoid(Humanoid* victim) override;
};

#endif //POO2_L4_BUFFY_VAMPIRE_H
