//
// Created by Marta on 27.12.2016.
//
#include <iostream>
#include "EventsQueue.h"
#include <memory>

class Event;


void EventsQueue::insert(const Event *event) {
    assert(time <= event->getStartTime());
    events.push(event);
//    std::cout << "Wstawianie do kolejki:" << std::endl;
//    std::cout << event->getDescription() << std::endl;
//    std::cout << "Wstawiono" << std::endl;

}

void EventsQueue::letItHappen(int endOfTheWorld) {
std::cout << "Kolejka się dzieje!" << std::endl;
    while(!events.empty() and time<= endOfTheWorld){
//        std::cout << "kolejne:" << std::endl;
        const Event* zdarzenie = events.top();
//        std::unique_ptr<const Event> zdarzen= events.top();
        time = zdarzenie->getStartTime();
//        std::cout << time << std::endl;
//        std::cout << time << ": " << zdarzenie->getDescription() << std::endl;
        zdarzenie -> amen();
        events.pop();
        delete zdarzenie;
    }



}

EventsQueue::EventsQueue() {
    time = 0;

}
