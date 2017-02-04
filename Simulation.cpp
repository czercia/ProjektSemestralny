//
// Created by Marta on 27.12.2016.
//

#include <sstream>
#include <fstream>
#include "Simulation.h"

void Simulation::readInputData() {

    std::ifstream input;
    input.open(inputFileName);
    if( !input.good() )
    {
        //throw exception file not found
    }
    input >> lengthDays;
    for (int i = 0; i < 4; ++i) {
        int no;
        input >> no;  howManyPeopleList.push_back(no);
    }
    input >> probWorkerGoesLunch;
    input >> probGoShopping;
    input >> percStudentsTwoUnivs;
    input >> percLessTramsWeekend;

    for (int i = 0; i < 4; ++i) {
        double pr;
        input >> pr; probGoToTheatreList.push_back(pr);
    }
    input >> tramCapacity;
    input >> howManyStops;
    for (int i = 0; i < howManyStops; ++i) {
        std::string name;
        input>>name; stopNamesList.push_back(name);
    }
    input >> howManyLines;
    for (int j = 0; j < howManyLines; ++j) {
        lineNumbersList.push_back(j);
//        int howManyVeh;
//        input >> howManyVeh;
//        howManyVehiclesEachLine.push_back(howManyVeh);
        std::vector<std::string>stopNamesList1;
        std::vector<int> times;
        std::string line;
        std::getline(input, line);
        std::istringstream linestream(line); // #include <sstream>
        std::string word;
//        linestream >> word;
//        std::cout << word;
        int no = 0;
        while (linestream >> word)
        {

            if (no == 0) howManyVehiclesEachLine.push_back(stoi(word));
            else if (no %2 == 1){
                stopNamesList1.push_back(word);
            }
            else if(no %2 == 0){
                times.push_back(stoi(word));
            }
            no++;
            // process word
        }
        stopsNamesListEachLineList.push_back(stopNamesList1);
        timesEachLineList.push_back(times);
    }
//    for (int i = 0; i < howManyLines; ++i) {
//        input >> howManyPeopleList[i];
//    } miejsce
    //czasy dojazdow
//    input >> howManyUnivs;
//    for (int i = 0; i < howManyUnivs; ++i) {
//        std::string name, loc;
//        input >> name; uniNamesList.push_back(name);
//        input >> loc; uniLocationsList.push_back(loc) ;
//    }
//    input >> howManyTheatres;
//    for (int i = 0; i < howManyTheatres; ++i) {
//        std::string name, loc;
//        int cap;
//        input >> name; theatresNamesList.push_back(name);
//        input >> loc; theatresLocationsList.push_back(loc);
//        input >> cap; theatresCapacityList.push_back(cap);
//    }
//    input >> howManySC;
//    for (int i = 0; i < howManySC; ++i) {
//        std::string name, loc;
//        input >> name; scNamesList.push_back(name);
//        input >> loc; scLocationsList.push_back(loc);
//    }
    //czy jestesmy na koncu pliku?
    input.close();
}

std::ostream &operator<<(std::ostream &os, const Simulation &simulation) {
    os << "inputFileName: " << simulation.inputFileName << " lengthDays: " << simulation.lengthDays
       << " probWorkerGoesLunch: " << simulation.probWorkerGoesLunch << " probGoShopping: " << simulation.probGoShopping
       << " percStudentsTwoUnivs: " << simulation.percStudentsTwoUnivs
       <<std::endl << " percLessTramsWeekend: "
       << simulation.percLessTramsWeekend << " tramCapacity: " << simulation.tramCapacity << " howManyStops: "
       << simulation.howManyStops << std::endl;
        for(auto stopName:simulation.stopNamesList){
            os << stopName << std::endl;
        }
    os<< " howManyLines: " << simulation.howManyLines << '\n';
    for(int i = 0; i < simulation.howManyLines; i++){
        for(auto j: simulation.stopsNamesListEachLineList[i]){
            os << j <<'\t';

        }
    }

    os<< " \n howManyUnivs: "
       << simulation.howManyUnivs << " howManyTheatres: " << simulation.howManyTheatres << " howManySC: "
       << simulation.howManySC;
    return os;
}

Simulation::Simulation(const std::string &inputFileName, int length) : inputFileName(inputFileName), lengthDays(length) {
    readInputData();
}

