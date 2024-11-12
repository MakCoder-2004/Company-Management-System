#pragma once
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
using namespace std;

class utilLibrary {
public:
	static string ReadString()
	{
		string  String = "";
		cin >> String;
		return String;
	}

	static int ReadIntNumber(string ErrorMessage = "Invalid Number, Enter again\n")
	{
		int Number;
		while (!(cin >> Number)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		return abs(Number);
	}

	static double ReadFloatNumber(string ErrorMessage = "Invalid Number, Enter again\n")
	{
		float Number;
		while (!(cin >> Number)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		return abs(Number);
	}

	static double ReadDoubelNumber(string ErrorMessage = "Invalid Number, Enter again\n")
	{
		double Number;
		while (!(cin >> Number)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		return abs(Number);
	}

	static bool IsNumberBetween(int Number, int From, int To){
		if (Number >= From && Number <= To)
			return true;
		else
			return false;

	}

	static vector<string> Split(string S1, string Delim)
	{

		vector<string> vString;

		short pos = 0;
		string sWord; // define a string variable  

		// use find() function to get the position of the delimiters  
		while ((pos = S1.find(Delim)) != std::string::npos)
		{
			sWord = S1.substr(0, pos); // store the word   
			// if (sWord != "")
			// {
			vString.push_back(sWord);
			//}

			S1.erase(0, pos + Delim.length());  /* erase() until positon and move to next word. */
		}

		if (S1 != "")
		{
			vString.push_back(S1); // it adds last word of the string.
		}

		return vString;

	}

	static short ReadShortNumberBetween(short From, short To, string ErrorMessage = "Number is not within range, Enter again:\n")
	{
		int Number = ReadIntNumber();

		while (!IsNumberBetween(Number, From, To))
		{
			cout << ErrorMessage;
			Number = ReadIntNumber();
		}
		return Number;
	}

	static void dashes(int x) {
			for (int i = 0; i < x; i++) {
				cout << "-";
			}
			cout << endl;
	}
	
	static void dashes() {
		for (int i = 0; i < 128; i++) {
			cout << "-";
		}
		cout << endl;
	}
	
	
};
	