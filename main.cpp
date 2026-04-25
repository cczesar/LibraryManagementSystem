#include <iostream>
#include "Driver.h"
#include "Library.h"
#include "Team.h"
#include "Menu.h"

// date of data: 2026-04-06
int main() {
    Library lib("data/drivers.csv", "data/teams.csv");

    Team mercedes("Mercedes", "Germany", 8, 134);
    Team redbull("Redbull", "Austria", 6, 130);
    Team ferrari("Ferrari", "Italy", 16, 248);
    Team mclaren("McLaren", "England", 10, 203);

    mercedes.addDriver("George Russel");
    mercedes.addDriver("Kimi Antonelli");

    redbull.addDriver("Max Verstappen");
    redbull.addDriver("Isack Hadjar");

    ferrari.addDriver("Charles Leclerc");
    ferrari.addDriver("Lewis Hamilton");

    mclaren.addDriver("Lando Norris");
    mclaren.addDriver("Oscar Piastri");

    lib.addTeam(mercedes);
    lib.addTeam(redbull);
    lib.addTeam(ferrari);
    lib.addTeam(mclaren);

    lib.addDriver(Driver("George Russel", 63, "British", 0, 6, "Mercedes"));
    lib.addDriver(Driver("Kimi Antonelli", 12, "Italian", 0, 2, "Mercedes"));
    lib.addDriver(Driver("Max Verstappen", 3, "Dutch", 4, 71, "Redbull"));
    lib.addDriver(Driver("Isack Hadjar", 6, "French", 0, 0, "Redbull"));
    lib.addDriver(Driver("Charles Leclerc", 16, "Monegasque", 0, 8, "Ferrari"));
    lib.addDriver(Driver("Lewis Hamilton", 44, "British", 7, 105, "Ferrari"));
    lib.addDriver(Driver("Lando Norris", 1, "British", 1, 11, "McLaren"));
    lib.addDriver(Driver("Oscar Piastri", 81, "Australian", 0, 9, "McLaren"));

    lib.displayAllTeams();
    lib.displayAllDrivers();

    std::cout << "\n=== find and modify ===\n\n";
    Driver* d = lib.findDriver("Lando Norris");
    if (d != nullptr) {
        std::cout << *d << "\n";
    }

    Team* t = lib.findTeam("McLaren");
    if (t != nullptr) {
        std::cout << *t << "\n";
    }

    lib.displayDriversByTeam("Ferrari");
    lib.displayDriversByTeam("McLaren");
    lib.displayDriversByTeam("Mercedes");
    lib.displayDriversByTeam("Redbull");

    std::cout << "\n=== sorted by wins ===\n\n";
    lib.sortDriversByWins();
    lib.displayAllDrivers();

    lib.sortTeamsByWins();
    lib.displayAllTeams();

    try {
        lib.saveToFiles();
        std::cout << "\nData saved to CSV successfully \n";
    } catch (const std::runtime_error& e) {
        std::cout << "Error saving: " << e.what() << "\n";
    }

    Menu menu(lib);
    menu.run();

    return 0;
}
