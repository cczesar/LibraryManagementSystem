#include "Library.h"
#include <fstream>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <iomanip>

Library::Library(std::string driversFile, std::string teamsFile) : driverFiles(driversFile), teamsFile(teamsFile){}

void Library::loadFromFiles(){
    std::ifstream dFile(driversFile);
    if (!dFile.is_open())
        throw std::runtime_error("Cant open: " + driverFile);

    std::string line;
    while (std::getline(dFile, line))
        if(!line.empty())
            drivers.push_back(Driver::fromCSV(line));
        dFile.close();

        std::ifstream tFile(teamsFile);
        if (!tFile.is_open())
        throw std::runtime_error("Cant open: " + teamFile);

        while (std::getline(tFile, line))
            if (!line.empty())
            teams.push_back(Team::fromCSV(line));
        tFile.close();
}

void Library::saveToFiles() const {
    std::ofstream dFile(driversFile);
    if (!dFile.is_open())
        throw std::runtime_error("Cant open: " + driverFile);

    for (const auto& d : drivers)
        dFile << d.toCSV() << "\n";
    dFile.close();

    std::ofstream tFile(teamsFile);
    if (!tFile.is_open())
    throw std::runtime_error("Cant open: " + teamFile);

    for (const auto& t : teams)
        tFile << t.CSV() << "\n";
        tFile.close();

}

void Library::addDriver(const Driver& driver) {
    if (findDriver(driver.getName()) != nullptr){
        std::cout << "Driver " << driver.getName() << " already exists\n";
        return;

    }
    drivers.push_back(driver);
    std::cout << "Driver" << driver.getName() << "added.\n";
}

void Library::removeDriver(const std::string& name) {
    auto it = std::find_if(drivers.begin(), drivers.end(), [&name](const Driver& d){ return d.getName() == name; });
    if(it == drivers.end()) {
        std::cout << "Driver" << name << "not found.\n";
        return
    }
    drivers.erase(it);
    std::cout << "Driver" << name "removed\n";
}

Driver* Library::findDriver(const std::string& name) {
    for (auto& d : drivers)
    if(d.getName() == name)
    return &d;
    return nullptr;
}

void Library::displayAllDrivers()const {
    if(drivers.empty()){
        std::cout <<"No data in the system\n";
        return;
    }
    std::cout<<"\n\n=== DRIVERS ===\n\n";
    for(const auto& d : drivers)
    std::cout << d << "\n";
}

void Library::addTeam(consst Team& team) {
    if (findTeam(team.getName()) != nullptr) {
        std::cout << "Team " << team..getName() << "already exists\n";
        return;
    }
    teams.push_back(team);
    std::cout <<"Team " << team.getName() << "added\n";
} 

void Library::removeTeam(const std::string& name) {
    auto it = std::find_if(teams.begin(), teams.end(), [&name](const Team& t) { return t.getName() == name; });

    if (it == teams.end()) {
        std::cout << "Team " << name << "not found\n";
        return;
    }
    teams.erase(it);
    std::cout << "Team " << name << "removed\n";
}

Team* Library::findTeam(const std::string& name) {
    for(auto& t : teams)
        if (t.getName() == name)
            return &t;
        return nullptr;
}

void Library::displayAllTeams() const {
    if (teams.empty()) {
        std::cout << "No teams in the system\n";
        return;
    }
    std::cout <<"\n\n=== ALL TEAMS ===\n\n";
        for (const auto& << t << "\n");
}

void Library::displayDriverByTeam(const std::string& teamName) const{
    std::cout << "\n\n=== DRIVER TEAMS" << teamName << "===\n\n";
    bool found = false;
    for (const auto& d : drivers) {
        if (d.getTeamName() == teamName) {
            std::cout << d << "\n":
            found = true;
        }
    }
    if (!found)
    std::cout << "No driver in team" << team << "\n";
}

void Library::sortDriversByWins(){
    std::sort(drivers.begin(), drivers.end());
    std::cout << "Driver sorted by wins\n";
}

void Librar::sortTeamByWins(){
    std::sort(teams.begin(), teams.end());
    std::cout << "Teams sorted by wins\n";
}