#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include "tests.h"
#include "utilities.h"

using namespace std;

void testPart2() {
	int v0 = 5;
	int increment = 2;
	int iterations = 10;
	incrementByValueNumTimes(&v0, increment, iterations);
	cout << "v0: " << v0 
		<< " increment: " << increment 
		<< " iterations: " << iterations << endl;
}

void incrementByValueNumTimes(int* startValue, int increment, int numTimes) {
	for (int i = 0; i < numTimes; i++) {
		*startValue += increment;
	}
}

// Denne funksjonen MÅ bruke peker; noe annet gir ikke mening!
void swapNumbers(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
	// swap(a,b);
}

void testPart3() {
	int len = 100000;
	//int *percentages = new int[len];
	int percentages[len];
	int percentages2[len];
	randomizeArray(percentages, len);
	randomizeArray(percentages2, len);
	//printArray(percentages, len);
	//cout << medianOfArray(percentages, len) << endl;
	//swapNumbers(percentages, percentages + 1);
	//printArray(percentages, len);
	sortArray(percentages, percentages2, len);
	//printArray(percentages, len);
	//cout << medianOfArray(percentages, len) << endl;
}

void randomizeArray(int *array, int length) {
	for (int *end = array + length, *i = array; i != end; i++) {
		*i = rand() % 100 + 1;
	}
}

void printArray(int* array, int length) {
	for (int *end = array + length, *i = array; i != end; i++) {
		cout << *i << " ";
	}
	cout << "\b\n";
}

void sortArray(int *array, int *array2, int length) {
	cout << "quick sort..." << endl;
	qsort(0, length - 1, array);
	cout << "insertion sort..." << endl;
	isort(array2, length);
}

// In-place quicksort
void qsort(int min, int max, int* array) {
	if (min >= max) { return; }
	
	int* pivotIndex = array + min + rand() % (max - min);
	int* left = array + min;
	int* right = array + max;
	int* index = left;
	int pivot = *pivotIndex;
	
	swap (*right, *pivotIndex);
	for (int* i = left; i != right; i++) {
		if (*i <= pivot) {
			swap(*i, *index);
			index++;
		}
	}
	swap(*index, *right);
	
	qsort(min, (int) (index - array - 1), array);
	qsort((int) (index - array + 1), max, array);
}

void isort(int *array, int length) {
	int *j;
	for (int *i = array + 1; i < array + length; i++) {
		j = i;
		while (j > array && *(j - 1) > *j) {
			swap(*j, *(j - 1));
			j--;
		}
	}
}	

double medianOfArray(int *array, int length) {
	return (*(array + (length - 1) / 2) + *(array + (int) ceil((length - 1) / 2.0)) ) / 2.0;
}

void testPart4() {
	const int len = 5 * 8;
	char grades[len + 1];
	grades[len] = '\0';
	randomizeCString(grades, len, 'A', 'F');
	cout << grades << endl;
	//readInputToCString(grades, len, 'A', 'F');
	int grade_freq[6];
	for (int *i = grade_freq; i < grade_freq + 6; i++) {
		*i = countOccurencesOfCharacter(grades, len, 'A' + (int) (i - grade_freq));
	}
	double average = 0;
	for (int *i = grade_freq; i < grade_freq + 6; i++) {
		average += *i * ((int) (i - grade_freq) + 1);
	}
	average /= len;
	cout << "Average: " << average << endl;
}

void randomizeCString(char *array, int length, char low, char high) {
	for (char *i = array; i < array + length; i++) {
		*i = randomCharWithLimits(low, high);
	}
}

void readInputToCString(char *array, int length, char low, char high) {
	cout << "Skriv inn " << length 
	<< " bokstav(er) i intervallet "
	<< low << " til " << high << ": " << endl;
	
	for (char *i = array; i < array + length; i++) {
		char temp;
		do {
			cin >> temp;
			temp = toupper(temp);
			if (temp < low || temp > high) {
				cout << "Ikke gyldig karakter! Prøv på nytt: ";
			}
		}  while (temp < low || temp > high);
		*i = temp;
	}
}

int countOccurencesOfCharacter(char *array, int length, char key) {
	int occ = 0;
	for (char *i = array; i < array + length; i++) {
		if (*i == key) {
			occ++;
		}
	}
	return occ;
}
