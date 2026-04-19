#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "Driver.h"
#include "Team.h"

class Library {
private:
    std::vector<Driver> drivers;
    std::vector<Team> teams;
    std::string driversFile;
    std::string teamsFile;

public:
    Library(std::string driversFile, std::string teamsFile);

    void loadFromFiles();
    void saveToFiles() const;

    void addDriver(const Driver& driver);
    void removeDriver(const std::string& name);
    Driver* findDriver(const std::string& name);

    void addTeam(const Team& team);
    void removeTeam(const std::string& name);
    Team* findTeam(const std::string& name);

    void displayAllDrivers() const;
    void displayAllTeams() const;
    void displayDriversByTeam(const std::string& teamName) const;

    void sortDriversByWins();
    void sortTeamsByWins();
};
