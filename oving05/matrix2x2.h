#ifndef MATRIX2X2_H
#define MATRIX2X2_H

#include <string>
#include "vector2.h"

class Matrix2x2 {
public:
	static const int NUM_ROWS = 2;
	static const int NUM_COLS = 2;
private:
	double matrix[NUM_ROWS][NUM_COLS];
	void initiateIdentity();
public:
	Matrix2x2();
	Matrix2x2(double a1, double a2, double a3, double a4);
	double getElement(int row, int column);
	void setElement(int row, int column, double value);
	std::string toString();
	double det() const;
	Matrix2x2 inverse() const;
	Matrix2x2& operator+=(const Matrix2x2 &matrix);
	Matrix2x2& operator-=(const Matrix2x2 &matrix);
	Matrix2x2& operator*=(const Matrix2x2 &matrix);
};
class Objekt {
	int x;
	Objekt&  operator +=(int value);
};
Objekt& Objekt::operator +=(int value){
	x += value;
	return *this;
}
Objekt obj;
obj += 2;

mat1 +=refTIlMat2;


}


std::ostream& operator<< (std::ostream &out, const Matrix2x2 &matrix);
Matrix2x2 operator+(const Matrix2x2 &m1, const Matrix2x2 &m2);
Matrix2x2 operator-(const Matrix2x2 &m1, const Matrix2x2 &m2);
Matrix2x2 operator*(const Matrix2x2 &m1, const Matrix2x2 &m2);
Vector2 operator*(const Matrix2x2 &m, const Vector2 &v);

#endif
