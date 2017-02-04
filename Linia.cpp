//
// Created by Marta on 28.12.2016.
//

#include "Linia.h"


Linia::Linia(int numer, const std::vector<Stop *> &listOfStops, const std::vector<int> &czasyPrzejazdow,
             int numberOfVehicles, double procWeekend, std::vector<Vehicle *> listOfVehicles, EventsQueue *eventsQueue1)
        : number(numer), listOfStops(listOfStops), czasyPrzejazdow(czasyPrzejazdow),
          numberOfVehicles(numberOfVehicles), procWeekend(procWeekend), listOfVehicles(listOfVehicles),
          eventsQueue(eventsQueue1) {
    zaj1 = listOfStops.front();
    zaj2 = listOfStops.back();
    int czasPrzejazdTam = 0;
    for (auto it = czasyPrzejazdow.begin(); it != czasyPrzejazdow.end(); ++it) {
        czasPrzejazdTam += *it;
    }
    dlugoscKursu = 2 * czasPrzejazdTam;


}

std::ostream &operator<<(std::ostream &s, const Linia &linia) {
    s << "Numer linii: " << linia.number << ", Przystanki i czasy przejazdow: " << std::endl;
    for (int i = 0; i < linia.listOfStops.size(); ++i) {
        s << *linia.listOfStops[i] << "   " << linia.czasyPrzejazdow[i] << std::endl;
    }
    s << "ilość pojazdów: " << linia.numberOfVehicles << std::endl;
    s << "pojazdy: " << std::endl;
    for (int i = 0; i < linia.listOfVehicles.size(); i++) {
        s << *linia.listOfVehicles[i] << std::endl;
    }

    s << "zajezdnia 1 (początek trasy): " << *linia.zaj1 << ", zajezdnia 2 (koniec trasy): " << *linia.zaj2
      << std::endl;
    return s;

}

void Linia::newDay(int dayOfTheWeek) {
    std::cout << "opracowywanie rozkładu jazdy:" << std::endl;
    if (Clock::isWeekend(dayOfTheWeek)) {
        numberOfVehiclesNow = (int) (procWeekend * numberOfVehicles);
    } else numberOfVehiclesNow = numberOfVehicles;

    std::cout << "ilość pojazdów w zajezdniach: ";

    numberOfVehiclesZaj2 = numberOfVehiclesNow / 2;
    numberOfVehiclesZaj1 = numberOfVehiclesNow - numberOfVehiclesZaj2;

    std::cout << "1: " << numberOfVehiclesZaj1 << ", 2: " << numberOfVehiclesZaj2 << std::endl;
    std::cout << "wszystkich pojazdów: " << numberOfVehiclesNow << std::endl;
    //dla kazdego pojazdu
    int opoznienie1 = dlugoscKursu / numberOfVehiclesZaj1;
    int opoznienie2 = dlugoscKursu / numberOfVehiclesZaj2;



    //dla kazdego pojazdu z zajezdni 1

    int iloscKursow1 = (17 * 60 - opoznienie1) / dlugoscKursu + 2;
    int iloscKursow2 = (17 * 60 - opoznienie2) / dlugoscKursu + 2;

    int czasOdjazdu1 = dayOfTheWeek + 6 * 60;

    std::cout << "pojazdy z zajezdni 1 odjazdy co " << opoznienie1 << "min, dł.kursu (tam+postój+powr + postój): "
              << dlugoscKursu << ", ilość kursów dziennie kazdego pojazdu: " << iloscKursow1 << std::endl;
    std::cout << "pojazdy z zajezdni 2 odjazdy co " << opoznienie2 << "min, ilość kursów dziennie kazdego pojazdu: "
              << iloscKursow2 << std::endl;

    for (int k = 0; k < numberOfVehiclesZaj1; k++) {
        int start = 0;
        int fin = listOfStops.size();
        int diff = 1;
        for (int j = 0; j < iloscKursow1; j++) {
            int czasOdjazdu = czasOdjazdu1 + j * dlugoscKursu;
            for (int i = start; i < fin; i += diff) {
                if (i > 0) czasOdjazdu += czasyPrzejazdow[i - 1];
                std::string name = "odjazd z: " + listOfStops[i]->getName() + " kurs " + std::to_string(j) + " time: " +
                                   std::to_string(czasOdjazdu);
                Event *zdarzenie = new Event(czasOdjazdu, *listOfVehicles[k], *eventsQueue, name);
                eventsQueue->insert(zdarzenie);

            }
            for (int i = fin - 1; i >= start; i--) {
                czasOdjazdu += czasyPrzejazdow[i];
                std::string name = "odjazd z: " + listOfStops[i]->getName() + " kurs " + std::to_string(j) + " time: " +
                                   std::to_string(czasOdjazdu);
                Event *zdarzenie = new Event(czasOdjazdu, *listOfVehicles[k], *eventsQueue, name);
                eventsQueue->insert(zdarzenie);
            }
        }
    }
    std::cout << "DRUGA ZAJEZDNIA" << std::endl;
    for (int k = numberOfVehiclesZaj1; k < numberOfVehiclesNow; k++) {
        int start = listOfStops.size() - 1;
        int fin = 0;
        int diff = 1;
        for (int j = 0; j < iloscKursow2; j++) {
            int czasOdjazdu = czasOdjazdu1 + j * dlugoscKursu;
            for (int i = start; i >= fin; i--) {
                if (i < start) czasOdjazdu += czasyPrzejazdow[i];
                std::string name = "odjazd z: " + listOfStops[i]->getName() + " kurs " + std::to_string(j) + " time: " +
                                   std::to_string(czasOdjazdu);
                Event *zdarzenie = new Event(czasOdjazdu, *listOfVehicles[k], *eventsQueue, name);
                eventsQueue->insert(zdarzenie);

            }

//            std::cout << "POWRÓT" << std::endl;
            czasOdjazdu += czasyPrzejazdow[start];
            for (int i = fin; i <= start; i++) {
                if (i > fin)
                    czasOdjazdu += czasyPrzejazdow[i - 1];
                std::string name = "odjazd z: " + listOfStops[i]->getName() + " kurs " + std::to_string(j) + " time: " +
                                   std::to_string(czasOdjazdu);
                Event *zdarzenie = new Event(czasOdjazdu, *listOfVehicles[k], *eventsQueue, name);
                eventsQueue->insert(zdarzenie);
            }
        }
    }


}




