#include <iostream>
#include "oppg6.h"
#include "ui.h"

using namespace std;

#ifndef MENU
int main() {
	// a) og b)
	calculateLoanPayments();
	
	return 0;
}
#endif

void calculateLoanPayments() {
	const int NR_OF_DEPOSITS = 10;
	
	cout << "Lanekalkulator..." << endl;
	
	cout << "Skriv inn lan: ";
	double loan = promptDouble();
	
	cout << "Skriv inn rente: ";
	double interest = promptDouble();
	
	int deposit = 0;
	int remaining = loan;
	
	cout << "Ar\tInnbetaling\tGjenstaende Lan" << endl;
	
	for (int year = 1; year <= NR_OF_DEPOSITS; year++) {
		deposit = loan / NR_OF_DEPOSITS + interest / 100 * remaining;
		cout << year << "\t" << deposit << "\t\t" << remaining << endl;
		remaining -= loan / NR_OF_DEPOSITS;
	}
}
