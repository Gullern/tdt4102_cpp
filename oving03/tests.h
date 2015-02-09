#ifndef TESTS_H
#define TESTS_H

extern void testPart2();
extern void incrementByValueNumTimes(int* startValue, int increment, int numTimes);
extern void swapNumbers(int* a, int* b);
extern void testPart3();
extern void randomizeArray(int *array, int length);
extern void printArray(int* array, int length);
extern void sortArray(int *array, int *array2, int length);
extern void qsort(int min, int max, int* array);
extern void isort(int *array, int length);
extern double medianOfArray(int *array, int length);
extern void testPart4();
extern void randomizeCString(char *array, int length, char low, char high);
extern void readInputToCString(char *array, int length, char low, char high);
extern int countOccurencesOfCharacter(char *array, int length, char key);

#endif
