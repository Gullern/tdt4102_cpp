#include "shapes.h"
#include <iostream>

/* Shape */

Shape::Shape(const Color &color) : color(color) {

}


/* Line */

Line::Line(unsigned int startX, unsigned int startY, unsigned int endX, unsigned int endY, const Color &color) :
		Shape(color), startX(startX), startY(startY), endX(endX), endY(endY) {

}

void Line::doDraw(Image &image) const {
	if (startX >= image.getWidth() || startY >= image.getHeight()) {
		return;
	}

	unsigned int ex = endX < image.getWidth() ? endX : image.getWidth();
	unsigned int ey = endY < image.getHeight() ? endY : image.getHeight();

	if (1.0 * (endY - startY) / (endX - startX) > 1) {
		for (unsigned int y = startY; y < ey; y++) {
			image.setColor(xValue(y), y, getColor());
		}
	} else {
		for (unsigned int x = startX; x < ex; x++) {
			image.setColor(x, yValue(x), getColor());
		}
	}
}


/* Rectangle */

Rectangle::Rectangle(const Line &diagonal) : Shape(diagonal.getColor()), diagonal(diagonal) {
	//Uses color from line
}

Rectangle::Rectangle(const Line &diagonal, const Color &color) : Shape(color), diagonal(diagonal) {
	//Custom color, leaves line color untouched
}

void Rectangle::doDraw(Image &image) const {
	Line left(diagonal.getStartX(), diagonal.getStartY(), diagonal.getStartX(), diagonal.getEndY(), getColor());
	Line right(diagonal.getEndX(), diagonal.getStartY(), diagonal.getEndX(), diagonal.getEndY(), getColor());
	Line top(diagonal.getStartX(), diagonal.getEndY(), diagonal.getEndX(), diagonal.getEndY(), getColor());
	Line bottom(diagonal.getStartX(), diagonal.getStartY(), diagonal.getEndX(), diagonal.getStartY(), getColor());

	left.draw(image);
	right.draw(image);
	top.draw(image);
	bottom.draw(image);
}


/* Circle */

Circle::Circle(unsigned int centerX, unsigned int centerY, unsigned int radius, const Color &color)
		: Shape(color), centerX(centerX), centerY(centerY), radius(radius) {

}

void Circle::doDraw(Image &image) const {
	double margin = 0.1;

	double diff = 0;
	for (unsigned int y = 0; y < image.getHeight(); y++) {
		for (unsigned int x = 0; x < image.getWidth(); x++) {
			diff = radiusValue(x, y) - radius;
			if (diff * diff < margin) {
				image.setColor(x, y, getColor());
			}
		}
	}
};
