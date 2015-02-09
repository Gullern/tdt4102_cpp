#include <iostream>
#include "main.h"
#include "image.h"
#include "shapes.h"
#include "canvas.h"

using namespace std;

int main() {
	oppg1();
	oppg2();
	oppg3();
	oppg4();
	oppg5();
	oppg6();
	oppg7();
}

void oppg1() {
	/*
	 * Teorispørsmål, oppg. 1:
	 * a)	512x512
	 * b)	sort
	 * c)	0xFF0000
	 * d)	En uchar passer datastørrelsen til RGB.
	 * 		Kan umulig bli feil med negative verdier, trenger ikke sjekk.
	 */
}

void oppg2() {
	Image img(50, 50);
	img.setColor(0, 0, Color(255, 255, 255));
	img.fill(Color(193, 84, 193));
	saveImage(img, "img.bmp");

	img.fill(Color(255, 255, 255));
	img.setColor(25, 25, Color(255, 0, 0));
	saveImage(img, "img2.bmp");
}

void oppg3() {
	//Shape s(Color(0, 0, 0));
	/*
	 * Pure virtual vil si en virtuel metode uten implementasjon.
	 * Kan ikke kontrueres fordi klassen er abstrakt.
	 */
}

void oppg4() {
	Image img(150, 150);

	Line l(0, 0, 100, 50, Color(255, 0, 0));
	l.draw(img);
	saveImage(img, "img3.bmp");

	img.fill(Color(0, 0, 0));
	l = Line(0, 0, 100, 200, Color(0, 255, 0));
	l.draw(img);
	saveImage(img, "img4.bmp");
}

void oppg5() {
	Image img(200, 200);
	Rectangle r(Line(0, 0, 100, 200, Color(255, 0, 0)));
	r.draw(img);
	saveImage(img, "img5.bmp");
}

void oppg6() {
	Image img(200, 200);
	Circle c1(100, 100, 8, Color(0, 0, 255));
	Circle c2(100, 100, 90, Color(100, 100, 100));
	c1.draw(img);
	c2.draw(img);
	saveImage(img, "img6.bmp");
}

void oppg7() {
	//Test
	Image img(250, 250);

	Line l1(0, 0, 100, 50, Color(255, 0, 0));
	Line l2(0, 0, 100, 200, Color(0, 255, 0));
	Rectangle r(Line(0, 0, 100, 200, Color(255, 0, 0)));
	Circle c1(100, 100, 8, Color(0, 0, 255));
	Circle c2(100, 100, 90, Color(100, 100, 100));

	Canvas can;
	can.addShape(&l1);
	can.addShape(&l2);
	can.addShape(&r);
	can.addShape(&c1);
	can.addShape(&c2);
	can.rasterizeTo(img);
	saveImage(img, "img7.bmp");

	//Smiley
	Image img2(200, 200);
	Canvas smiley;

	Color color(255, 255, 0);
	Circle head(100, 100, 80, color);
	Circle leftEye(70, 105, 13, color);
	Circle rightEye(130, 105, 13, color);
	Line mouth(70, 60, 130, 60, color);

	smiley.addShape(&head);
	smiley.addShape(&leftEye);
	smiley.addShape(&rightEye);
	smiley.addShape(&mouth);

	smiley.rasterizeTo(img2);
	saveImage(img2, "smiley.bmp");
}
