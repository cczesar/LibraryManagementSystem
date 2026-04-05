#pragma once
#include <string>
#include <vector>
#include <iostran>

class Team {
    private:
    std::string name;
    std::string country;
    int WCC;
    int totalWins;
    std::vector <std::string> driverNames;

    public:
    Team();
    Team (std::string name, std::string country, 
            int WCC, int totalWins);

            void setName(const std::string& n) {
                name = n;
            }
            void setCountry(const std::string& c){
                country = c;
            }
            void setConstructorTitles(int t){
                setConstructorTitles = t;
            }
            void setTotalWins(int w){
                totalWins = w;
            }

            void addDriver(const std::string& driverName);
            void removerDriver(const std::string& driverName);
            bool hasDriver(const std::string& driverName) const;

            void display() const;

            std::string() toCSV() const;
            static Team fromCSV(const std::string& line);

            bool operator==(const Team& other) const;
            bool operator<(const Team& other) const;
            friend std::ostream& operator<<(std::ostream& os, const Team& t);
    };