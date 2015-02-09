#include <iostream>
#include "mastermind.h"
#include "tests.h"

using namespace std;

void playMasterMind() {
	const int SIZE = 4;
	const int LETTERS = 6;
	
	char code[SIZE + 1];
	code[SIZE] = '\0';
	char guess[SIZE + 1];
	guess[SIZE] = '\0';
	randomizeCString(code, SIZE, 'A', 'A' + LETTERS);
	
	cout << endl << endl << "===========================\n";
	cout << "Velkommen til mastermind.\n";
	cout << "Koden er paa " << SIZE << " bokstaver, A til " << (char) ('A' + LETTERS) << ".\n";
	
	//cout << code << endl;
	
	bool running = true;
	
	while (running) {
		int trials = 0;
		int cc = 0;
		int c = 0;
		while (trials <= 10) {
			readInputToCString(guess, SIZE, 'A', 'A' + LETTERS);
			cc = checkCharactersAndPosition(code, guess, SIZE);
			c = checkCharacters(code, guess, SIZE, LETTERS);
			
			trials++;
			
			if (cc == 4) {
				cout << "Gratulerer, du gjettet koden: " << code << ", paa " << trials << " forsok.\n";
				break;
			} else {
				cout << c << " riktige, " << cc << " paa rett plass.\n";
			}
		}
		if (cc != 4) {
			cout << "Beklager, du har brukt alle " << trials - 1 << " forsokene.\n";
		}
		cout << "Prove igjen?: [y/n]";
		char choice;
		cin >> choice;
		if (choice == 'n') {
			running = false;
		}
	}
}

int checkCharactersAndPosition(char *code, char *guess, int length) {
	int corr = 0;
	for (int i = 0; i < length; i++) {
		if (*(guess + i) == *(code + i)) {
			corr++;
		}
	}
	return corr;
}

int checkCharacters(char *code, char *guess, int length, int letters) {
	int corr = 0;
	for (char c = 'A'; c <= 'A' + letters; c++) {
		//cout << c << countOccurencesOfCharacter(guess, length, c) << countOccurencesOfCharacter(code, length, c) << endl;
		corr += min(countOccurencesOfCharacter(guess, length, c)
		, countOccurencesOfCharacter(code, length, c));
	}
	return corr;
}
