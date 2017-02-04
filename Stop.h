//
// Created by Marta on 28.12.2016.
//

#ifndef PROJEKTSEMESTRALNY_PRZYSTANEK_H
#define PROJEKTSEMESTRALNY_PRZYSTANEK_H

#include <iostream>
#include <string>
#include <vector>
#include "Person.h"


class Stop {
    std::string name;
    std::vector<Person *> listOfPeopleIn;

public:
    Stop(const std::string &name);

    ~Stop() = default;

//    Stop(const Stop &) = delete;

//    Stop &operator=(const Stop &) = delete;

    const std::string &getName() const;

    friend std::ostream&operator<<(std::ostream&s, Stop& p);

    void addToWaitingList(Person *person);

    void removeFromWaitingList(Person *person);

};


#endif //PROJEKTSEMESTRALNY_PRZYSTANEK_H
