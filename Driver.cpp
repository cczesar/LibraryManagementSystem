#include "Driver.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <stdexcept>
#include <vector>


Driver::Driver()
    : name(""), number(0), nationality(""),
    championships(0), wins(0), team(""){}

Driver::Driver(std::string name, int number, std::string nationality,
                int championships, int wins, std::string team)
                : name(name), number(number), nationality(nationality),
                championships(championships), wins(wins), team(team){}

void Driver::display() const{
    std::cout <<"|-----------------------------------|\n";
    std::cout <<"| Driver Profile                    |\n";
    std::cout <<"|-----------------------------------|\n";
    std::cout <<"| Name        : " << std::left << std::setw(23)<< name          << "|\n";
    std::cout <<"| Number      : " << std::left << std::setw(23)<< number        << "|\n";
    std::cout <<"| Nationality : " << std::left << std::setw(23)<< nationality   << "|\n";
    std::cout <<"| Team        : " << std::left << std::setw(23)<< team          << "|\n";
    std::cout <<"| Wins        : " << std::left << std::setw(23)<< wins          << "|\n";
    std::cout <<"| Titles WDC  : " << std::left << std::setw(23)<< championships << "|\n";
    std::cout <<"|-----------------------------------|\n";

}

std::string Driver::toCSV() const{
    return name + "," +
    std::to_string(number) + "," +
    nationality + "," +
    std::to_string(championships) + "," +
    std::to_string(wins) + "," +
    team;
}

Driver Driver::fromCSV(const std::string& line){
    std::stringstream ss(line);
    std::string token;
    std::vector<std::string> fields;

    while (std::getline(ss, token, ',')) {
        fields.push_back(token);
    }

    if(fields.size() != 6) {
        throw std::invalid_argument("Invalid CSV line for driver: " + line);
    }

    return Driver(
        fields[0],
        std::stoi(fields[1]),
        fields[2],
        std::stoi(fields[3]),
        std::stoi(fields[4]),
        fields[5]
    );
}

bool Driver::operator==(const Driver& other) const {
    return number == other.number;
}

bool Driver::operator<(const Driver& other) const{
    // sort by wins descending (more wins = "smaller" for std::sort)
    if (wins != other.wins) return wins > other.wins;
    return number < other.number;
}

std::ostream& operator<<(std::ostream& os, const Driver& d){
     os << std::left
        << std::setw(25) << d.name
        << " #" << std::setw(4) << d.number
        << std::setw(14) << d.nationality
        << std::setw(18) << d.team
        << "W: " << std::setw(4) << d.wins
        << "T: " << d.championships;
     return os;
} 