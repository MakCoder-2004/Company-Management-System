#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include "clsPerson.h"
#include "utilLibrary.h"

using namespace std;

class clsEmployee : public clsPerson {

private:

	string _Id;
	string _Email;
	string _Password;
	string _PassHint;
	string _Department;
	float _Salary;

	bool _MarkedForDelete = false;


	//--------------------- fstream library Functions ------------------

	//Converting the Data in The TXT file into the class variable data
	static clsEmployee _ConvertLinetoObject(string Line, string Seperator = "#//#") {
		vector<string> vEmployeeData = utilLibrary::Split(Line, Seperator);

		if (vEmployeeData.size() < 10) {
			throw std::length_error("Insufficient data in line, unable to create clsEmployee object.");
		}

		return clsEmployee(
			vEmployeeData[0], // FirstName
			vEmployeeData[1], // LastName
			vEmployeeData[2], // BirthDate
			vEmployeeData[3], // PhoneNumber
			vEmployeeData[4], // Id
			vEmployeeData[5], // Email
			vEmployeeData[6], // Password
			vEmployeeData[7], // PassHint
			vEmployeeData[8], // Department
			stod(vEmployeeData[9]) // Salary (converted from string to double)
		);
	}

	//Converting the class variables data to TXT FIle
	static string _ConvertObjectToLine(clsEmployee Employee, string Seperator = "#//#")
	{

		string stEmployeeRecord = "";
		stEmployeeRecord += Employee.FirstName + Seperator;
		stEmployeeRecord += Employee.LastName + Seperator;
		stEmployeeRecord += Employee.BirthDate + Seperator;
		stEmployeeRecord += Employee.PhoneNumber + Seperator;
		stEmployeeRecord += Employee.Id + Seperator;
		stEmployeeRecord += Employee.Email + Seperator;
		stEmployeeRecord += Employee.Password + Seperator;
		stEmployeeRecord += Employee.PassHint + Seperator;
		stEmployeeRecord += Employee.Department + Seperator;
		stEmployeeRecord += to_string(Employee.Salary);

		return stEmployeeRecord;

	}

	//Add Data To the TXT File
	static void _AddDataLineToFile(string  stDataLine)
	{
		fstream MyFile;
		MyFile.open("EmployeesFile.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{

			MyFile << stDataLine << endl;

			MyFile.close();
		}

	}

	//Save Data from Vector To TXT file
	static void _SaveDataToFile(vector <clsEmployee> vEmployee) {
		string DataLine;

		fstream EmployeeFile;
		EmployeeFile.open("EmployeesFile.txt", ios::out); //overwrite only

		if (EmployeeFile.is_open()) {
			for (clsEmployee E : vEmployee) {
				if (E.MarkedForDelete() == false) {

					DataLine = _ConvertObjectToLine(E);

					EmployeeFile << DataLine << endl;
				}
			}
		}
	}

	//Load Data from TXT file to vector
	static  vector <clsEmployee> _LoadDataFromFile()
	{
		vector <clsEmployee> vEmployees;

		fstream MyFile;
		MyFile.open("EmployeesFile.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				clsEmployee Employee = _ConvertLinetoObject(Line);
				vEmployees.push_back(Employee);
			}

			MyFile.close();

		}
		return vEmployees;
	}

	//--------------------------------------------------------------------


	//Return Empty Employee info 
	static clsEmployee _GetEmptyObject()
	{
		return clsEmployee("", "", "", "", "", "", "", "", "", 0);
	}

public:

	//Default Constructor
	clsEmployee() = default;

	//Parametrized Constructor
	clsEmployee(string FirstName, string LastName, string BirthDate, string PhoneNumber, string Id, string Email, string Password, string PassHint, string Department , float Salary)
		: clsPerson(FirstName, LastName, BirthDate, PhoneNumber)
	{
		_Id = Id;
		_Email = Email;
		_Password = Password;
		_PassHint = PassHint;
		_Department = Department;
		_Salary = Salary;
	}


	//Id Read Only
	string GetId() {
		return _Id;
	}
	__declspec(property(get = GetId)) string Id;

	//MarkForDelete
	bool MarkedForDelete() {
		return _MarkedForDelete;
	}

	//Email Setter and Getter
	void SetEmail(string Email) {
		_Email = Email;
	}
	string GetEmail() {
		return _Email;
	}
	__declspec(property(get = GetEmail, put = SetEmail)) string Email;



	//Password Setter and Getter
	void SetPassword(string Password) {
		_Password = Password;
	}
	string GetPassword() {
		return _Password;
	}
	__declspec(property(get = GetPassword, put = SetPassword)) string Password;



	//PassHint Setter and Getter
	void SetPassHint(string PassHint) {
		_PassHint = PassHint;
	}
	string GetPassHint() {
		return _PassHint;
	}
	__declspec(property(get = GetPassHint, put = SetPassHint)) string PassHint;



	//Department Setter and Getter
	void SetDepartment(string Department) {
		_Department = Department;
	}
	string GetDepartment() {
		return _Department;
	}
	__declspec(property(get = GetDepartment, put = SetDepartment)) string Department;



	//Salary Setter and Getter
	void SetSalary(float Salary)
	{
		_Salary = Salary;
	}
	float GetSalary()
	{
		return _Salary;
	}
	__declspec(property(get = GetSalary, put = SetSalary)) float Salary;


	string SaveEmployeeId() {

		clsEmployee::GetId();
		return GetId();
	}

	//Print Employee Info
	void Print() {
		cout << "\n\n Employee Info :-" << endl;
		cout << "------------------------------------------ " << endl;
		cout << " Employee ID  : " << Id << endl;
		cout << " First Name   : " << FirstName << endl;
		cout << " Last Name    : " << LastName << endl;
		cout << " Full Name    : " << FullName() << endl;
		cout << " Birth Date   : " << BirthDate << endl;
		cout << " Phone Number : " << PhoneNumber << endl;
		cout << " Email        : " << Email << endl;
		cout << " Department   : " << Department << endl;
		cout << " Salary       : " << Salary << endl;
		cout << "------------------------------------------ " << endl;
	}

	//Find Emplyee
	static clsEmployee Find(string Id, string File)
	{

		fstream EmployeesFile;
		EmployeesFile.open(File, ios::in); //read Mode

		if (EmployeesFile.is_open())
		{
			string Line;
			while (getline(EmployeesFile, Line))
			{
				clsEmployee Employee = _ConvertLinetoObject(Line);
				if (Employee.Id == Id)
				{
					EmployeesFile.close();
					return Employee;
				}

			}

			EmployeesFile.close();

		}

		return _GetEmptyObject();
	}

	//Is Employee Exist or no
	static bool IsIdExist(string Id, string File)
	{
		bool existance = false;

		clsEmployee Employee = clsEmployee::Find(Id, File);

		if (!empty(Employee.Id)) {
			existance = true;
		}

		return existance;
	}

	//Inputing Info of Employee From Administrator Menue
	static void ReadEmployeeData(clsEmployee &Employee) {

		cout << "\nEnter Employee 's FirstName: ";
		Employee.FirstName = utilLibrary::ReadString();

		cout << "\nEnter Employee 's LastName: ";
		Employee.LastName = utilLibrary::ReadString();

		cout << "\nEnter Employee 's Birth Date (DD-MM-YYYY): ";
		Employee.BirthDate = utilLibrary::ReadString();

		cout << "\nEnter Employee 's Phone Number: ";
		Employee.PhoneNumber = utilLibrary::ReadString();

		cout << "\nEnter Employee 's Email: ";
		Employee.Email = utilLibrary::ReadString();

		cout << "\nEnter Employee 's Password: ";
		Employee.Password = utilLibrary::ReadString();

		cout << "\nEnter Employee 's Password Hint: ";
		Employee.PassHint = utilLibrary::ReadString();

		cout << "\nEnter Employee 's Department: ";
		Employee.Department = utilLibrary::ReadString();

		cout << "\nEnter Employee 's Salary: ";
		Employee.Salary = utilLibrary::ReadFloatNumber();
		
	}

	//Inputing Info of Employee From Employee Menue
	static void UpdateEmployeeData(clsEmployee& Employee) {

		cout << "\nEnter Employee 's FirstName: ";
		Employee.FirstName = utilLibrary::ReadString();

		cout << "\nEnter Employee 's LastName: ";
		Employee.LastName = utilLibrary::ReadString();

		cout << "\nEnter Employee 's Birth Date (DD-MM-YYYY): ";
		Employee.BirthDate = utilLibrary::ReadString();

		cout << "\nEnter Employee 's Phone Number: ";
		Employee.PhoneNumber = utilLibrary::ReadString();

		cout << "\nEnter Employee 's Email: ";
		Employee.Email = utilLibrary::ReadString();

		cout << "\nEnter Employee 's Password: ";
		Employee.Password = utilLibrary::ReadString();

		cout << "\nEnter Employee 's Password Hint: ";
		Employee.PassHint = utilLibrary::ReadString();


	}


	//********* Manage Employees ************
 
	//Insert New Employee 

	void AddNewEmployee()
	{
		string Id = "";

		cout << "\nPlease Enter Employee 's ID: ";
		Id = utilLibrary::ReadString();

		while (clsEmployee::IsIdExist(Id, "EmployeesFile.txt"))
		{
			cout << "\nEmployee ID Is Already Used, Choose another one: ";
			Id = utilLibrary::ReadString();
		}

		clsEmployee NewEmployee("", "", "", "", Id, "", "", "", "", 0);

		ReadEmployeeData(NewEmployee);

		_AddDataLineToFile(_ConvertObjectToLine(NewEmployee));

		NewEmployee.Print();
	}

	//Update Employee info
	void UpdateEmployee() {

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

		vector <clsEmployee> _vEmployee;
		_vEmployee = _LoadDataFromFile();

		// Iterate through the list until we find the employee with the ID we entered
		for (clsEmployee& E : _vEmployee) {
			if (E.Id == Id) {
				E = *this;
				break;
			}
		}

		// Save the updated list back to the file
		_SaveDataToFile(_vEmployee);

		Employee.Print();
	}

	void UpdateEmployeeById(string Id) {
		clsEmployee Employee = clsEmployee::Find(Id, "EmployeesFile.txt");

		cout << "\nUpdate My Info :" << endl;
		cout << "-----------------------------" << endl;

		clsEmployee::UpdateEmployeeData(Employee);

		vector <clsEmployee> _vEmployee;
		_vEmployee = _LoadDataFromFile();

		// Iterate through the list until we find the employee with the ID we entered
		for (clsEmployee& E : _vEmployee) {
			if (E.Id == Id) {
				E = *this;
				break;
			}
		}

		// Save the updated list back to the file
		_SaveDataToFile(_vEmployee);

		Employee.Print();
	}

	//Delete Employee 
	void DeleteEmployee() {
		string Id = "";

		cout << "\nPlease Enter Employee's ID: ";
		Id = utilLibrary::ReadString();

		while (!clsEmployee::IsIdExist(Id, "EmployeesFile.txt")) {
			cout << "\nEmployee ID doesn't exist, Choose another one: ";
			Id = utilLibrary::ReadString();
		}

		clsEmployee DeleteEmployee = Find(Id, "EmployeesFile.txt");
		DeleteEmployee.Print();

		cout << "\nAre you sure you want to delete (fire) this employee? (Y/N): ";
		char ans;
		cin >> ans;

		if (ans == 'Y' || ans == 'y') {
			vector<clsEmployee> _vEmployees;
			_vEmployees = _LoadDataFromFile(); // Load current employee data from file

			// Iterate through the list and mark the employee for deletion
			for (clsEmployee& C : _vEmployees) {
				if (C.Id == DeleteEmployee.Id) {
					C._MarkedForDelete = true;
					break;
				}
			}

			// Save the updated list back to the file
			_SaveDataToFile(_vEmployees);

			// Mark the current object as an empty employee
			*this = _GetEmptyObject();

			cout << "\nEmployee Deleted/Fired Successfully\n";
		}
		else {
			cout << "\nOperation Cancelled.\n";
		}
	}

	//List of All Employees
	void GetEmployeesList() {

		vector <clsEmployee> _vEmployees = _LoadDataFromFile();

		//Dashes
		cout << endl;
		utilLibrary::dashes();

		//Head
		cout << "|                                               ";
		cout << "Employees List ( " << _vEmployees.size() << " Employees )";
		cout << "                                                 |" << endl;
		
		//Dashes
		utilLibrary::dashes();

		//Topics
		cout << "| " << left << setw(9) << "ID";
		cout << "| " << left << setw(19) << "Employee Name";
		cout << "| " << left << setw(14) << "BirthDate";
		cout << "| " << left << setw(14) << "Phone Number";
		cout << "| " << left << setw(23) << "Email";
		cout << "| " << left << setw(10) << "Password";
		cout << "| " << left << setw(13) << "Department";
		cout << "| " << left << setw(9) << "Salary" << "|" << endl;

		//Dashes
		utilLibrary::dashes();

		//Body
		if (_vEmployees.size() == 0) {
			cout << "                                             ";
			cout << "No Clients Available in this sysytem !";
			cout << "                                             " << endl;
		}
		else {
			for (clsEmployee& Employee : _vEmployees) {

				cout << "| " << left << setw(9) << Employee.Id;
				cout << "| " << left << setw(19) << Employee.FullName();
				cout << "| " << left << setw(14) << Employee.BirthDate;
				cout << "| " << left << setw(14) << Employee.PhoneNumber;
				cout << "| " << left << setw(23) << Employee.Email;
				cout << "| " << left << setw(10) << Employee.Password;
				cout << "| " << left << setw(13) << Employee.Department;
				cout << "| " << left << setw(9) << Employee.Salary << "|" << endl;
			}
		}

		//Dashes
		utilLibrary::dashes();

	}

	//Count Total Salaries
	static double GetTotalSalaries() {
		vector <clsEmployee> _vEmployees = _LoadDataFromFile();

		double TotalSalaries = 0;
		for (clsEmployee &E : _vEmployees)
		{
			TotalSalaries += E.Salary;
		}
		return TotalSalaries;
	}

	//List of All Employees' Salary
	void GetEmployeesSalaryList() {
	
		vector <clsEmployee> _vEmployees = _LoadDataFromFile();

		//Dashes
		cout << endl;
		utilLibrary::dashes(84);

		//Head
		cout << "|                          ";
		cout << "Employees List ( " << _vEmployees.size() << " Employees )";
		cout << "                          |" << endl;

		//Dashes
		utilLibrary::dashes(84);

		//Topics
		cout << "| " << left << setw(9) << "ID";
		cout << "| " << left << setw(19) << "Employee Name";
		cout << "| " << left << setw(23) << "Email";
		cout << "| " << left << setw(13) << "Department";
		cout << "| " << left << setw(9) << "Salary" << "|" << endl;

		//Dashes
		utilLibrary::dashes(84);

		//Body
		if (_vEmployees.size() == 0) {
			cout << "                                    ";
			cout << "No Clients Available in this sysytem !";
			cout << "                                   " << endl;
		}
		else {
			for (clsEmployee& Employee : _vEmployees) {

				cout << "| " << left << setw(9) << Employee.Id;
				cout << "| " << left << setw(19) << Employee.FullName();
				cout << "| " << left << setw(23) << Employee.Email;
				cout << "| " << left << setw(13) << Employee.Department;
				cout << "| " << left << setw(9) << Employee.Salary << "|" << endl;
			}
		}

		//Dashes
		utilLibrary::dashes(84);

		cout << "\t\t- Total Salaries :" << GetTotalSalaries() << " -" << endl;
	}
	
	//Search Emplyee By ID
	void SearchEmployee() {

		string Id = "";

		cout << "\nPlease Enter Employee 's ID: ";
		Id = utilLibrary::ReadString();

		while (!clsEmployee::IsIdExist(Id, "EmployeesFile.txt"))
		{
			cout << "\nEmployee ID doesn't exist, Choose another one: ";
			Id = utilLibrary::ReadString();
		}


		if (IsIdExist(Id, "EmployeesFile.txt")) {

			clsEmployee Employee = Find(Id, "EmployeesFile.txt");
			Employee.Print();
		}
		else {
			cout << "\nNo Employee Exists with This ID !\n";
		}
	}

	//Give Bonus to Employee
	void GiveBonusToEmployee() {
		string Id = "";

		cout << "\nPlease Enter Employee 's ID: ";
		Id = utilLibrary::ReadString();

		// Check if employee ID exists in the file
		while (!clsEmployee::IsIdExist(Id, "EmployeesFile.txt")) {
			cout << "\nEmployee ID doesn't exist, Choose another one: ";
			Id = utilLibrary::ReadString();
		}

		// Retrieve the employee object
		clsEmployee Employee = clsEmployee::Find(Id, "EmployeesFile.txt");

		// Display current salary
		cout << "\nHis Current Salary is " << Employee.Salary << endl;

		double bonus = 0;
		cout << "\nEnter Bonus Value: ";
		bonus = utilLibrary::ReadDoubelNumber();

		// Update the employee's salary by adding the bonus
		Employee.Salary += bonus;

		// Load all employees from file to update
		vector<clsEmployee> _vEmployee = _LoadDataFromFile();

		// Update the employee in the list
		for (clsEmployee& E : _vEmployee) {
			if (E.Id == Id) {
				E.Salary = Employee.Salary;  // Update the salary
				break;
			}
		}

		// Save the updated list back to the file
		_SaveDataToFile(_vEmployee);

		// Display the success message
		cout << "\nEmployee's Bonus Added successfully!\n";
		cout << "\nSalary After Bonus: " << Employee.Salary << endl;
	}

	//Give Deduction to Employee
	void GiveDeductionToEmployee() {
		string Id = "";

		cout << "\nPlease Enter Employee 's ID: ";
		Id = utilLibrary::ReadString();

		// Check if employee ID exists in the file
		while (!clsEmployee::IsIdExist(Id, "EmployeesFile.txt")) {
			cout << "\nEmployee ID doesn't exist, Choose another one: ";
			Id = utilLibrary::ReadString();
		}

		// Retrieve the employee object
		clsEmployee Employee = clsEmployee::Find(Id, "EmployeesFile.txt");

		// Display current salary
		cout << "\nHis Current Salary is " << Employee.Salary << endl;

		double deduction = 0;
		cout << "\nEnter Deduction Value: ";
		deduction = utilLibrary::ReadDoubelNumber();

		// Update the employee's salary by subtracting the deduction
		Employee.Salary -= deduction;

		// Load all employees from file to update
		vector<clsEmployee> _vEmployee = _LoadDataFromFile();

		// Update the employee in the list
		for (clsEmployee& E : _vEmployee) {
			if (E.Id == Id) {
				E.Salary = Employee.Salary;  // Update the salary
				break;
			}
		}

		// Save the updated list back to the file
		_SaveDataToFile(_vEmployee);

		// Display the success message
		cout << "\nDeduction made successfully!\n";
		cout << "\nSalary After Deduction: " << Employee.Salary << endl;
	}



};
