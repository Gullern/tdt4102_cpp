#ifndef MINESWEEPER_H
#define MINESWEEPER_H

#include "matrix.h"

class Minesweeper {
	unsigned int height;
	unsigned int width;
	unsigned int mines;
	unsigned int open;
	Matrix board;
	Matrix mask;
	void makeBoard();
	void placeMines(unsigned int firstRow, unsigned int firstColumn);
	bool readInt(int &number) const;
	bool validateInput(int number, int lower, int higher) const;
	void getInput();
	void setFlag(unsigned int row, unsigned int column);
	bool openSquare(unsigned int row, unsigned int column);
	void printBoard(bool solution) const;
public:
	static bool seeded;
	Minesweeper();
	void play();
};


#endif
