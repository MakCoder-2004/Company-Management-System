#pragma once

#include <iostream>
#include "clsMainMenueScreen.h"
#include "clsScreen.h"
#include "clsTasks.h"

using namespace std;

int x = 30;

class clsEmployeeMenue : protected clsScreen, public clsEmployee, public clsTask {

protected:

    static void _GoBackToEmployeeMenue(string& EmployeeId)
    {
        cout << setw(23) << left << "" << "\n                      Press any key to return to Employee Menue...\n";

        system("pause>0");

        // Pass EmployeeId when calling EmployeeMenue
        EmployeeMenue(EmployeeId);
    }

    static short _ReadAdministratorMenueOption()
    {
        int x = 26;
        cout << setw(x) << left << "" << "Choose From the List [1 to 10] => ";
        short Choice = utilLibrary::ReadShortNumberBetween(1, 10, "                           Enter Number between (1 to 10) ");
        return Choice;
    }

public:

    static void EmployeeMenue(string& EmployeeId) {

        system("cls");
        _ScreenHeader();

        clsEmployee Employee = Find(EmployeeId, "EmployeesFile.txt");
        clsTask Task;

        cout << "                  ==================================================" << endl;
        cout << "                  |                 Employee MENUE                 | \n";
        cout << "                               Welcome Mr. ";
        cout << Employee.FullName() << "\n";
        cout << "                  ==================================================\n" << endl;

        cout << setw(x) << left << "" << "[1] See my info.\n";
        cout << setw(x) << left << "" << "[2] Update my info.\n";
        cout << setw(x) << left << "" << "[3] See Tasks.\n";
        cout << setw(x) << left << "" << "[4] Logout.\n\n";

        cout << setw(18) << left;
        cout << "                  ==================================================\n" << endl;



        switch (_ReadAdministratorMenueOption()) {

        case 1:

            system("cls");

            Employee.Print();
            _GoBackToEmployeeMenue(EmployeeId);

            break;

        case 2:

            system("cls");

            Employee.UpdateEmployeeById(Employee.Id);
            _GoBackToEmployeeMenue(EmployeeId);

            break;

        case 3:

            system("cls");
            Task = FindTask(EmployeeId, "TasksFile.txt");
            _GoBackToEmployeeMenue(EmployeeId);

            break;

        case 4:

            system("cls");

            break;
        }
    }
};
