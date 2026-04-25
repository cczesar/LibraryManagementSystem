#pragma once
#include <string>
#include <iostream>
#include "Library.h"

class Menu {
    private:
    Library& lib:

    void showMainMenu() const;

    void handleAddDriver();
    void handleRemoveDriver();
    void handleFindDriver();

    void handleAddTeam();
    void handleRemoveTeam();
    void handleFindTeam();

    void clearScreen() const;
    void waitForEnter() const;

    public:
    Menu(Library& lib);
    void run();

};