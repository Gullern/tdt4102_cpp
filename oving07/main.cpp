#include <iostream>

#include "main.h"
#include "fileio.h"
#include "substitution.h"

using namespace std;

int main() {
	//tasks();
	game();
}

void game() {
	char input[] = "text.txt";
	Substitution sub(input);
	sub.play();
}

void tasks() {
	char file1[] = "output.txt";
	char file2[] = "input.txt";
	char file3[] = "output2.txt";
	char file4[] = "text.txt";

	//Oppg. 1
	consoleToFile(file1);
	addLineNumbers(file2, file3);

	//Oppg. 2
	printCharStatistics(file4);

	//Oppg. 3
	printWordStatistics(file2);
}
