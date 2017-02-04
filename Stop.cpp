//
// Created by Marta on 28.12.2016.
//

#include "Stop.h"

Stop::Stop(const std::string &name) : name(name) {
    std::cout << "Utworzono przystanek o nazwie: " << name << std::endl;
//    listOfPeopleIn.empty();
}

std::ostream &operator<<(std::ostream &s, Stop &p) {
    s << "Stop " << p.name <<std::endl;
    if(!p.listOfPeopleIn.empty()){
    s<< "lista osób czekających na przystanku " << p.name <<":" <<std::endl;
    for (int i = 0;  i< p.listOfPeopleIn.size() ; i++) {
        s << *p.listOfPeopleIn[i] << std::endl;
    }} else s << "Nikt nie czeka na tym przystanku" << std::endl;
    return s;
}

const std::string &Stop::getName() const {
    return name;
}

void Stop::addToWaitingList(Person *person) {
    listOfPeopleIn.push_back(person);

}

void Stop::removeFromWaitingList(Person *person) {
    for (auto i = listOfPeopleIn.begin(); i <listOfPeopleIn.end() ; ++i) {
        if(*i == person){
            listOfPeopleIn.erase(i);
            break;
        }
    }

}
