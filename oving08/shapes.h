#ifndef SHAPES_H
#define SHAPES_H

#include <functional>
#include <cmath>
#include "image.h"

/* Shape */
class Shape {
private:
	Color color;

	virtual void doDraw(Image &image) const = 0;
public:
	Shape(const Color &color);
	virtual ~Shape() {};

	Color getColor() const { return color; }
	void setColor(const Color &color) { this->color = color; }
	void draw(Image &image) const { doDraw(image); }
};

/* Line */
class Line : public Shape {
private:
	unsigned int startX, startY, endX, endY;
	std::function<unsigned int(unsigned int)> yValue = [this](unsigned int x) {
		return (endY - startY) * 1.0 / (endX - startX) * (x - startX) + startY;
	};

	std::function<unsigned int(unsigned int)> xValue = [this](unsigned int y) {
		return (endX - startX) * 1.0 / (endY - startY) * (y - startY) + startX;
	};

	void doDraw(Image &image) const;
public:
	Line(unsigned int startX, unsigned int startY, unsigned int endX,
			unsigned int endY, const Color &color);
	unsigned int getStartX() const { return startX; }
	unsigned int getEndX() const { return endX; }
	unsigned int getStartY() const { return startY; }
	unsigned int getEndY() const { return endY; }
};

/*Rectangle */
class Rectangle : public Shape {
private:
	Line diagonal;

	void doDraw(Image &image) const;
public:
	Rectangle(const Line &diagonal); //Uses color from line
	Rectangle(const Line &diagonal, const Color &color); //Custom color
};

/* Circle */
class Circle : public Shape {
private:
	unsigned int centerX, centerY, radius;
	std::function<unsigned int(unsigned int, unsigned int)> radiusValue = [this](unsigned int x, unsigned int y) {
		return sqrt((x - centerX) * (x - centerX) + (y - centerY) * (y - centerY));
	};

	void doDraw(Image &image) const;
public:
	Circle(unsigned int centerX, unsigned int centerY, unsigned int radius, const Color &color);
};

#endif
