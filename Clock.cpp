//
// Created by Marta on 15.01.2017.
//

#include "Clock.h"

int Clock::dayOfTheSimulation(int time) {

    return time / (24 * 60) + 1;
}

int Clock::dayOfTheWeek(int time) {
    int dzT = dayOfTheSimulation(time) % 7;
    if (dzT > 0) return dzT;
    else return 7;

}

bool Clock::isWeekend(int time) {
    return dayOfTheWeek(time) == 6 || dayOfTheWeek(time) == 7;
}


std::string Clock::whatTime(int time) {
    int godz = (time % (60 * 24)) / 60;
    int min = time % 60;
    return "dzień " + std::to_string(dayOfTheSimulation(time)) + " godz. " + std::to_string(godz) + ":" +
           std::to_string(min);
}

