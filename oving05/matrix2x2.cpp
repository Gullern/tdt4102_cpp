#include <sstream>
#include "matrix2x2.h"
#include "vector2.h"

using namespace std;

Matrix2x2::Matrix2x2() {
	initiateIdentity();
}

Matrix2x2::Matrix2x2(double a1, double a2, double a3, double a4) {
	matrix[0][0] = a1;
	matrix[0][1] = a2;
	matrix[1][0] = a3;
	matrix[1][1] = a4;
}

void Matrix2x2::initiateIdentity() {
	for (int row = 0; row < NUM_ROWS; row++) {
		for (int col = 0; col < NUM_COLS; col++) {
			if (row == col) {
				matrix[row][col] = 1;
			} else {
				matrix[row][col] = 0;
			}
		}
	}
}

double Matrix2x2::getElement(int row, int column) {
	if (row < 0 || row >= NUM_ROWS || column < 0 || column >= NUM_COLS) {
		return 0;
	}
	return matrix[row][column];
}

void Matrix2x2::setElement(int row, int column, double value) {
	if (row < 0 || row >= NUM_ROWS || column < 0 || column >= NUM_COLS) {
		return;
	}
	matrix[row][column] = value;
}

string Matrix2x2::toString() {
	string output = "";
	stringstream ss;
	for (int row = 0; row < NUM_ROWS; row++) {
		for (int col = 0; col < NUM_COLS; col++) {
			ss << matrix[row][col];
			output += ss.str();
			ss.str("");
			if (col < NUM_COLS - 1) {
				output += ", ";
			}
		}
		output += "\n";
	}
	return output;
}

ostream& operator<< (ostream &out, const Matrix2x2 &matrix) {
	Matrix2x2 temp = matrix;
	out << temp.toString();
	return out;
}

Matrix2x2& Matrix2x2::operator+=(const Matrix2x2 &matrix) {
	this->matrix[0][0] += matrix.matrix[0][0];
	this->matrix[0][1] += matrix.matrix[0][1];
	this->matrix[1][0] += matrix.matrix[1][0];
	this->matrix[1][1] += matrix.matrix[1][1];
	return *this;
}

Matrix2x2& Matrix2x2::operator-=(const Matrix2x2 &matrix) {
	this->matrix[0][0] -= matrix.matrix[0][0];
	this->matrix[0][1] -= matrix.matrix[0][1];
	this->matrix[1][0] -= matrix.matrix[1][0];
	this->matrix[1][1] -= matrix.matrix[1][1];
	return *this;
}

Matrix2x2& Matrix2x2::operator*=(const Matrix2x2 &matrix) {
	if (this->NUM_COLS != matrix.NUM_ROWS) {
		return *this;
	}

	for (int row = 0; row < this->NUM_ROWS; row++) {
		for (int col = 0; col < matrix.NUM_COLS; col++) {
			double element = 0;
			for (int i = 0; i < this->NUM_COLS; i++) {
				element += this->matrix[row][i] * matrix.matrix[i][col];
			}
			this->matrix[row][col] = element;
		}
	}
	return *this;
}

Matrix2x2& operator+(const Matrix2x2 &m1, const Matrix2x2 &m2) {
	return Matrix2x2(m1) += m2;
}

Matrix2x2 operator-(const Matrix2x2 &m1, const Matrix2x2 &m2) {
	return Matrix2x2(m1) -= m2;
}

Matrix2x2 operator*(const Matrix2x2 &m1, const Matrix2x2 &m2) {
	return Matrix2x2(m1) *= m2;
}

double Matrix2x2::det() const {
	return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
}

Matrix2x2 Matrix2x2::inverse() const {
	double det = this->det();
	if (det == 0) {
		return Matrix2x2();
	}

	Matrix2x2 output;
	output.matrix[0][0] = this->matrix[1][1] / det;
	output.matrix[0][1] = - this->matrix[0][1] / det;
	output.matrix[1][0] = - this->matrix[1][0] / det;
	output.matrix[1][1] = this->matrix[0][0] / det;
	return output;
}

Vector2 operator*(const Matrix2x2 &m, const Vector2 &v) {
	if (m.NUM_COLS != v.SIZE) {
		return Vector2();
	}

	Vector2 result;
	Matrix2x2 temp_matrix = m;
	Vector2 temp_vector = v;

	for (int row = 0; row < m.NUM_ROWS; row++) {
		double element = 0;
		for (int i = 0; i < v.SIZE; i++) {
			element += temp_matrix.getElement(row, i) * temp_vector.getElement(i);
		}
		result.setElement(row, element);
	}
	return result;
}

