#include <cmath>
#include <iostream>
#include "vector.h"

using namespace std;

Vector::Vector() : Matrix() {

}

Vector::Vector(unsigned int nRowsValue) : Matrix(nRowsValue, 1) {

}

Vector::Vector(const Matrix &other) : Matrix() {
	if (other.getNColumns() > 1) {
		return;
	}
	Matrix &m = *this;
	m = Matrix(other);
}

double Vector::getElement(unsigned int row) const {
	return Matrix::getElement(row, 0);
}

void Vector::setElement(unsigned int row, double value) {
	Matrix::setElement(row, 0, value);
}

double Vector::dot(const Vector &rhs) const {
	if (this->getNRows() != rhs.getNRows()) {
		cout << "Unequal dimensions: "
				<< this->getNRows() << "x" << this->getNColumns() << " vs. "
				<< rhs.getNRows() << "x" << rhs.getNColumns() << "!\n";
		throw 1;
	}

	double result = 0;
	for (unsigned int i = 0; i < getNRows(); i++) {
		result += this->getElement(i) * rhs.getElement(i);
	}
	return result;
}

double Vector::lengthSquared() const {
	return dot(*this);
}

double Vector::length() const {
	return sqrt(lengthSquared());
}
