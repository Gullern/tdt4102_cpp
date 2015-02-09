#include <iostream>
#include "simpleSet.h"

/** Construct empty set **/
SimpleSet::SimpleSet()  : maxSize(10), currentSize(0){
	data = new int[maxSize];
}

/** Destruct set **/
SimpleSet::~SimpleSet() {
	tearDown();
	data = 0;
	maxSize = 0;
	currentSize = 0;
}

/** Tears down heap allocated data **/
void SimpleSet::tearDown() {
	delete[] data;
}

/** Insert i into set, return true if the element was inserted, else false **/
bool SimpleSet::insert(int i) {
	if (find(i) != -1) {
		return false;
	}

	if (currentSize == maxSize) {
		resize(2 * currentSize);
	}
	*(data + currentSize) = i;
	++currentSize;
	return true;
}

/** Returns true if i is in the set **/
bool SimpleSet::exists(int i) const {
	return find(i) != -1;
}

/** Removes i from the set, return true if an element was removed **/
bool SimpleSet::remove(int i) {
	for (int *t = data; t != data + currentSize; ++t) {
		if (*t == i) {
			++t;
			while(t != data + maxSize) {
				*(t - 1) = *t;
				++t;
			}
			return true;
		}
	}
	return false;
}

/** Returns the index where i may be found, else an invalid index. **/
int SimpleSet::find(int i) const {
	for (int *t = data; t != data + currentSize; ++t) {
		if (*t == i) {
			return t - data;
		}
	}
	return -1;
}

/** Resizes data, superflous elements are dropped. **/
void SimpleSet::resize(int n) {
	if (n == maxSize) { return; }
	if (n < maxSize) {
		maxSize = n;
		if (n < currentSize) {
			currentSize = n;
		}
	} else {
		maxSize = n;
		int *newData = new int[maxSize];
		for (int i = 0; i != currentSize; ++i) {
			*(newData + i) = *(data + i);
		}
		tearDown();
		data = newData;
	}
}

// ###### Debugging

/** Prints the set **/
void SimpleSet::print() const {
	std::cout << '{';
	for (int *i = data; i != data + currentSize; ++i) {
		std::cout << *i;
		if (i != data + currentSize - 1) {
			std::cout << ',';
		}
	}
	std::cout << '}';
	std::cout << "cs=" << currentSize << ",mx=" << maxSize << std::endl;
}
