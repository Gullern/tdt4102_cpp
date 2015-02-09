#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <string>
#include <cstring>
#include "minesweeper.h"

using namespace std;

bool Minesweeper::seeded = false;

Minesweeper::Minesweeper() : height(0), width(0), mines(0), open(0), board(), mask() {
	if (! seeded) {
		srand(time(0));
		seeded = true;
	}
}

void Minesweeper::makeBoard() {
	board = Matrix(height, width);
	mask = Matrix(height, width);
}

void Minesweeper::placeMines(unsigned int firstRow, unsigned int firstColumn) {
	unsigned int row = 0;
	unsigned int column = 0;
	int element = 0;
	unsigned int r = 0;
	unsigned int c = 0;

	for (unsigned int n = 0; n < mines; n++) {
		row = rand() % height;
		column = rand() % width;
		while (board.getElement(row, column) == -1 || (row == firstRow && column == firstColumn)) {
			row = rand() % height;
			column = rand() % width;
		}

		board.setElement(row, column, -1);

		for (int i = 0; i < 9; i++) {
			r = row - 1 + i / 3;
			c = column - 1 + i % 3;
			if (r < 0 || r >= height || c < 0 || c >= width || i == 4) {
				continue;
			}
			element = board.getElement(r, c);
			if (element != -1) {
				board.setElement(r, c, element + 1);
			}
		}
	}
}

bool Minesweeper::validateInput(int number, int lower, int higher = 1000) const {
	if (number < 0 || number < lower || number > higher) {
		cout << "Invalid input: ";
		return false;
	}
	return true;
}

bool Minesweeper::readInt(int &number) const {
	string input = "";
	getline(cin, input);

	int input_number = 0;
	string input_string;
	stringstream stream(input);
	stream >> input_number;
	if (stream.fail()) {
		stream.clear();
		stream.ignore();
		return false;
	}

	if (stream >> input_string) {
		return false;
	}

	number = input_number;
	return true;
}

void Minesweeper::getInput() {
	unsigned int height = 0;
	unsigned int width = 0;
	unsigned int mines = 0;

	int read = 0;
	while (true) {
		cout << "Enter height: ";
		while (! readInt(read)) {
			cout << "Invalid input: Unknown sign!\n";
			cout << "Enter height: ";
		}
		//if (validateInput(read, 2)) {
		if (validateInput(read, 2, 300)) {
			break;
		}
		cout << "Height must be at least 2 and no more than 300!\n";
		cout << "Enter height: ";
	}
	height = read;

	read = 0;
	while (true) {
		cout << "Enter width: ";
		while (! readInt(read)) {
			cout << "Invalid input: Unknown sign!\n";
			cout << "Enter width: ";
		}
		//if (validateInput(read, 2)) {
		if (validateInput(read, 2, 35)) {
			break;
		}
		cout << "Width must be at least 2 and no more than 35!\n";
		cout << "Enter width: ";
	}
	width = read;

	read = 0;
	while (true) {
		cout << "Enter number of mines: ";
		while (! readInt(read)) {
			cout << "Invalid input: Unknown sign!\n";
			cout << "Enter number of mines: ";
		}
		if (validateInput(read, 1, width * height / 2)) {
			break;
		}
		cout << "number of mines must be at least 1 and no more than "
				<< width * height / 2
				<< "!\nEnter number of mines:";
	}
	mines = read;

	this->height = height;
	this->width = width;
	this->mines = mines;
	this->open = 0;
}

void Minesweeper::setFlag(unsigned int row, unsigned int column) {
	int mark = mask.getElement(row, column);
	if (mark != 1) {
		mask.setElement(row, column, (mark == 0) * 2);
	}
}

bool Minesweeper::openSquare(unsigned int row, unsigned int column) {
	int mark = mask.getElement(row, column);
	if (mark == 1 || mark == 2) {
		return false;
	}
	int element = board.getElement(row, column);
	if (element == -1) {
		return true;
	}

	mask.setElement(row, column, 1);
	open++;
	if (element == 0) {
		unsigned int r = 0;
		unsigned int c = 0;
		for (int i = 0; i < 9; i++) {
			r = row - 1 + i / 3;
			c = column - 1 + i % 3;
			if (r < 0 || r >= height || c < 0 || c >= width || i == 4) {
				continue;
			}
			openSquare(r, c);
		}
	}
	return false;
}

void Minesweeper::printBoard(bool solution) const {
	char unknown = '.';
	char empty = ' ';
	char mine = '*';
	char marked = 'X';
	char v = (char) 196;
	char h = (char) 179;
	int element = 0;
	int mark = 0;

	string output = "";
	ostringstream convert;

	output += "     ";
	//cout << "     ";
	for (unsigned int i = 0; i < width; i++) {
		output += (char) ('a' + i);
		output += " ";
		//cout << (char) ('a' + i) << " ";
	}
	output += '\n';
	//cout << endl;

	output += "   ";
	output += (char) 218;
	//cout << "   " << (char) 218;
	for (unsigned int i = 0; i < 2 * width + 1; i++) {
		output += v;
		//cout << v;
	}
	output += (char) 191;
	output += '\n';
	//cout << (char) 191 << endl;

	for (unsigned int i = 0; i < height; i++) {
		convert << setw(3) << i;
		output += convert.str();
		convert.str("");
		convert.clear();
		output += h;
		//cout << setw(3) << i;
		//cout << h;
		for (unsigned int j = 0; j < width; j++) {
			output += " ";
			//cout << setw(2);
			element = board.getElement(i, j);
			mark = mask.getElement(i, j);
			if (solution) {
				if (element == -1) {
					output += mine;
					//cout << mine;
				} else if (element == 0) {
					output += empty;
					//cout << empty;
				} else {
					convert << element;
					output += convert.str();
					convert.str("");
					convert.clear();
					//cout << element;
				}
			} else {
				if (mark == 2) {
					output += marked;
					//cout << marked;
				} else if (mark == 0) {
					output += unknown;
					//cout << unknown;
				} else {
					if (element == 0 || element == -1) {
						output += empty;
						//cout << empty;
					} else {
						convert << element;
						output += convert.str();
						convert.str("");
						convert.clear();
						//cout << element;
					}
				}
			}
		}
		output += " ";
		output += h;
		output += '\n';
		//cout << setw(2) << h << endl;
	}

	output += "   ";
	output += (char) 192;
	//cout << "   " << (char) 192;
	for (unsigned int i = 0; i < 2 * width + 1; i++) {
		output += v;
		//cout << v;
	}
	output += (char) 217;
	output += '\n';
	output += "Number of mines: ";
	convert << mines;
	output += convert.str();
	convert.str("");
	convert.clear();
	output += '\n';
	//cout << (char) 217 << endl;
	//cout << "Number of mines: " << mines << endl;
	cout << output;
}

void Minesweeper::play() {
	cout << "Welcome to Jan's epic minesweeper\nChoose your game setup:\n";

	char mark_char = '?';
	bool running = true;
	while (running) {
		getInput();
		makeBoard();

		cout << "Open a square by specifying the position: <row> <column>. \n\tExample: 2 c\n"
					"Mark a square (as potential mine) by writing '?' followed by the position. \n\tExample ? 0 b\n"
					"Unmark a square by remarking it.\n"
					"Marked squares cannot be opened (as a safety)\n\n";

		bool setup = true;
		bool defeated = false;
		while (! defeated) {
			printBoard(false);

			bool error = false;
			unsigned int row = 0;
			unsigned int column = 0;
			bool mark_mode = false;

			char read_char = '\0';
			int read_int = 0;
			string input = "";

			cout << ">>";
			getline(cin, input);

			string input_string;
			stringstream stream(input);

			stream >> read_int;
			if (stream.fail()) {
				stream.clear();
				stream >> read_char;
				error = error || read_char != mark_char || stream.fail();
				mark_mode = true;
				stream >> read_int;
				error = error || stream.fail();
			}
			row = (unsigned int) read_int;
			stream >> read_char;
			error = error || stream.fail();
			column = (unsigned int) (read_char - 'a');
			error = error || stream.fail();
			if (stream >> read_char) {
				error = true;
			}

			if (error) {
				stream.clear();
				stream.ignore();
				cout << "Invalid input: Unknown sign!\n";
				continue;
			}

			if (! validateInput(row, 0, height - 1) || ! validateInput(column, 0, width - 1)) {
				cout << "Incorrect position!\n";
				continue;
			}

			if (setup) {
				placeMines(row, column);
				setup = false;
			}

			if (mark_mode) {
				setFlag(row, column);
			} else {
				defeated = openSquare(row, column);
			}

			if (open >= height * width - mines) {
				break;
			}
		}

		if (defeated) {
			cout << "Boooooom!!\nSorry you lost.\n";
		} else {
			cout << "Congratulations, you are victorious!\n";
		}

		cout << "Solution:\n";
		printBoard(true);

		while(true) {
			cout << "Play again? [y/n]: ";
			char play = '\0';
			string input = "";
			getline(cin, input);
			stringstream stream(input);
			stream >> play;
			if (play == 'n' || play == 'N') {
				running = false;
				break;
			} else if (play == 'y' || play == 'Y') {
				break;
			}
			cout << "Invalid input: Unknown symbol!\n";
		}
	}
}
