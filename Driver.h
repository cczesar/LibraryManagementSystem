#pragma once
#include <string>
#include <iosfwd>

class Driver {
    private:
    std::string name;
    int number;
    std::string nationality;
    int championships;
    int wins;
    std::string team;

    public:
    Driver();
    Driver (std::string name, int number, std::string nationality, 
            int championships, int wins, std::string team);

            std::string getName() const { return name; }
            int getNumber() const { return number; }
            std::string getNationality() const { return nationality; }
            int getChampionships() const { return championships; }
            int getWins() const { return wins; }
            std::string getTeam() const { return team; }


            void setName (const std::string& n)
              { name = n; }
            void setNumber(int n) {
                number = n;
            }
            void setNationality(const std::string& n) {
                nationality = n;
            }
            void setChampionships(int c){
                championships = c;
            }
            void setWins(int winX){
                wins = winX;
            }
            void setTeamName(const std::string& t) {
                team = t;
            }

            void display() const;

            std::string toCSV() const;
            static Driver fromCSV(const std::string& line);

            bool operator==(const Driver& other) const;
            bool operator<(const Driver& other) const;
            friend std::ostream& operator<<(std::ostream& os, const Driver& d);
};