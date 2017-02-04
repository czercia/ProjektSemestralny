//
// Created by Marta on 29.12.2016.
//

#include "Compare.h"

bool Compare::operator()(const Event *z1, const Event *z2) {
    return z1->getStartTime() > z2->getStartTime();
}
