#include <iostream>
#include <cstdlib>
#include <ctime>
#include "main.h"
#include "utilities.h"
#include "tests.h"
#include "mastermind.h"

using namespace std;

int main() {
	srand(time(0));
	
	cout << randomWithLimits(-1.2, 5.3);
	cout << randomCharWithLimits('J', 'N');
	cout << endl;
	
	testPart2();
	
	int a = 3;
	int b = 9;
	swapNumbers(&a, &b);
	cout << a << b << endl;
	
	testPart3();
	
	testPart4();
	
	playMasterMind();
	
	return 0;
}
