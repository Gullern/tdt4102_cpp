#include <string>
#include <iostream>
#include "main.h"
#include "template.h"
#include "simpleSet.h"

using namespace std;

int main() {
	oppg1();
	oppg2();

	/*
	int *data = new int[10];
	*data = 99;
	*(data + 1) = 123;
	cout << *data << endl;
	cout << *(data + 1) << endl;

	delete data;
	//delete[] data;
	//delete[] data;

	//delete[] (data + 1);
	cout << *data << endl;
	cout << *(data + 1) << endl;
	*/
}

void oppg1() {
	int a[] = {1, 2, 3, 4, 5, 6, 7};
	shuffle(a, 7);
	printArray(a, 7);

	double b[] = {1.2, 2.2, 3.2, 4.2};
	shuffle(b, 4);
	printArray(b, 4);

	string c[] = {"one", "two", "three", "four"};
	shuffle(c, 4);
	printArray(c, 4);

	int d = 1;
	int e = 2;
	int f = maximum(d, e);
	cout << f << endl;

	double g = 2.4;
	double h = 3.2;
	double i = maximum(g, h);
	cout << i << endl;

	/*
	 * Viktig at typen støtter operator>,
	 * altså større-enn-sammenligning.
	 */
}

void oppg2() {
	SimpleSet s;
	s.print();
	s.insert(1);
	s.insert(10);
	s.insert(5);
	s.print();
	s.insert(1);
	s.print();
	s.insert(11);
	s.insert(12);
	s.insert(13);
	s.insert(14);
	s.insert(15);
	s.insert(16);
	s.insert(17);
	s.print();
	s.insert(20);
	s.print();
	s.remove(5);
	s.remove(192);
	s.print();
	s.exists(20);
	s.exists(999);
}
