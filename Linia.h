//
// Created by Marta on 28.12.2016.
//

#ifndef PROJEKTSEMESTRALNY_LINIA_H
#define PROJEKTSEMESTRALNY_LINIA_H

#include <vector>
#include <iostream>
#include "Vehicle.h"
#include "Stop.h"
#include "Clock.h"
#include "EventsQueue.h"

class Linia {
    int number;
    int dlugoscKursu; //time calego kursu: tam+postoj+powrot+postoj
    std::vector<Stop *> listOfStops;
    std::vector<int> czasyPrzejazdow;
    Stop *zaj1;
    Stop *zaj2;
    EventsQueue *eventsQueue;

    //Flota
    int numberOfVehicles;
    int numberOfVehiclesNow; //jak weekend to mniej
    double procWeekend;
    int numberOfVehiclesZaj1;
    int numberOfVehiclesZaj2;
    std::vector<Vehicle *> listOfVehicles;
    std::vector<Vehicle *> listOfVehiclesZaj1; //w zajezdni pierwszej
    std::vector<Vehicle *> listOfVehiclesZaj2; //w zajezdni drugiej


public:
    //Konstruktorki, destruktorki itp
    Linia() = delete;

//    Linia(int nr, std::vector<int> czasyPrzej, std::vector<Stop *> listaPrzyst,
//              std::vector<Vehicle *> listOfVehicles, double procWeekend);

    Linia(int numer, const std::vector<Stop *> &listOfStops, const std::vector<int> &czasyPrzejazdow,
          int numberOfVehicles, double procWeekend, std::vector<Vehicle *> listOfVehicles, EventsQueue *eventsQueue1);

    Linia(const Linia &) = delete;

    Linia &operator=(Linia &) = delete;

    friend std::ostream &operator<<(std::ostream &s, const Linia &linia);

    void newDay(int dayOfTheWeek);

    //
//    void wczytajTrase();
};


#endif //PROJEKTSEMESTRALNY_LINIA_H
