#include <iostream>
#include "oppg1.h"
#include "ui.h"

using namespace std;

int main() {
	// a)
	getAndPrintInteger();
	
	// b)
	cout << getAndReturnInteger() << endl;
	
	// c)
	/*
	getAndPrintInteger() reads an integer from the console and prints in back. 
	It has return type void because it does not return anything. 
	getAndReturnInteger() reads an integer from the console and returns it. 
	It has return type int because it returns the integer. 
	Setning 5...
	*/
	
	// d)
	getAndPrintSum();
	
	// e)
	/*
	Only one of the functions is usable; the one which return the integer instead
	of simply printing it.
	Setning 2 - 5.
	*/
	return 0;
}

void getAndPrintInteger() {
	cout << "Skriv inn et tall: ";
	int i = promptInt();
	cout << "Du skrev: " << i << endl;
}

int getAndReturnInteger() {
	cout << "Skriv inn et tall: ";
	return promptInt();
}

void getAndPrintSum() {
	int sum = 0;
	
	for (int i = 0; i < 2; i++) {
		sum += getAndReturnInteger();
	}
	
	cout << "Sum: " << sum << endl;
}
