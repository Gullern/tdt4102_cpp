#include <iostream>
#include "main.h"
#include "matrix2x2.h"
#include "vector2.h"

using namespace std;

int main() {
	//test();

	linear_system_solver();
}

void linear_system_solver() {
	cout << "Equation of the form:\nI:  ax + by = p\nII: cx + dy = q\n";
	cout << "Input:\n";

	double a, b, c, d, p, q;


	cout << "a:";
	cin >> a;
	cout << "b:";
	cin >> b;
	cout << "c:";
	cin >> c;
	cout << "d:";
	cin >> d;
	cout << "p:";
	cin >> p;
	cout << "q:";
	cin >> q;

	Matrix2x2 coef = Matrix2x2(a, b, c, d);
	Vector2 rhs = Vector2(p, q);
	Vector2 sol;

	if (coef.det() == 0) {
		cout << "No solution!\n";
	} else {
		sol = coef.inverse() * rhs;
		cout << "Solution: \n";
		cout << "x = " << sol.getElement(0) << endl;
		cout << "y = " << sol.getElement(1) << endl;
	}
}

void test() {
	Matrix2x2 A(1, 2, 3, 4);
	Matrix2x2 B(4, 3, 2, 1);
	Matrix2x2 C(1.0, 3.0, 1.5, 2.0);

	cout << A;
	cout << B;
	cout << C;

	Matrix2x2 test = A;
	test.setElement(0, 0, 9);
	cout << A;

	Matrix2x2 E = refTilKopi;

	cout << (A + B);

	string s = (A + B).toString();
	cout << s;
	cout << (A += B);

	cout << (A + B);
	cout << A;
	cout << (A += B);
	cout << A;

	cout << endl << endl;

	Vector2 v1;
	Vector2 v2;

	v1.setElement(0, 3);
	v1.setElement(1, 4);
	v2.setElement(0, 3);
	v2.setElement(1, 4);

	cout << v1;
	cout << v1.dot(v2) << endl;
	cout << v1.length() << endl;

	cout << A.inverse();

	cout << A * v1;
}
