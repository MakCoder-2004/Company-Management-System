#pragma once

#include <iostream>
#include <iomanip>

#include "clsScreen.h"
#include "clsLogInScreen.h"
#include "clsAdminstratorMenue.h"
#include "clsEmployeeMenue.h"
#include "clsDescription.h"

#include "utilLibrary.h"


using namespace std;

class clsMainMenueScreen : protected clsScreen {

protected:

    static short _ReadMainMenueOption()
    {
        int x = 26;
        cout << setw(x) << left << "" << "Choose From the List [1 to 3] => ";
        short Choice = utilLibrary::ReadShortNumberBetween(1, 3, "                           Enter Number between (1 to 3) ");
        return Choice;
    }

    static  void _GoBackToMainMenueScreen()
    {
        cout << "                  ==================================================" << endl;
        cout << setw(23) << left << "" << "\n                      Press any key to return to Main Menue...\n";

        system("pause>0");
        ShowMainMenueScreen();
    }

    static void Exit() {
        clsEmployee::Find("", "");
    }

public:

    static void ShowMainMenueScreen() {

        system("cls");
        _ScreenHeader();
        int x = 30;

        cout << "                  ==================================================" << endl;
        cout << "                  |                   Main Menue                   | \n";
        cout << "                  ==================================================\n" << endl;

        cout << setw(x) << left << "" << "[1] Log In.\n\n";
        cout << setw(x) << left << "" << "[2] Description.\n\n";
        cout << setw(x) << left << "" << "[3] Exit.\n\n";

        cout << setw(18) << left;
        cout << "                  ==================================================\n" << endl;


        switch(_ReadMainMenueOption()) {
        case 1:

            system("cls");
            clsLogInScreen::LogInScreen("EmployeesFile.txt");
            _GoBackToMainMenueScreen();

            break;
        case 2:

            system("cls");
            clsDescription::ShowDescription();
            _GoBackToMainMenueScreen();

            break;
        case 3:

            system("cls");
            Exit();

            break;

        }
    }
};
