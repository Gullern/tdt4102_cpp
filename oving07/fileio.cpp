#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <map>
#include <algorithm>

#include "fileio.h"

using namespace std;

void consoleToFile(char readFile[]) {
	ofstream output(readFile);
	string word;
	bool running = true;
	while (running) {
		cin >> word;
		if (word == "quit" || word == "exit") {
			running = false;
		} else {
			output << word << endl;
		}
	}
	output.close();
}

void addLineNumbers(char readFile[], char writeFile[]) {
	ifstream input(readFile);
	ofstream output(writeFile);

	string line;
	int i = 1;
	while (getline(input, line)) {
		output << i++ << ' ' << line << endl;
	}
	input.close();
	output.close();
}

void printCharStatistics(char readFile[]) {
	const int alph_size = 26;

	ifstream input(readFile);
	int stats[alph_size]; //English letters only

	for (int *i = stats; i < stats + alph_size; i++) {
		*i = 0;
	}

	int total = 0;
	char read;
	while(input >> read) {
		read = tolower(read);
		if (read >= 'a' && read <= 'a' + alph_size) {
			stats[read - 'a']++;
		}
		total++;
	}

	cout << "Character statistics:\n"
			"Total number of characters: "
			<< total;
	for (int i = 0; i < alph_size; i++) {
		if (i % 4 == 0) {
			cout << '\n';
		}
		cout << char('a' + i) << ' ' << stats[i] << '\t';
	}
	cout << endl << endl;
}

void cleanString(string &str) {
	int i = 0;
	while (i < str.length()) {
		str[i] = tolower(str[i]);
		if ((str[i] < 'a' || str[i] > 'z') && str[i] != ' ') {
			str.erase(i, 1);
		} else {
			i++;
		}
	}
}

void printWordStatistics(char readFile[]) {
	ifstream input(readFile);

	string longest = "";
	int number = 0;
	int lines = 0;
	int average = 0;

	map<string, int> stats;
	string readLine;
	stringstream buffer;
	string readWord;

	while (getline(input, readLine)) {
		cleanString(readLine);
		buffer.clear();
		buffer << readLine;
		while (buffer >> readWord) {
			if (readWord.length() > longest.length()) {
				longest = readWord;
			}
			average += readWord.length();
			stats[readWord]++;
			number++;
		}
		lines++;
	}

	average = number == 0 ? 0 : average / number;

	cout << "Text statistics:\n"
			"Longest word: " << longest << endl
			<< "Number of words: " << number << endl
			<< "Number of lines: " << lines << endl
			<< "Average word length: " << average << endl;

	map<string, int>::iterator it;
	for (it = stats.begin(); it != stats.end(); it++) {
		cout << it->first << ": " << it->second << endl;
	}
}
