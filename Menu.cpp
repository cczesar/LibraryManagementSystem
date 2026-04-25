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

void Menu::handleRemoveDriver(){
    clearScreen();
    std::cout << "\n=== REMOVE DRIVER ===\n\n";

    std::string name;
    std::cin.ignore();
    std::cout << "Driver name: ";
    std::getline(std::cin, name);

    lib.removeDriver(name);
    waitForEnter();
}

void Menu::handleFindDriver(){
    clearScreen();
    std::cout << "\n=== FIND DRIVER ===\n\n";

    std::string name;
    std::cin.ignore();
    std::cout << "Driver name: ";
    std::getline(std::cin, name);

    lib.removeDriver(name);
    waitForEnter();
}

void Menu::handleFindDriver(){
    clearScreen();
    std::cout <<"\n=== FIND DRIVER ===\n\n";
    std::string name;
    std::cin.ignore();
    std::cout << "Driver name: ";
    std::getline(std::cin, name);

    Driver* d = lib.findDriver(name);
    if (d != nullptr)
        d->display();
    else
        std::cout << "Driver " << name << " not found\n";

        waitForEnter();
}

void Menu::handleAddTeam(){
    clearScreen();
    std::cout <<"\n=== ADD TEAM ===\n\n";

    std::string name;
    std::cin.ignore();
    std::cout << "Team name: ";
    std::getline(std::cin, name);

    lib.removeTeam(name);
    waitForEnter();
}

void Menu::handleFindTeam(){
    clearScreen();
    std::cout << "\n=== FIND TEAM ===\n\n";

    std::string name;
    std::cin.ignore();
    std::cout << "Team name: ";
    std::getline(std::cin, name);

    Team* t = lib.findTeam(name);
    if (t != nullptr)
        t->display();
    else
        std::cout << "Team " << name << " Not found\n";
    waitForEnter();
}

void Menu::run(){
    int option;

    do{
        showMainMenu();
        std::cin >> option;

        switch (option) {
            case 1:
            clearScreen();
            lib.displayAllDrivers();
            waitForEnter();
            break;
            case 2:
            handleAddDriver();
            break;
            case 3:
            handleRemoveDriver();
            break;
            case 4:
            handleFindDriver();
            break;
            case 5:{
            clearScreen();
            std::string teamName;
            std::cin.ignore();
            std::cout << "\nTeam name: ";
            std::getline(std::cin, teamName);
            lib.displayDriversByTeam(teamName);
            waitForEnter();
            break;

        }
            case 6:
            clearScreen();
            lib.sortDriversByWins();
            lib.displayAllDrivers();
            waitForEnter();
            break;
            
            case 7:
            clearScreen();
            lib.displayAllTeams();
            waitForEnter();
            break;
            
            case 8:
            handleAddTeam();
            break;

            case 9:
            handleRemoveTeam();
            break;

            case 10:
            handleFindTeam();
            break;

            case 11:
            clearScreen();
            lib.sortTeamByWins();
            lib.displayAllTeams();
            waitForEnter();
            break;

            case 0:
            clearScreen();
            std::cout << "\nSaving data... \n";
            try {
                lib.saveToFiles();
                std::cout << "Data saved successfully.\n";
            }
            catch (const std::runtime_error& e){
                std::cout << "Error saving: " << e.what() << "\n";
            }
            std::cout << "Goodbye.\n\n";
            break;
            
            default:
            std::cout << "\nInvalid option. Try again.\n";
            waitForEnter();
            break;
    }

        } while (option != 0);       
}