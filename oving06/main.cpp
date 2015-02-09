#include <iostream>
#include <cstdlib>
#include "main.h"
#include "matrix.h"
#include "vector.h"
#include "minesweeper.h"

using namespace std;

int main() {
	//Oppgave 1 - 5
	tests();

	int number = 0;
	while(true) {
		cin >> number;
		if (number == 1) {
			break;
		}
		cout << "test";
		cin.clear();
		cin.ignore();
	}

	//Oppgave 6: Minesveiper
	minesweeper();
}

void minesweeper() {
	Minesweeper game;
	game.play();
}

void tests() {
	//Oppgave 1
	test1();

	//Oppgave 2
	test2();

	//Oppgave 3
	test3();

	//Oppgave 4
	test4();

	//Oppgave 5
	test5();
}

void test1() {
	Matrix m1;
	Matrix m2 = Matrix(2);
	Matrix m3 = Matrix(2, 3);

	m2.setElement(0, 0, 5);
	m2.setElement(1, 0, 3);
	m3.setElement(0, 0, 1);

	cout << m1;
	cout << m2;
	cout << m3;
}

void test2() {
	Matrix m1 = Matrix(2);
	Matrix m2 = Matrix(m1);
	Matrix m3;

	m2.setElement(0, 0, 5);
	m2.setElement(1, 0, 3);
	m3 = m2;

	cout << m1;
	cout << m2;
	cout << m3;
}

void test3() {
	Matrix A(2);
	A.setElement(0, 0, 1);
	A.setElement(0, 1, 2);
	A.setElement(1, 0, 3);
	A.setElement(1, 1, 4);

	Matrix B(2);
	B.setElement(0, 0, 4);
	B.setElement(0, 1, 3);
	B.setElement(1, 0, 2);
	B.setElement(1, 1, 1);

	Matrix C(2);
	C.setElement(0, 0, 1.0);
	C.setElement(0, 1, 3.0);
	C.setElement(1, 0, 1.5);
	C.setElement(1, 1, 2.0);

	Matrix D;
	D = (A + B);
	cout << D;
	D = (D * B - A + C);
	cout << D;
}

void test4() {
	Matrix m1(2);
	Matrix m2(2, 1);
	Vector v1(m1);
	Vector v2(m2);
	cout << v1 << v2;

	v2.setElement(0, 3);
	v2.setElement(1, 4);
	cout << v2.dot(v2) << endl;
	cout << v2.length() << endl;
}

void test5() {
	Matrix m(4);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			m.setElement(i, j, (int)(rand() % 10));
		}
	}

	Vector v(4);
	for (int i = 0; i < 4; i++) {
		v.setElement(i, (int)(rand() % 10));
	}

	cout << m;
	cout << v;
	cout << m * v;
}
