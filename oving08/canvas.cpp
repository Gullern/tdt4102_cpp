#include "canvas.h"

void Canvas::rasterizeTo(Image &image) const {
	for (std::vector<Shape*>::const_iterator it = objects.begin(); it != objects.end(); it++) {
		(*it)->draw(image);
	}
}
