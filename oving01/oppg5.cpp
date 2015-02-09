#include <iostream>
#include <cmath>
#include "oppg5.h"
#include "ui.h"

using namespace std;

#ifndef MENU
int main() {
	// a)
	cout << internalSum(1, 2, 3) << endl;
	
	// b)
	cout << positiveSqrt(25) << endl;
	cout << positiveSqrt(-25) << endl;
	
	// c)
	cout << polyRoot(3, 2, 1) << endl;
	
	// d)
	abcFormula(4, 2, -1);
	
	// e)
	solveAndPrintRoots();
	
	// f)
	//Done
	
	// g)
	abcFormula(1, 2, 4);
	abcFormula(4, 4, 1);
	abcFormula(8, 4, -1);
	
	return 0;
}
#endif

double internalSum(double a, double b, double c) {
	return b * b - 4 * a * c;
}

double positiveSqrt(double x) {
	if (x < 0)
		return -1;
	else
		return sqrt(x);
}

double polyRoot(double a, double b, double c) {
	return positiveSqrt(internalSum(a, b, c));
}

void abcFormula(double a, double b, double c) {
	double poly = polyRoot(a, b, c);
	
	if (poly > 0) {
		double x1 = (- b + poly) / (2 * a);
		double x2 = (- b - poly) / (2 * a);
		
		cout << "To losninger:\n" << x1 << endl << x2 << endl;
	} else if (poly == 0) {
		double x1 = (- b + poly) / (2 * a);
		
		cout << "En losning: " << x1 << endl;
	} else {
		cout << "Ingen losning!" << endl;
	}
}

void solveAndPrintRoots() {
	cout << "Andregradsloser..." << endl;
	
	double var[3] = {0, 0, 0};
	
	for (int i = 0; i < 3; i++) {
		cout << "Skriv inn et tall: ";
		var[i] = promptDouble();
	}
	
	abcFormula(var[0], var[1], var[2]);
}
