//
// Created by Marta on 27.12.2016.
//

#ifndef PROJEKTSEMESTRALNY_POJAZD_H
#define PROJEKTSEMESTRALNY_POJAZD_H

#include <string>
#include <ostream>


class Vehicle {
    int id;
    int capacity;
    int numberOfPeopleInside;
    bool wTrasie;

public:
    Vehicle() {};

    Vehicle(int cap, int id);

    Vehicle(const Vehicle &) = default;

    Vehicle &operator=(Vehicle &) = delete;

    virtual ~Vehicle() = default;

    friend std::ostream &operator<<(std::ostream &s, const Vehicle &p);

    virtual const std::string getDescription() const = 0;


};


#endif //PROJEKTSEMESTRALNY_POJAZD_H
