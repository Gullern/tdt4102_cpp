#include <iostream>
#include <cstdlib>

using namespace std;

void func(int i) {
	//char *a = new char[10];
	
	//char a[] = {'j', 'i', 'h', 'g', 'f', 'e', 'g', 'h', 'i', 'j'};
	//a[9] = i + '0';
	
	/*
	for (char *b = a; b < a + 100; b += 1) {
		cout << *b;
	}
	
	cout << endl << endl;
	if (i < 10) {
		func(i + 1);
	} */
	
	char x[] = {};
	char *a = x;
	for (;;a += 2) {
		cout << *a;
	}
}

/*
void test() {
	double **matrix = nullptr;
	int nRows = 2;
	int nColumns = 2;
	matrix = new double*[nRows];
	for (int i = 0; i < nRows; i++) {
		matrix[i] = new double[nColumns];
		for (int j = 0; j < nColumns; j++) {
			//matrix[i][j] = (i == j ? 1 : 0);
			matrix[i][j] = 0;
			cout << matrix[i][j];
		}
	}
} */


int main() {
	func(0);
	
	//int *a = nullptr;
	//test();
	return 0;
}
