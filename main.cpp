#include <iostream>
#include "Vehicle.h"
#include "EventsQueue.h"
#include "Compare.h"
#include "Linia.h"
#include "Stop.h"
#include "Simulation.h"
#include "Event.h"
#include "Clock.h"
#include "Tram.h"
using namespace std;
void test1();
void test2();

int main() {

test2();


}

void test1(){cout << "Test" << endl;
    cout << "Tworzenie listy osób:" <<endl;
    std::vector<Person> osoby;
    for (int j = 0; j < 5; ++j) {
        Person osoba(j);
        osoby.push_back(osoba);
    }
    std::vector<Person*> osobyWsk;
    for (int j = 0; j < 5; ++j) {
        osobyWsk.push_back(&osoby[j]);
    }

    cout << "Tworzenie przystankow:" << endl;
    Stop przystanek1 = Stop("Przyst1");
    przystanek1.addToWaitingList(osobyWsk[0]);
    std::cout << przystanek1 << endl;
    przystanek1.removeFromWaitingList(osobyWsk[0]);
    std::cout << przystanek1 << endl;


    cout << "Tworzenie pojazdów:" << endl;
    std::vector<Tram> pojazdy;
    for (int i = 0; i < 3; ++i) {
        Tram pojazd(10, i);
        pojazdy.push_back(pojazd);
    }

    EventsQueue kolejkaZdarzen;
//    Event zdarzenie(2, pojazdy[0], eventsQueue, std::__cxx11::string());
//    Event zdarzenie2(3, pojazdy[1], eventsQueue, std::__cxx11::string());
//    Event zdarzenie1(1, pojazdy[2], eventsQueue, std::__cxx11::string());
//    eventsQueue.insert(&zdarzenie);
//    eventsQueue.insert(&zdarzenie2);
//    eventsQueue.insert(&zdarzenie1);
//    eventsQueue.letItHappen(10);

    cout << "Tworzenie linii:" <<endl;
    cout << "Tworzenie listy pojazdów:" << endl;
//    std::vector<Vehicle> pojazds;
//    for (int i = 0; i < 3; ++i) {
//        Vehicle pojazd(10, i);
//        pojazds.push_back(pojazd);
//    }
//    std::vector<Vehicle*> pojazdy2;
//    for (int i = 0; i < 2; ++i) {
//        pojazdy2.push_back(&pojazds[i]);
//    }
    cout << "Tworzenie listy tramwajów:" << endl;
    std::vector<Tram> pojazds;
    for (int i = 0; i < 3; ++i) {
        Tram pojazd(10, i);
        pojazds.push_back(pojazd);
    }
    std::vector<Vehicle*> pojazdy2;
    for (int i = 0; i < 2; ++i) {
        pojazdy2.push_back(&pojazds[i]);
    }
    cout << "Tworzenie listy przystanków i czasów przejazdów:" << endl;

    std::vector<Stop> przystanki;
    for (int i = 0; i < 3; ++i) {
        Stop przystanek("przystanek nr "+to_string(i));
        przystanki.push_back(przystanek);
    }
    std::vector<Stop*> przystankiWsk;
    std::vector<int> czasyPrzejazdow;
    for (int i = 0; i < 3; ++i) {
        przystankiWsk.push_back(&przystanki[i]);
        czasyPrzejazdow.push_back(i*i+i+50);
    }
    cout << "Tworzenie linii tramwajowej" << endl;
    Linia linia(111, przystankiWsk, czasyPrzejazdow, 2, 0.7, pojazdy2, &kolejkaZdarzen);
    std::cout << linia;
    linia.newDay(1);

    kolejkaZdarzen.letItHappen(4000);}

void test2() {
    Simulation simulation("dane.txt", 4000);
    cout << simulation;
//    simulation.readInputData();
}



