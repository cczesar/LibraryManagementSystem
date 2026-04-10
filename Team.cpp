#include "Team.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <utility>

Team::Team()
    : name(""), country(""), wcc(0), totalWins(0) {}

Team::Team(std::string name, std::string country,
           int wcc, int totalWins)
    : name(std::move(name)),
      country(std::move(country)),
      wcc(wcc),
      totalWins(totalWins) {}

void Team::addDriver(const std::string& driverName) {
    if (!hasDriver(driverName)) {
        driverNames.push_back(driverName);
    }
}

void Team::removeDriver(const std::string& driverName){
    driverNames.erase(
        std::remove(driverNames.begin(), driverNames.end(), driverName),
        driverNames.end()
    );
}

bool Team::hasDriver(const std::string& driverName) const{
    return std::find(driverNames.begin(), driverNames.end(), driverName) != driverNames.end();
}


void Team::display() const{
    std::cout <<"|-----------------------------------|\n";
    std::cout <<"| Team Profile                      |\n";
    std::cout <<"|-----------------------------------|\n";
    std::cout <<"| Name         : " << std::left << std::setw(23)<< name      << "|\n";
    std::cout <<"| Country      : " << std::left << std::setw(23)<< country   << "|\n";
    std::cout <<"| WCC          : " << std::left << std::setw(23)<< wcc       << "|\n";
    std::cout <<"| Total Wins   : " << std::left << std::setw(23)<< totalWins << "|\n";
    std::cout <<"|-----------------------------------|\n";
    std::cout <<"| Drivers                           |\n";
    for (const auto& d : driverNames) {
        std::cout << "|   - " << std::left << std::setw(32) << d << "|\n";
    }
    std::cout <<"|-----------------------------------|\n";
}

std::string Team::toCSV() const{
    std::string drivers;
    for (size_t i = 0; i < driverNames.size(); i++) {
        drivers += driverNames[i];
        if(i + 1 < driverNames.size()) drivers += "|";
    }

    return name + "," +
           country + "," +
           std::to_string(wcc) + "," +
           std::to_string(totalWins) + "," +
           drivers;
}

Team Team::fromCSV(const std::string& line){
    std::stringstream ss(line);
    std::string token;
    std::vector<std::string> fields;

    while (std::getline(ss, token, ',')) {
        fields.push_back(token);
    }

    if(fields.size() != 5) {
        throw std::invalid_argument("Invalid CSV line for Team: " + line);
    }

    Team t(fields[0], fields[1], std::stoi(fields[2]), std::stoi(fields[3]));

    std::stringstream ds(fields[4]);
    std::string driver;
    while (std::getline(ds, driver, '|')) {
        if (!driver.empty()) t.addDriver(driver);
    }

    return t;
}

    bool Team::operator==(const Team& other) const {
        return name == other.name;
    }

    bool Team::operator <(const Team& other) const{
        return totalWins > other.totalWins;
    }

    std::ostream& operator<<(std::ostream& os, const Team& t){
        os << std::left
           << std::setw(20) << t.name 
           << std::setw(15) << t.country
           <<"WCC: " << std::setw(4) << t.wcc
           <<"Wins: " << t.totalWins;
           return os;
    }