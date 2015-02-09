/*
#include <iostream>

using namespace std;

class SubOst {
public:
	int b;
};

class Ost {
public:
	int a;
	SubOst subOst;
	SubOst *ostPeker;
};

void tost(Ost ost) {
	ost.a = -1;
	ost.subOst.b = 5;
	ost.ostPeker->b = 1;
}

void tost2(const Ost ost) {
	ost.ostPeker->b = 100;
}

void tost3(Ost &ost) {

}

void tost4(const Ost &ost) {

}

void tost5(Ost *ost) {
	ost->a = 50;
	ost->subOst.b = 20;
	ost->ostPeker->b = 88;
}

void tost6(const Ost *ost) {

}

int main3()  {
	Ost ost;
	SubOst subOst;
	SubOst pointerOst;
	ost.a = 7;
	subOst.b = 9;
	pointerOst.b = 99;
	ost.subOst = subOst;
	ost.ostPeker = &pointerOst;
	Ost *ost2 = &ost;

	cout << ost.a << endl;
	cout << ost.subOst.b << endl;
	cout << ost.ostPeker->b << endl;
	tost(ost);
	cout << ost.a << endl;
	cout << ost.subOst.b << endl;
	cout << ost.ostPeker->b << endl;
	tost2(ost);
	cout << ost.a << endl;
	cout << ost.subOst.b << endl;
	cout << ost.ostPeker->b << endl;
	tost3(ost);
	cout << ost.a << endl;
	cout << ost.subOst.b << endl;
	cout << ost.ostPeker->b << endl;
}


void test(int a) {
	a = 2;
}

void test2(const int a) {
	//a = 2;
}

void test3(int *a) {
	*a = 2;
}

void test4(int *a) {
	int b = 99;
	a = &b;
}

void test5(const int *a) {
	//*a = 2;
}

void test6(const int *a) {
	int b = 999;
	a = &b;
}

void test7(int &a) {
	a = 12;
}

void test8(int &a) {
	int b = 34;
	//&a = &b;
}

void test9(const int &a) {
	//a = 345;
}

void test10(const int &a) {
	int b = 4262;
	//&a = &b;
}

int main2() {

	int a = 8;
	int *b = &a;

	cout << a << endl;
	test(a);
	cout << a << endl;
	test2(a);
	cout << a << endl;
	test7(a);
	cout << a << endl;
	test8(a);
	cout << a << endl;
	test9(a);
	cout << a << endl;
	test10(a);
	cout << a << endl;

	cout << b << endl;
	cout << *b << endl;
	test3(b);
	cout << b << endl;
	cout << *b << endl;
	test4(b);
	cout << b << endl;
	cout << *b << endl;
	test5(b);
	cout << b << endl;
	cout << *b << endl;
	test6(b);
	cout << b << endl;
	cout << *b << endl;


}

*/
