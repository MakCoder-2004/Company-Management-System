#pragma once

#include <iostream>
using namespace std;

class clsPerson {

private:

	string _FirstName;
	string _LastName;
	string _BirthDate;
	string _PhoneNumber;

public:

	//Default Constructor
	clsPerson(){}

	//Parametrized Constructor
	clsPerson(string FirstName, string LastName, string BirthDate, string PhoneNumber) {

		_FirstName = FirstName;
		_LastName = LastName;
		_BirthDate = BirthDate;
		_PhoneNumber = PhoneNumber;

	}
	

	//FirstName Setter and Getter
	void SetFirstName(string FirstName) {
		_FirstName = FirstName;
	}
	string GetFirstName() {
		return _FirstName;
	}
	__declspec(property(get = GetFirstName, put = SetFirstName)) string FirstName;


	//LastName Setter and Getter
	void SetLastName(string LastName) {
		_LastName = LastName;
	}
	string GetLastName() {
		return _LastName;
	}
	__declspec(property(get = GetLastName, put = SetLastName)) string LastName;



	//FullName
	string FullName() {
		return (_FirstName + " " + _LastName);
	}



	//BirthDate Setter and Getter
	void SetBirthDate(string BirthDate) {
		_BirthDate = BirthDate;
	}
	string GetBirthDate() {
		return _BirthDate;
	}
	__declspec(property(get = GetBirthDate, put = SetBirthDate)) string BirthDate;



	//PhoneNumber Setter and Getter
	void SetPhoneNumber(string PhoneNumber) {
		_PhoneNumber = PhoneNumber;
	}
	string GetPhoneNumber() {
		return _PhoneNumber;
	}
	__declspec(property(get = GetPhoneNumber, put = SetPhoneNumber)) string PhoneNumber;


};
