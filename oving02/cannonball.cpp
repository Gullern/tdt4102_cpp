#include <iostream>
#include <cmath>
#include "cannonball.h"

using namespace std;

double acclX() {
	return 0.0;
}

double acclY(){
	return - 9.81; //const.
}

double velX(double startVelX, double time) {
	return startVelX + acclX() * time;
}

double velY(double startVelY, double time) {
	return startVelY + acclY() * time;
}

double velIntX(double startVelX, double time) {
	const int INTERVALS = 10000;
	
	double dt = time / INTERVALS;
	
	double velX = startVelX;
	double acc = acclX();
	int n = time / dt;
	
	for (int i = 0; i < n; i++) {
		velX += acc * dt;
	}
	return velX;
}

double velIntY(double startVelY, double time) {
	const int INTERVALS = 10000;
	
	double dt = time / INTERVALS;
	
	double velY = startVelY;
	double acc = acclY();
	int n = time / dt;
	
	for (int i = 0; i < n; i++) {
		velY += acc * dt;
	}
	return velY;
}

double posX(double startVelX, double time) {
	const double startPosX = 0;
	
	return startPosX + startVelX * time;
}

double posY(double startVelY, double time) {
	const double startPosY = 0;
	
	return startPosY + startVelY * time + 1.0 / 2 * acclY() * time * time;
}

double posIntX(double startVelX, double time) {
	const int INTERVALS = 10000;
	double dt = time / INTERVALS;
	
	const double startPosX = 0;
	
	double posX = startPosX;
	int n = time / dt;
	
	for (int i = 0; i < n; i++) {
		posX += velIntX(startVelX, dt * i) * dt;
	}
	return posX;
}

double posIntY(double startVelY, double time) {
	const int INTERVALS = 10000;
	double dt = time / INTERVALS;
	
	const double startPosY = 0;
	
	double posY = startPosY;
	int n = time / dt;
	
	for (int i = 0; i < n; i++) {
		posY += velIntY(startVelY, dt * i) * dt;
	}
	return posY;
}

void printTime(double time) {
	int hours = 0;
	int minutes = 0;
	
	hours = time / 3600;
	time -= hours * 3600;
	minutes = time / 60;
	time -= minutes * 60;
	
	cout << hours << " time";
	if (hours != 1)
		cout << "r";
	cout << ", " << minutes << " minutt";
	if (minutes != 1)
		cout << "er";
	cout << ", " << time << " sekund";
	if (time != 1)
		cout << "er";
	cout << endl;
}

double flightTime(double startVelY) {
	const double start_dt = 0.01;
	const double min_dt = 0.00001;
	const double margin = 0.001;
	
	double time = 0;
	double velY = startVelY;
	double dt = start_dt;
	
	while((velY - startVelY) * (velY - startVelY) < margin) {
		time += dt;
		velY = velIntY(startVelY, time);
	}
	
	while((velY + startVelY) > margin * 100) {
		time += dt;
		velY = velIntY(startVelY, time);
	}
	dt = min_dt;
	while((velY + startVelY) > margin) {
		time += dt;
		velY = velIntY(startVelY, time);
	}
	
	return time;
}

void getUserInput(double *theta, double *absVelocity) {
	cout << "Enter angle [degrees]: ";
	cin >> *theta;
	cout << "Enter velocity [m/s]: ";
	cin >> *absVelocity;
}

double getVelocityX(double theta, double absVelocity) {
	return absVelocity * cos(theta * 3.141592 / 180);
}

double getVelocityY(double theta, double absVelocity) {
	return absVelocity * sin(theta * 3.141592 / 180);
}

void getVelocityVector(double theta, double absVelocity, double *velocityX, double *velocityY) {
	*velocityX = getVelocityX(theta, absVelocity);
	*velocityY = getVelocityY(theta, absVelocity);
}

double getDistanceTraveled(double velocityX, double velocityY) {
	return posX(velocityX, flightTime(velocityY));
}

double optimalAngleForMaxDistance(double absVelocity) {
	double best_distance = 0;
	double distance = 0;
	double theta = 0;
	
	double velocityX = 0;
	double velocityY = 0;
	
	double d_theta = 0.1;
	while (distance >= best_distance) {
		theta += d_theta;
		best_distance = distance;
		getVelocityVector(theta, absVelocity, &velocityX, &velocityY);
		distance = getDistanceTraveled(velocityX, velocityY);
	}
	
	return theta - d_theta;
}

double targetPractice(double distanceToTarget, double velocityX, double velocityY) {
	return getDistanceTraveled(velocityX, velocityY) - distanceToTarget;
}