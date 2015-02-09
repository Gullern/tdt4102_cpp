#include <iostream>
#include "oppg2.h"
#define nel(x) (sizeof(x) / sizeof(x[0]))
using namespace std;

int main() {
	cout << fibonacci(10) << endl;
	triangleNumbersBelow(10);
	cout << isTriangleNumber(6) << "," << isTriangleNumber(7) << endl;
	cout << squareNumberSum(10) << endl;
	cout << max(5, -2) << endl;
	cout << isPrime(7) << "," << isPrime(9) << endl;
	naivePrimeNumberSearch(53);
	cout << findGreatestDivisor(2831) << endl;
	double test[] = {3, -5, 1, 0, -2, 3, -3, 5, 0, 6};
	compareListOfNumbers(test, nel(test));
	cout << &test << endl;
	return 0;
}

int fibonacci(int n) {
	int a = 0;
	int b = 1;
	cout << "Fibonacci numbers:" << endl;
	
	int temp;
	for (int i = 1; i < n; i++) {
		temp = b;
		b = a + b;
		a = temp;
		cout << i << ',' << b << endl;
	}
	
	cout << endl;
	return b;
}

void triangleNumbersBelow(int n) {
	int acc = 1;
	int num = 2;
	cout << "Triangle numbers below " << n << ":" << endl;
	
	while (acc + num < n) {
		acc += num;
		num++;
		cout << acc << endl;
	}
	cout << endl;
}

bool isTriangleNumber(int number) {
	int acc = 1;
	while (number > 0) {
		number -= acc;
		acc++;
	}
	
	if (number == 0)
		return true;
	else
		return false;
}

int squareNumberSum(int n) {
	int totalSum = 0;
	for (int i = 0; i < n; i++) {
		totalSum += i * i;
		cout << (i + 1) * (i + 1) << endl;
	}
	cout << totalSum << endl;
	return totalSum;
}

int max(int a, int b) {
	if (a > b) {
		cout << "A is greater than B" << endl;
		return a;
	} else {
		cout << "B is greater than or equal A" << endl;
		return b;
	}
}

bool isPrime(int n) {
	bool primeness = true;
	for (int j = 2; j < n; j++) {
		if (n % j == 0) {
			primeness = false;
			break;
		}
	}
	return primeness;
}

void naivePrimeNumberSearch(int n) {
	for (int number = 2; number < n; number++) {
		if (isPrime(number)) {
			cout << number << " is a prime" << endl;
		}
	}
}

int findGreatestDivisor(int n) {
	for (int divisor = n - 1; divisor > 0; divisor--) {
		if (n % divisor == 0)
			return divisor;
	}
	return 1;
}

void compareListOfNumbers(double l[], int len) {
	int r[3] = {0, 0, 0};
	for (int i = 0; i < len; i++) {
		if (l[i] < 0)
			r[0]++;
		else if (l[i] == 0)
			r[1]++;
		else
			r[2]++;
	}
	
	cout << r[0] << " numbers were below zero" << endl;
	cout << r[1] << " numbers were zero" << endl;
	cout << r[2] << " numbers were greater than zero" << endl;
}
