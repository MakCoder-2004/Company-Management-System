#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsEmployee.h"
#include "utilLibrary.h"

using namespace std;

class clsUpdateEmployeeScreen {

public:

	 static void UpdateEmployee() {

		string Id = "";

		cout << "\nPlease Enter Employee 's ID: ";
		Id = utilLibrary::ReadString();

		while (!clsEmployee::IsIdExist(Id, "EmployeesFile.txt"))
		{
			cout << "\nEmployee ID doesn't exist, Choose another one: ";
			Id = utilLibrary::ReadString();
		}

		clsEmployee Employee = clsEmployee::Find(Id, "EmployeesFile.txt");
		Employee.Print();

		cout << "\nUpdate Client Info :" << endl;
		cout << "-----------------------------" << endl;

		clsEmployee::ReadEmployeeData(Employee);


		

	 }

};