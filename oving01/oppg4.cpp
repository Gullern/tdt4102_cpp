#include <iostream>
#include "oppg4.h"
#include "ui.h"

using namespace std;

#ifndef MENU
int main() {
	// a)
	printOddOrEven();
	
	// b)
	printMax();
	
	// c)
	/*
	A function which takes two numbers as input parameters must be 
	called with explicitly with numbers provided as input.
	A function which prompts the user for two numbers uses std::cin to
	prompt the user for input and then proceeds. 
	Setning 3 - 5. 
	*/
	
	return 0;
}
#endif

void printOddOrEven() {
	int number = 0;
	
	cout << "Skriv inn et tall: ";
	number = promptInt();
	
	cout << "Tallet er et ";
	if (number % 2)
		cout << "odde";
	else
		cout << "par";
	
	cout << "tall." << endl;
}

void printMax() {
	double a = 0;
	double b = 0;
	
	cout << "Skriv inn et tall: ";
	a = promptDouble();
	cout << "Skriv inn et tall: ";
	b = promptDouble();
	
	if (a > b)
		cout << a;
	else
		cout << b;
	
	cout << " er storst" << endl;
}
