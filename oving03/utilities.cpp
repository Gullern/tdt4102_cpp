#include <iostream>
#include <cstdlib>
#include <cmath>
#include "utilities.h"

int randomWithLimits(double low, double high) {
	return ceil(low) + rand() % (int) (high - low + 1);
}

char randomCharWithLimits(char low, char high) {
	return (char) ceil(low) + rand() % (int) (high - low + 1);
}
