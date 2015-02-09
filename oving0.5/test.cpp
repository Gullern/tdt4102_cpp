#include <iostream>

using namespace std;

int a = 0;

int count();

int main() {
	/*
	int a = 0;
	bool valid = false;
	
	do {
		cout << "Write 5: ";
		cin >> a;
		valid = !cin.fail();
		cin.clear();
		cin.ignore();
		
		if (!valid)
			cout << "Not a number!" << endl;
		
		if (a != 5)
			valid = false;
	} while (!valid);
	
	cout << a << endl;
	
	for (int i = 1; i <= 3; i++) {
		cout << "w";
	}
	
	int b = 0;
	b += 1;
	cout << endl << b << endl;
	
	int ar[2] = {0, 0};
	
	for (int i = 0; i < a; i++) {
		cout << ar[i] << endl;
	}
	
	*/
	
	int a;
	cin >> a;
	
	int ar[a];
	int b = 0;
	
	
	for (int i = 0; i < a; i++) {
		cin >> ar[i];
	}
	
	for (int i = 0; i < a; i++) {
		cout << ar[i] << endl;
	}
	
	ar[a] = 1;
	
	cout << b;
	
	return 0;
}

int count() {
	return ++a;
}
