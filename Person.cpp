//
// Created by marta on 24.01.17.
//

#include "Person.h"

Person::Person(int id) : id(id) {}

std::ostream &operator<<(std::ostream &os, const Person &person) {
    os << "Person nr: " << person.id;
    return os;
}
