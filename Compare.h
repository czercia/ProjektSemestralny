//
// Created by Marta on 29.12.2016.
//

#ifndef PROJEKTSEMESTRALNY_COMPARE_H
#define PROJEKTSEMESTRALNY_COMPARE_H

#include "Event.h"

class Event;


class Compare {

public:
    bool operator()(const Event *z1, const Event *z2);
};


#endif //PROJEKTSEMESTRALNY_COMPARE_H
