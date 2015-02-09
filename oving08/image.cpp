#include <cstdlib>
#include <iostream>
#include "image.h"

Image::Image(unsigned int width, unsigned int height) : width(width), height(height) {
	data = new unsigned char[width * height * 3];
	fill(Color(0, 0, 0));
}

Image::~Image() {
	delete []data;
	width = 0;
	height = 0;
	data = 0;
}

const unsigned char* Image::getScanLine(unsigned int line) const {
	if (line >= height) {
		std::cerr << "Line out of range!\n";
		return NULL;
	}
	const unsigned char *scan = &data[width * line * 3];
	return scan;
}

unsigned char* Image::getScanLine(unsigned int line) {
	if (line >= height) {
		std::cerr << "Line out of range!\n";
		return NULL;
	}
	return &data[width * line * 3];
}

Color Image::getColor(unsigned int x, unsigned int y) const {
	if (y >= height || x >= width) {
		std::cerr << "Line out of range!\n";
		return Color();
	}
	/*
	return Color(	data[(width * (height - y - 1) + x) * 3 + 0],
					data[(width * (height - y - 1) + x) * 3 + 1],
					data[(width * (height - y - 1) + x) * 3 + 2]);
	*/
	return Color(	data[(width * y + x) * 3 + 0],
					data[(width * y + x) * 3 + 1],
					data[(width * y + x) * 3 + 2]);
}

void Image::setColor(unsigned int x, unsigned int y, const Color &color) {
	if (y >= height || x >= width) {
		std::cerr << "Line out of range!\n";
		return;
	}
	/*
	data[(width * (height - y - 1) + x) * 3 + 0] = color.red;
	data[(width * (height - y - 1) + x) * 3 + 1] = color.green;
	data[(width * (height - y - 1) + x) * 3 + 2] = color.blue;
	*/
	data[(width * y + x) * 3 + 0] = color.red;
	data[(width * y + x) * 3 + 1] = color.green;
	data[(width * y + x) * 3 + 2] = color.blue;
}

void Image::fill(const Color &color) {
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			setColor(x, y, color);
		}
	}
}
