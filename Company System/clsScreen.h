#pragma once

#include <iostream>
#include <iomanip>
#include "clsDate.h"

using namespace std;

class clsScreen {

protected:

	static void _ScreenHeader(string Title = "Company Name") {

        utilLibrary::dashes(103);
        cout << "|==================================================================================|" << "                   |" << endl;
        cout << "|                                  \" " << Title << " \"                                |" ;
        cout << "  Date:"<< clsDate::DateToString(clsDate())<< "  |" << endl;
        cout << "|==================================================================================|" << "                   |" << endl;
        utilLibrary::dashes(103);
       
	}

};