#ifndef TEMPLATE_H
#define TMEPLATE_H

#include <iostream>
#include <cstdlib>
#include <ctime>

template <typename A>
void printArray(A *array, int size) {
	std::cout << '{';
	for (A *i = array; i < array + size; ++i) {
		std::cout << *i;
		if (i != array + size - 1) {
			std::cout << ',';
		}
	}
	std::cout << '}' << std::endl;
}

template <typename A>
void shuffle(A *array, int size) {
	srand(time(0));
	int a = 0;
	int b = 0;
	for (int i = 0; i < 10000; ++i) {
		a = rand() % size;
		b = rand() % size;
		A temp = array[a];
		array[a] = array[b];
		array[b] = temp;
	}
}

template <typename A>
A maximum(A a, A b) {
	if (a > b) { return a; }
	return b;
}

#endif
