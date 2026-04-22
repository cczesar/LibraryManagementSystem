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