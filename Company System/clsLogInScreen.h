#pragma once

#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "utilLibrary.h"
#include "clsEmployee.h"
#include "clsEmployeeMenue.h"
#include "clsAdminstratorMenue.h"

using namespace std;


class clsLogInScreen : protected clsScreen {

private:

	static bool _validateUser(string Id, string Password,string File) {

		if (clsEmployee::IsIdExist(Id, File)) {
			clsEmployee Employee = clsEmployee::Find(Id, File);

			if (Employee.Id == Id && Employee.Password == Password) {
				clsEmployeeMenue::EmployeeMenue(Id);
				return true;
			}
			else if (Employee.Id == Id && Employee.Password != Password) {
				cout << setw(x) << left << "" << "! InCorrect Password ! \n";
				cout << setw(x) << left << "" << "Password Hint => " << Employee.PassHint << endl;
				// forget password func.
			}
		}
		else {
			cout << setw(x) << left << "" << "     ! InCorrect ID ! \n";
		}
		return false;
	}

public:

	static void LogInScreen(string File = "EmployeesFile.txt") {

		system("cls");
		_ScreenHeader();

		cout << "                  ==================================================" << endl;
		cout << "                                       Login Menue                  \n";
		cout << "                  ==================================================\n" << endl;


		string Id = "";
		cout << setw(x) << left << "" << "- Enter your ID : ";
		Id = utilLibrary::ReadString();
		cout << endl;

		string password = "";
		cout << setw(x) << left << "" << "- Enter your Password : ";
		password = utilLibrary::ReadString();
		cout << endl;

		if (_validateUser(Id,password,"EmployeesFile.txt")) {

			clsEmployee Employee = clsEmployee::Find(Id,"EmployeesFile.txt");
			clsEmployeeMenue::EmployeeMenue(Id);

		}else if (Id == "admin" && password == "ADMIN1234") {

			clsAdministratorMenue::AdminstratorMenue();
		}
	}
	
	
};