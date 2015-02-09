#include <iostream>
#include <iomanip>
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include "main.h"
#include "cannonball.h"

using namespace std;

int main() {
	//cout << "testing..." << endl;
	//test();
	//test2();
	
	playTargetPractice();
	//srand(time(NULL));
	//srand((int)rand());
	//for ( int i = 0; i < 10; ++i)
	//cout << rand() % 50 << endl;
	
	return 0;
}

void playTargetPractice() {
	cout << "Enemy ship spotted somewhere between 100 and 10000 meters ahead.\nThe ship is 50 meters long.\nWe have 10 shots left.\nBring them down..." << endl;
	
	srand(time(NULL));
	srand((int)rand());
	//unsigned long long number = rand();
	unsigned long long number = pow(rand(), rand() % 3) * rand();
	int target = number % (10000 - 100) + 100;
	cout << target << endl;
	int margin = 50;
	
	double velocityX = 0;
	double velocityY = 0;
	double theta = 0;
	double absVelocity = 0;
	double distance;
	
	for (int shot = 0; shot < 10; shot++) {
		getUserInput(&theta, &absVelocity);
		getVelocityVector(theta, absVelocity, &velocityX, &velocityY);
		distance = targetPractice(target, velocityX, velocityY);
		
		cout << "Trial " << shot + 1 << ": ";
		
		if (abs(distance) < margin) {
			cout << "Target eliminated!" << endl;
			break;
		} else if (theta == 90) {
			cout << "You successfully shot yourself... Congratulations" << endl;
			break;
		} else if (distance < 0) {
			cout << "Too short, miss by " << - distance << " meters." << endl;
		} else if (distance > 0) {
			cout << "Too long, miss by " << distance << " meters." << endl;
		}
	}
}

void test2() {
	double theta = 30;
	double absVelocity = 200;
	
	double velocityX = 0;
	double velocityY = 0;
	getVelocityVector(theta, absVelocity, &velocityX, &velocityY);
	
	cout << flightTime(25) << endl;
	cout << getDistanceTraveled(velocityX, velocityY) << endl;
	cout << optimalAngleForMaxDistance(absVelocity) << endl;
	cout << targetPractice(3000, velocityX, velocityY) << endl;
}

void test() {
	double t[] = {0.0, 2.5, 5.0};
	double startVelX = 50;
	double startVelY = 25;
	
	printf("\t T = %.1f  T = %.1f  T = %.1f\n", t[0], t[1], t[2]);
	
	cout << "acclX\t";
	cout << fixed << setprecision(2);
	cout << setw(6) << acclX() << setw(9) << acclX() << setw(9) << acclX() << endl;
	cout << "acclY\t";
	cout << setw(6) << acclY() << setw(9) << acclY() << setw(9) << acclY() << endl;
	cout << "velX\t";
	cout << setw(6) << velX(startVelX, t[0]) << setw(9) << velX(startVelX, t[1]) << setw(9) << velX(startVelX, t[2]) << endl;
	cout << "velY\t";
	cout << setw(6) << velY(startVelY, t[0]) << setw(9) << velY(startVelY, t[1]) << setw(9) << velY(startVelY, t[2]) << endl;
	cout << "velIntX\t";
	cout << setw(6) << velIntX(startVelX, t[0]) << setw(9) << velIntX(startVelX, t[1]) << setw(9) << velIntX(startVelX, t[2]) << endl;
	cout << "velIntY\t";
	cout << setw(6) << velIntY(startVelY, t[0]) << setw(9) << velIntY(startVelY, t[1]) << setw(9) << velIntY(startVelY, t[2]) << endl;
	cout << "posX\t";
	cout << setw(6) << posX(startVelX, t[0]) << setw(9) << posX(startVelX, t[1]) << setw(9) << posX(startVelX, t[2]) << endl;
	cout << "posY\t";
	cout << setw(6) << posY(startVelY, t[0]) << setw(9) << posY(startVelY, t[1]) << setw(9) << posY(startVelY, t[2]) << endl;
	cout << "posIntX\t";
	cout << setw(6) << posIntX(startVelX, t[0]) << setw(9) << posIntX(startVelX, t[1]) << setw(9) << posIntX(startVelX, t[2]) << endl;
	cout << "posIntY\t";
	cout << setw(6) << posIntY(startVelY, t[0]) << setw(9) << posIntY(startVelY, t[1]) << setw(9) << posIntY(startVelY, t[2]) << endl;
}
