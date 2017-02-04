//
// Created by marta on 24.01.17.
//

#ifndef PROJEKTSEMESTRALNYTESTOWANIE_OSOBA_H
#define PROJEKTSEMESTRALNYTESTOWANIE_OSOBA_H


#include <ostream>

class Person {
int id;
public:
    Person(int id);

    friend std::ostream &operator<<(std::ostream &os, const Person &person);

    ~Person() = default;


};


#endif //PROJEKTSEMESTRALNYTESTOWANIE_OSOBA_H
