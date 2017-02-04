//
// Created by Marta on 27.12.2016.
//

#include <iostream>
#include "Vehicle.h"

Vehicle::Vehicle(int cap, int id) :id(id){
    capacity = cap;
    std::cout << "Utworzono pojazd o pojemnosci " << cap <<", id: " << id << std::endl;

}


std::ostream &operator<<(std::ostream &s, const Vehicle &p)  {
    return s << "Vehicle nr " << p.id ;
}
