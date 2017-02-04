//
// Created by Marta on 27.12.2016.
//

#ifndef PROJEKTSEMESTRALNY_KOLEJKAZDARZEN_H
#define PROJEKTSEMESTRALNY_KOLEJKAZDARZEN_H

#include <queue>
#include <cassert>
#include "Event.h"
#include "Compare.h"
//class Event;

class EventsQueue {
    std::priority_queue<const Event *, std::vector<const Event *>, Compare> events;
    int time;

public:
    EventsQueue();

    EventsQueue(EventsQueue &) = delete;

    EventsQueue &operator=(EventsQueue &) = delete;

    ~EventsQueue() = default;

    void insert(const Event *event);

    void letItHappen(int endOfTheWorld);


};

#endif //PROJEKTSEMESTRALNY_KOLEJKAZDARZEN_H
