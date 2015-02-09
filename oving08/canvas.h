#ifndef CANVAS_H
#define CANVAS_H

#include <vector>
#include "shapes.h"

class Canvas {
private:
	std::vector<Shape*> objects;
public:
	void addShape(Shape *shape) { objects.push_back(shape); };
	void rasterizeTo(Image &image) const;
};

#endif
