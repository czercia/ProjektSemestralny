//
// Created by Marta on 27.12.2016.
//

#ifndef PROJEKTSEMESTRALNY_SYMULACJA_H
#define PROJEKTSEMESTRALNY_SYMULACJA_H

#include <vector>
#include <sstream>
#include <queue>
#include <ostream>
#include "EventsQueue.h"
#include "Stop.h"
//#include "Miejsce.h"
//#include "Teatr.h"


class Simulation {
    EventsQueue eventsQueue;
    std::string inputFileName;

    int lengthDays;
    std::vector<int> howManyPeopleList;
    double probWorkerGoesLunch;
    double probGoShopping;
    int percStudentsTwoUnivs;
    int percLessTramsWeekend;
    std::vector<double> probGoToTheatreList;
    int tramCapacity;
    int howManyStops;
    std::vector<std::string> stopNamesList;
    int howManyLines;
    std::vector<int> lineNumbersList;
    std::vector<int> howManyVehiclesEachLine;
    std::vector<std::vector<std::string>> stopsNamesListEachLineList;
    std::vector<std::vector<int>> timesEachLineList;
    //trasa w postaci par miejsce, czas dojazdu. Ostatni czas, to czas postoju na
    //pętli, zakładamy, że taki sam w obu pętlach, miejsca typu string, czasy typu int
    int howManyUnivs;
    std::vector<std::string> uniNamesList;
    std::vector<std::string> uniLocationsList;
    int howManyTheatres;
    std::vector<std::string> theatresNamesList;
    std::vector<std::string> theatresLocationsList;
    std::vector<int> theatresCapacityList;
    int howManySC;
    std::vector<std::string> scNamesList;
    std::vector<std::string> scLocationsList;
    std::vector<Stop> listOfStops;

//    std::vector<Teatr> listaTeatrow;
    void readInputData();

public:

    friend std::ostream &operator<<(std::ostream &os, const Simulation &simulation);

    Simulation(const std::string &inputFileName, int length);

    Simulation() = delete;

    Simulation(const Simulation &) = delete;

    ~Simulation() = default;



//    class InputError{};
//    class WrongValue: public InputError{
//    public:
//        WrongValue();
//    };



//    void start();


};


#endif //PROJEKTSEMESTRALNY_SYMULACJA_H
