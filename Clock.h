//
// Created by Marta on 15.01.2017.
//

#ifndef PROJEKTSEMESTRALNY_ZEGAR_H
#define PROJEKTSEMESTRALNY_ZEGAR_H

#include <string>


class Clock {


public:
    static int dayOfTheSimulation(int time);

    static int dayOfTheWeek(int time);

    static std::string whatTime(int time);

    static bool isWeekend(int time);

};


#endif //PROJEKTSEMESTRALNY_ZEGAR_H
