//
// Created by marta on 04.02.17.
//
#include <iostream>
#include "Tram.h"

Tram::Tram(int cap, int id) :id(id), capacity(cap){
    std::cout << "Utworzono pojazd o pojemnosci " << cap <<", id: " << id << std::endl;

}

const std::string Tram::getDescription() const {
    return " Tram no.: "+ std::to_string(id);
}

std::ostream &operator<<(std::ostream &s, const Tram &p)  {
    return s << "Tram no.: " << p.id ;
}

