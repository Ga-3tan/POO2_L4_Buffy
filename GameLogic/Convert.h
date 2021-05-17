//
// Created by Marco on 17.05.2021.
//

#ifndef POO2_L4_BUFFY_CONVERT_H
#define POO2_L4_BUFFY_CONVERT_H

#include "Action.h"

class Convert : public Action {
public:
    Convert(Humanoid* actor);
    void execute(Field &field) override;
};

#endif //POO2_L4_BUFFY_CONVERT_H
