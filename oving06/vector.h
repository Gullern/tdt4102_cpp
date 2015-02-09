#ifndef VECTOR_H
#define VECTOR_H

#include "matrix.h"

class Vector : public Matrix {
public:
	Vector();
	explicit Vector(unsigned int nRows);
	Vector(const Matrix &other);
	double getElement(unsigned int row) const;
	void setElement(unsigned int row, double value);
	double dot(const Vector &rhs) const;
	double lengthSquared() const;
	double length() const;
};

#endif
