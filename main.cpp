#include <iostream>
#include <Driver.h>
#include <Team.h>

"""date of data: 2026-04-06"""
int main(){
    Team mercedes("Mercedes", "Germany", 8, 134);
    Team redbull("Redbull", "Austria", 6, 130);
    team ferrari("Ferrari", "Italy", 16, 248);
    team mclaren("McLaren", "England", 10, 203);


mercedes.addDriver("George Russel");
mercedes.addDriver("Kimi Antonelli");

redbull.addDriver("Max Verstappen");
redbull.addDriver("Isack Hadjar");

ferrari.addDriver("Charles Leclerc");
ferrari.addDriver("Lewis Hamilton")

mclaren.addDriver("Lando Norris");
mclaren.addDriver("Oscar Piastri");

Driver russel("George Russel", 63, "British", 0, 6, "Mercedes");
Driver antonelli("Kimi Antonelli", 12, "Italian", 0, 2, "Mercedes");
Driver verstappen("Max Verstappen", 3, "Dutch", 4, 71, "Redbull");
Driver hadjar("Isack Hadjar", 6, "French", 0, 0, "Redbull");
Driver leclerc("Charles Leclerc", 16, "Monegasque", 0, 8, "Ferrari");
Driver hamilton("Lewis Hamilton", 44, "British", 7, 105, "Ferrari");
Driver norris("Lando Norris", 1, "British", 1, 11, "McLaren");
Driver piastri("Oscar Piastri", 81 "Australian", 0, 9, "McLaren");


std::cout << "\n=== TEAMS ===\n\n";
mercedes.display();
redbull.display();
ferrari.display();
mclaren.display();

std::cout <<"\n=== DRIVERS ===\n\n";
russel.display();
antonelli.display();
verstappen.display();
hadjar.display();
leclerc.display();
hamilton.display();
norris.display();
piastri.display();


std::cout << "\n=== QUICK LISTING ===\n\n";
std::cout << russel << "\n";
std::cout << antonelli << "\n";
std::cout << verstappen << "\n";
std::cout << hadjar << "\n";
std::cout << leclerc << "\n";
std::cout << hamilton << "\n";
std::cout << norris << "\n";
std::cout << piastri << "\n";

std::cout << "\n=== CSV Output ===\n\n";
std::cout << russel.toCSV() << "\n";
std::cout << antonelli.toCSV() << "\n";
std::cout << verstappen.toCSV() << "\n";
std::cout << hadjar.toCSV() << "\n";
std::cout << leclerc.toCSV() << "\n";
std::cout << hamilton.toCSV() << "\n";
std::cout << norris.toCSV() << "\n";
std::cout << piastri.toCSV() << "\n";

std::cout << "\n=== EQUALITY TEST ===\n\n";
if (hamilton == hamilton)
    std::cout << "same driver\n";
if (!(hamilton == verstappen))
    std::cout << "Different drivers\n";
if (mercedes == mercedes)
    std::cout << "Same team\n"
if (!(mercedes == ferrari))
    std::cout << "Different teams\n";


std::cout << "\n=== HAS DRIVER TEST ===\n\n";
    if (mercedes.hasDriver("George Russel"))
        std::cout << "Hamilton is in mercedes\n";
    if (!mercedes.hasDriver("Max Verstappen"))
    std::cout << "Verstappen is NOT in mercedes AND AINT WINNING SHI\n";

    return 0;
}