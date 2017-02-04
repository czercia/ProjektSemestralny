//
// Created by Marta on 29.12.2016.
//

#include <iostream>
#include "Event.h"
#include "Clock.h"

int Event::getStartTime() const {
    return startTime;

}

std::string Event::getDescription() const {
    return description + who.getDescription();
}

Event::Event(int startTime, Vehicle &who, EventsQueue &eventsQueue, std::string desc)
        : startTime(startTime),
          who(who), queue(eventsQueue) {
    this->description = desc;
}

void Event::amen() const {
    std::cout  << Clock::whatTime(startTime) << ": " << getDescription() << ": amen!" << std::endl;

}
