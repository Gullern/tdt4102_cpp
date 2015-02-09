#include <sstream>
#include <cmath>
#include "vector2.h"

using namespace std;

Vector2::Vector2() {
	this->initiateEmpty();
}

Vector2::Vector2(double a1, double a2) {
	this->vector[0] = a1;
	this->vector[1] = a2;
}

void Vector2::initiateEmpty() {
	for (int i = 0; i < this->SIZE; i++) {
		this->vector[i] = 0;
	}
}

double Vector2::getElement(int position) {
	if (position < 0 || position >= SIZE) {
		return 0;
	}

	return vector[position];
}

void Vector2::setElement(int position, double value) {
	if (position < 0 || position >= SIZE) {
		return;
	}

	vector[position] = value;
}

double Vector2::dot(const Vector2 &rhs) const {
	double result = 0;
	for (int i = 0; i < SIZE; i++) {
		result += this->vector[i] * rhs.vector[i];
	}
	return result;
}

double Vector2::lengthSquared() const {
	return this->dot(*this);
}

double Vector2::length() const {
	return sqrt(this->lengthSquared());
}

std::string Vector2::toString() {
	string output = "";
	stringstream ss;
	for (int i = 0; i < SIZE; i++) {
		ss << vector[i];
		output += ss.str();
		ss.str("");
		if (i < SIZE - 1) {
			output += ", ";
		}
	}
	output += "\n";
	return output;
}

std::ostream& operator<<(std::ostream &out, const Vector2 &vector) {
	Vector2 temp = vector;
	out << temp.toString();
	return out;
}
