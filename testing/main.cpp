#include <iostream>
#include <cstdlib>
#include "main.h"

using namespace std;

int main() {
	
	test1(0);
	
	return 0;
}

void sort(int min, int max, int* array) {
	if (min >= max - 1) { return; }
	
	int pivotIndex = min + rand() % (max - min);
	int pivot = array[pivotIndex];
	
	int* left = array + min;
	int* right = array + max;
	
	swap (*right, *array);
	
	while (right != left) {
		
		
	}
}

void test1(int z) {
	if (z > 1) { return; }
	int a = 55;
	int *p = &a;
	int b = 77;
	int **q = &p;
	unsigned char *x = (unsigned char*) &a - 50;
	*(&a + 4) = 0x0;
	
	cout << &a << " " << a << endl;
	cout << &p << " " << p << endl;
	cout << &b << " " << b << endl;
	cout << &q << " " << q << endl;
	cout << &x << " " << (void*) x << endl;
	
	cout << endl;
	/*
	for (int i = 0; i < 120; i++) {
		cout << dec << (void *) x << " " << (int) *x << " ";
		cout << hex << (int) *x << endl;
		x++;
	}*/
	
	cout << endl << endl;
	
	test1(z + 1);
}
