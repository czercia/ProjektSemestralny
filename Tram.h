//
// Created by marta on 04.02.17.
//

#ifndef PROJEKTSEMESTRALNYTESTOWANIE_TRAM_H
#define PROJEKTSEMESTRALNYTESTOWANIE_TRAM_H

#include <string>
#include <ostream>
#include "Vehicle.h"


class Tram : public Vehicle {
    int id;
    int capacity;
    int numberOfPeopleInside;
    bool wTrasie;

public:
    Tram(int cap, int id);

    Tram(const Tram &) = default;

    Tram &operator=(Tram &) = delete;

    ~Tram() = default;

    friend std::ostream &operator<<(std::ostream &s, const Tram &p);

    const std::string getDescription() const override ;


};

#endif //PROJEKTSEMESTRALNYTESTOWANIE_TRAM_H
