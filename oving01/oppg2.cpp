#include <iostream>
#include <iomanip>
#include "oppg2.h"
#include "ui.h"

#ifdef MENU
#include "oppg3.h"
#include "oppg4.h"
#include "oppg5.h"
#include "oppg6.h"
#endif

using namespace std;

int main() {
#ifndef MENU
	// a)
	getAndPrintMoreSumsPre();
	getAndPrintMoreSums();
	
	// b)
	/*
	A for-loop iterates a specified number of times (usually), while a while-loop
	iterates until a given conditions is met (usually). When the number of
	iterations is known before hand a for-loop is best, when not, a while-loop 
	is better. 
	Setning 3 - 5. 
	*/
	
	// c)
	cout << getAndReturnDouble() << endl;
	
	// d)
	convertAndPrintNokToEuro();
	
	// e)
	/*
	getAndReturnDouble returns a floating point number from the console. 
	This tasks specified that the number to be converted is of type float, 
	hence getAndReturnDouble must be used instead of getAndReturnInteger, 
	which only returns an integer. 
	Setning 3 - 5. 
	*/
	
	// f)
	menu();
	
	// g)
	//Bygd inn i menyen fra oppgave (f).
#else
	menu();
#endif
	return 0;
}

void getAndPrintMoreSumsPre() {
	int num = 0;
	
	cout << "Hvor mange tall skal summeres?: ";
	num = promptInt();
	getAndPrintMoreSums(num);
}

void getAndPrintMoreSums(int num) {
	int sum = 0;
	
	for (int i = 0; i < num; i++) {
		cout << "Skriv inn et tall: ";
		sum += promptInt();
	}
	
	cout << "Sum: " << sum << endl;
}

void getAndPrintMoreSums() {
	int sum = 0;
	
	int i = 0;
	do {
		cout << "Skriv inn et tall: ";
		i = promptInt();
		sum += i;
	} while(i != 0);
	
	cout << "Sum: " << sum << endl;
}

double getAndReturnDouble() {
	cout << "Skriv inn et tall: ";
	return promptDouble();
}

void convertAndPrintNokToEuro() {
	const double CONVERSIONFACTOR = 7.84;
	
	double value = 0;
	do {
		value = getAndReturnDouble();
		
		if (value < 0)
			cout << "Kun ikke-negative tall aksepteres!" << endl;
	} while(value < 0);
	
	cout << value / CONVERSIONFACTOR << endl;
}

void menu() {
#ifdef MENU
	int ITEMS = 10;
#else
	int ITEMS = 4;
#endif
	
	int choice = 0;
	do {
		do {
			cout << "Velg funksjon: \n"
			"0) Avslutt\n"
			"1) Summer to tall\n"
			"2) Summer flere tall\n"
			"3) Konverter NOK til EURO.\n"
			"4) Print gangetabell\n"
			
#ifdef MENU
			"5) Print tid\n"
			"6) Print priser\n"
			"7) Sjekk om partall eller oddetall\n"
			"8) Print max\n"
			"9) Los andregradsligning\n"
			"10) Beregn laneinnbetalinger\n"
#endif
			"Angi valg (0-" << ITEMS << "): ";
			
			choice = promptInt();
			
			if (choice < 0 || choice > ITEMS)
				cout << "Ikke et gyldig valg!" << endl;
		} while (choice < 0 || choice > ITEMS);
		
		if (choice == 1) { //ITEMS!
			getAndPrintMoreSums(2);
		} else if (choice == 2) {
			getAndPrintMoreSums();
		} else if (choice == 3) {
			convertAndPrintNokToEuro();
		} else if (choice == 4) {
			printMultiplicationTable();
		}
#ifdef MENU
		else if (choice == 5) {
			getAndPrintTime();
		} else if (choice == 6) {
			getAndPrintPrices();
		} else if (choice == 7) {
			printOddOrEven();
		} else if (choice == 8) {
			printMax();
		} else if (choice == 9) {
			solveAndPrintRoots();
		} else if (choice == 10) {
			calculateLoanPayments();
		}
#endif
	} while (choice != 0);
}

void printMultiplicationTable() {
	int dimensions[] = {0, 0}; //{height, width}
	
	for (int i = 0; i < 2; i++) {
		if (i == 0) {
			cout << "Velg hoyde: ";
		} else {
			cout << "Velg bredde: ";
		}
		
		dimensions[i] = promptInt();
	}
	
	for (int i = 1; i <= dimensions[0]; i++) {
		for (int j = 1; j <= dimensions[1]; j++) {
			cout << setw(4) << i * j;
		}
		cout << endl;
	}
}
