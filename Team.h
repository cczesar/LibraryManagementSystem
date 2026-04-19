#pragma once
#include <string>
#include <vector>
#include <iosfwd>

class Team {
    private:
    std::string name;
    std::string country;
    int wcc;
    int totalWins;
    std::vector <std::string> driverNames;

    public:
    Team();
    Team (std::string name, std::string country, 
            int wcc, int totalWins);

            std::string getName() const { return name; }
            std::string getCountry() const { return country; }
            int getWcc() const { return wcc; }
            int getTotalWins() const { return totalWins; }

            void setName(const std::string& n) {
                name = n;
            }
            void setCountry(const std::string& c){
                country = c;
            }
            void setConstructorTitles(int t){
                wcc = t;
            }
            void setTotalWins(int w){
                totalWins = w;
            }

            void addDriver(const std::string& driverName);
            void removeDriver(const std::string& driverName);
            bool hasDriver(const std::string& driverName) const;

            void display() const;

            std::string toCSV() const;
            static Team fromCSV(const std::string& line);

            bool operator==(const Team& other) const;
            bool operator<(const Team& other) const;
            friend std::ostream& operator<<(std::ostream& os, const Team& t);
};