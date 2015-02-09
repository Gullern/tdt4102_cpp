#include <string>
#include <sstream>
#include <ctime>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <iomanip>

#include "substitution.h"

using namespace std;

Substitution::Substitution(char filename[]) : cipher(), guessCipher(), plainText(), cipherText(), rawText() {
	ifstream input(filename);

	string line;
	while (getline(input, line)) {
		rawText.append(cleanString(line));
	}
	input.close();

	srand(time(0));
}

void Substitution::play() {
	cout << "Encryption game:\n-----------------------\n\n";
	selectRandomText();
	generateCipher();

	//cout << plainText << endl; // Debug

	while (checkForErrors(encodeString(cipherText, guessCipher))) {
		printUserInformation(encodeString(cipherText, guessCipher));
		askUser();
	}

	cout << plainText << endl;
	cout << "Success!\n";
}

char Substitution::encodeChar(char a, map<char, char> &map) const {
	return a == ' ' ? ' ' : map[a];
}

string Substitution::encodeString(string plainText, map<char, char> &map) const {
	string encoded;
	encoded.resize(plainText.length());
	for (int i = 0; i < plainText.length(); i++) {
		encoded[i] = encodeChar(plainText[i], map);
	}
	return encoded;
}

int Substitution::countSpaces(string input) const {
	int number = 0;
	for (int i = 0; i < input.length(); i++) {
		if (input[i] == ' ') {
			number++;
		}
	}
	return number;
}

int Substitution::checkForErrors(string input) const {
	int errors = 0;
	int minLength = input.length() < plainText.length() ? input.length() : plainText.length();
	for (int i = 0; i < minLength; i++) {
		if (plainText[i] != ' ' && plainText[i] != input[i]) {
			errors++;
		}
	}
	return errors;
}

string Substitution::cleanString(string input) const {
	int i = 0;
	while (i < input.length()) {
		input[i] = tolower(input[i]);
		if ((input[i] < 'a' || input[i] > 'z') && input[i] != ' ') {
			input.erase(i, 1);
		} else {
			i++;
		}
	}
	return input;
}

void Substitution::generateCipher() {
	const int alphSize = 26;
	char alph[alphSize];

	for (int k = 0; k < 2; k++) {
		map<char, char> &m = k == 0 ? cipher : guessCipher;

		for (int i = 0; i < alphSize; i++) {
			alph[i] = char('a' + i);
		}

		int c = 0;
		for (int i = 0; i < alphSize; i++) {
			c = rand() % (alphSize - i);
			m[char('a' + i)] = alph[c];

			if (k == 0) {
				decodeCipher[alph[c]] = char('a' + i);
			}

			alph[c] = alph[alphSize - i - 1];
		}

		/*
		for (map<char, char>::iterator it = m.begin(); it != m.end(); it++) {
			cout << it->first << ':' << it->second << endl;
		}
		*/
	}

	cipherText = encodeString(plainText, cipher);
}

void Substitution::selectRandomText() {
	/*
	cout << rawText << endl;

	for (int i = 0; i < rawText.length(); i++) {
		cout << i % 10;
	}
	cout << endl;
	*/

	int length = rand() % maxWords + 1;
	int earliest = 0;
	int latest = 0; // will calculate latest next

	int countWords = 0;
	bool space = true;
	int i = 0;
	for (i = rawText.length() - 1; i >= 0; i--) {
		if (space) {
			space = rawText[i] == ' ';
		} else if (rawText[i] == ' ') {
			countWords++;
			space = true;
		}
		if (countWords == length){
			break;
		}
	}
	latest = i + 1;
	int start = earliest + rand() % (latest - earliest);

	int index = 0;
	if (start > 0) {
		index = rawText.find(' ', start);
	}

	while(rawText[index] == ' ') {
		index++;
	}
	stringstream buffer(rawText.substr(index));
	string select;
	int count = 0;
	while (count < length && buffer >> select) {
		count++;
		plainText.append(select + ' ');
	}

	/*
	cout << "length=" << length << endl;
	cout << "latest=" << latest << endl;
	cout << "start=" << start << endl;
	cout << endl << plainText << endl;
	*/
}

void Substitution::askUser() {
	char c1;
	char c2;

	for (int k = 0; k < 2; k++) {
		if (k == 0) {
			cout << "Please enter a character to replace:";
		} else {
			cout << "What should replace it?:";
		}

		char read;
		string input;
		stringstream buffer;
		string dump;

		while (true) {
			getline(cin, input);
			buffer.clear();
			buffer.str(string());
			buffer << input;
			if (buffer >> read) {
				if (!(buffer >> dump) && read >= 'a' && read <= 'z') {
					break;
				}
			}
			cout << "Invalid sign!\n";
		}
		if (k == 0) {
			c1 = read;
		} else {
			c2 = read;
		}
	}
	guessCipher[c1] = c2;
	cout << endl;
}

int Substitution::printErrors(string userPlaintext) const {
	int errors = checkForErrors(userPlaintext);
	cout << "Number of errors: " << errors
			<< " (" << setprecision(2) << (1 - errors * 1.0 / (plainText.length() - countSpaces(userPlaintext))) * 100 << "% correct)\n";
	return errors;
}

void Substitution::printUserInformation(string userPlaintext) const {
	cout << "Ciphertext:\t\t" << cipherText << endl;
	cout << "Decoded ciphertext:\t" << parseDecryptedText(userPlaintext )<< endl;
	printErrors(userPlaintext);
}

string Substitution::parseDecryptedText(string userPlaintext) const {
	string output;
	int minLength = userPlaintext.length() < plainText.length() ? userPlaintext.length() : plainText.length();
	output.resize(minLength);
	for (int i = 0; i < minLength; i++) {
		if (userPlaintext[i] == plainText[i]) {
			output[i] = toupper(userPlaintext[i]);
		} else {
			output[i] = cipherText[i];
		}
	}
	return output;
}
