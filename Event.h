//
// Created by Marta on 29.12.2016.
//

#ifndef PROJEKTSEMESTRALNY_ZDARZENIE_H
#define PROJEKTSEMESTRALNY_ZDARZENIE_H

#include <string>
#include <iostream>
#include "Vehicle.h"
//#include "EventsQueue.h"
//#include "Obiekt.h"
#include "Compare.h"

class EventsQueue;

class Event {
    int startTime;
    Vehicle &who;
    EventsQueue &queue;
    std::string description;

public:
    //konstruktorki itp
//    Event(int czasRozp, Vehicle &obiekt, EventsQueue &eventsQueue);
    Event(int startTime, Vehicle &who, EventsQueue &eventsQueue, std::string desc);

//    Event() = delete;

//    Event(Event &) = delete;

//    Event &operator=(const Event &) = delete;

//     ~Event() {std::cout << "destruktor : zdarzenie" << std::endl;};

    //get
    int getStartTime() const;

    std::string getDescription() const;

    //reszta
    void amen() const;

};


#endif //PROJEKTSEMESTRALNY_ZDARZENIE_H
