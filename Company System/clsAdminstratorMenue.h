#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsEmployee.h"
#include "clsTasks.h"
#include "clsMainMenueScreen.h"

using namespace std;



class clsAdministratorMenue : protected clsScreen, public clsEmployee, public clsTask {

protected:

    static void _GoBackToAdministratorMenue()
    {
        cout << setw(23) << left << "" << "\n\n                      Press any key to return to Administrator Menue...\n";

        system("pause>0");
        AdminstratorMenue();
    }

    static short _ReadAdministratorMenueOption()
    {
        int x = 26;
        cout << setw(x) << left << "" << "Choose From the List [1 to 10] => ";
        short Choice = utilLibrary::ReadShortNumberBetween(1, 10, "                           Enter Number between (1 to 10) ");
        return Choice;
    }

public:

    static void AdminstratorMenue() {
        
        int x = 30;

        system("cls");
        _ScreenHeader();

        cout << "                  ==================================================" << endl;
        cout << "                  |         WELCOME TO Administrator MENUE         | \n";
        cout << "                  ==================================================\n" << endl;


        cout << setw(x) << left << "" << "[1] Employees List.\n";
        cout << setw(x) << left << "" << "[2] Salaries List.\n";
        cout << setw(x) << left << "" << "[3] Search Employee Info.\n";
        cout << setw(x) << left << "" << "[4] Give Bonus.\n";
        cout << setw(x) << left << "" << "[5] Give Deduction.\n";
        cout << setw(x) << left << "" << "[6] Send Task.\n";
        cout << setw(x) << left << "" << "[7] Insert New Employee.\n";
        cout << setw(x) << left << "" << "[8] Update Employee Info.\n";
        cout << setw(x) << left << "" << "[9] Delete/Fire Employee.\n";
        cout << setw(x) << left << "" << "[10] Logout.\n\n";

        cout << setw(18) << left;
        cout << "                  ==================================================\n" << endl;

        clsEmployee Employee;
        clsTask Task;

        switch (_ReadAdministratorMenueOption()) {

        case 1:

            system("cls");
            Employee.GetEmployeesList();
            _GoBackToAdministratorMenue();

            break;

        case 2:

            system("cls");
            Employee.GetEmployeesSalaryList();
            _GoBackToAdministratorMenue();

            break;

        case 3:

            system("cls");
            Employee.SearchEmployee();
            _GoBackToAdministratorMenue();

            break;

        case 4:

            system("cls");
            Employee.GiveBonusToEmployee();
            _GoBackToAdministratorMenue();

            break;

        case 5:

            system("cls");
            Employee.GiveDeductionToEmployee();
            _GoBackToAdministratorMenue();

            break;

        case 6:

            system("cls");
            Task.SendTask();
            _GoBackToAdministratorMenue();

            break;

        case 7:

            system("cls");
            Employee.AddNewEmployee();
            _GoBackToAdministratorMenue();

            break;

        case 8:

            system("cls");
            Employee.UpdateEmployee();
            _GoBackToAdministratorMenue();

            break;

        case 9:

            system("cls");
            Employee.DeleteEmployee();
            _GoBackToAdministratorMenue();

            break;

        case 10:

            system("cls");

            break;
        }

    }
};
