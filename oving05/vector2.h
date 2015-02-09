#ifndef VECTOR2_H
#define VECTOR2_H

#include <string>

class Vector2 {
public:
	static const int SIZE = 2;
private:
	double vector[SIZE];
	void initiateEmpty();
public:
	Vector2();
	Vector2(double a1, double a2);
	double getElement(int position);
	void setElement(int position, double value);
	double dot(const Vector2 &rhs) const;
	double lengthSquared() const;
	double length() const;
	std::string toString();
};

std::ostream& operator<<(std::ostream &out, const Vector2 &vector);

#endif
