#include "Menu.h"
#include <iostream>
#include <limits>

Menu::Menu(Library& lib) : lib(lib) {}

void Menu::clearScreen() const{
    #ifdef _WIN32   
        system("cls");
    #else
        system("clear");
    #endif
}

void Menu::waitForEnter() const{
    std::cout << "\nPress Enter to continue...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

void Menu::showMainMenu() const {
    clearScreen();
    std::cout << "\n";
    std::cout << "|===================================|\n";
    std::cout << "|   F1 Library Management System    |\n";
    std::cout << "|===================================|\n";
    std::cout << "| Drivers                           |\n";
    std::cout << "| 1. Display all drivers            |\n";
    std::cout << "| 2. Add driver                     |\n";
    std::cout << "| 3. Remove driver                  |\n";
    std::cout << "| 4. Find driver                    |\n";
    std::cout << "| 5. Display drivers by team        |\n";
    std::cout << "| 6. Sort drivers by wins           |\n";
    std::cout << "|===================================|\n";
    std::cout << "| TEAMS                             |\n";
    std::cout << "| 7. Display all teams              |\n";
    std::cout << "| 8. Add team                       |\n";
    std::cout << "| 9. Remove team                    |\n";
    std::cout << "| 10. Find Team                     |\n";
    std::cout << "| 11. Sort teams by wins            |\n";
    std::cout << "| 0. Exit                           |\n";
    std::cout << "|===================================|\n";

    std::cout << "\n Select an option: ";
}

void Menu::handleAddDriver(){
    clearScreen();
    std::cout << "\n=== ADD DRIVER ===\n\n";

    std::string name, nationality, teamName;
    int number, championships, wins;

    std::cin.ignore();
    std::cout << "Name         : "; std::getline(std::cin, name);
    std::cout << "Number       : "; std::cin >> number;
    std::cin.ignore();
    std::cout << "Nationality  : "; std::getline(std::cin, nationality);
    std::cout << "WCC titles   : "; std::cin >> championships;
    std::cout << "Total wins   : "; std::cin >> wins;
    std::cin.ignore();
    std::cout << "Team name    : "; std::getline(std::cin, teamName);

    lib.addDriver(Driver(name, number, nationality, championships, wins, teamName));
    waitForEnter;

}