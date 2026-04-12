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
    library(std::string driversFile, std::string teamsFile);

    void loadFromFiles();
    void saveToFiles() const;


    void addDriver(const Driver& driver);
    void removeDriver(const std::string& name);
    Team* findTeam(const std::string& name);
    void displayAllTeams();

    void displayDriverByTeam(const std::string& teamName) const;
    void sortDriverByWins();
    void sortTeamByWins();
};