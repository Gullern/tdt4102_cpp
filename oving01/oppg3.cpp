#include <iostream>
#include <cstdio>
#include "oppg3.h"
#include "ui.h"

using namespace std;

#ifndef MENU
int main() {
	// a)
	getAndPrintTime();
	
	// b)
	getAndPrintPrices();
	
	return 0;
}
#endif

void getAndPrintTime() {
	int time = 0;
	
	cout << "Skriv antall sekunder: ";
	time = promptInt();
	
	int hours = 0;
	int minutes = 0;
	
	hours = time / 3600;
	time -= hours * 3600;
	minutes = time / 60;
	time -= minutes * 60;
	
	cout << hours << " time";
	if (hours != 1)
		cout << "r";
	cout << ", " << minutes << " minutt";
	if (minutes != 1)
		cout << "er";
	cout << ", " << time << " sekund";
	if (time != 1)
		cout << "er";
	cout << endl;
}

void getAndPrintPrices() {
	const double MVA = 0.875;
	const double TIPS = 0.18;
	
	double price = 0;
	double mva = 0;
	double tips = 0;
	double sum = 0;
	
	cout << "Skriv inn pris: ";
	price = promptDouble();
	
	mva = price * MVA;
	tips = (price + mva) * TIPS;
	sum = price + tips;
	
	printf("Pris: %.2f\nMVA: %.2f\nTips: %.2f\nSum: %.2f\n", price, mva, tips, sum);
}
