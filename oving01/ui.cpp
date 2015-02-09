#include <iostream>
#include "ui.h"

using namespace std;

int promptInt() {
	int i = 0;
	bool valid = false;
	
	do {
		cin >> i;
		
		valid = !cin.fail();
		cin.clear();
		cin.ignore();
		
		if (!valid)
			cout << "Ikke et tall!" << endl;
	} while (!valid);
	
	return i;
}

double promptDouble() {
	double i = 0;
	bool valid = false;
	
	do {
		cin >> i;
		
		valid = !cin.fail();
		cin.clear();
		cin.ignore();
		
		if (!valid)
			cout << "Ikke et tall!" << endl;
	} while (!valid);
	
	return i;
}
