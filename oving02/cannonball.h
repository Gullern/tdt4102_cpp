#ifndef _OPPG1_H
#define _OPPG1_H

//Del 1
extern double acclX();
extern double acclY();
extern double velX(double startVelY, double time);
extern double velY(double startVelY, double time);
extern double velIntX(double startVelY, double time);
extern double velIntY(double startVelY, double time);
extern double posX(double starVelX, double time);
extern double posY(double starVelY, double time);
extern double posIntX(double starVelX, double time);
extern double posIntY(double starVelY, double time);
extern void printTime(double time);
extern double flightTime(double startVelY);

//Del 2
extern void getUserInput(double *theta, double *absVelocity);
extern double getVelocityX(double theta, double absVelocity);
extern double getVelocityY(double theta, double absVelocity);
extern void getVelocityVector(double theta, double absVelocity, double *velocityX, double *velocityY);
extern double getDistanceTraveled(double velocityX, double velocityY);
extern double optimalAngleForMaxDistance(double absVelocity);
extern double targetPractice(double distanceToTarget, double velocityX, double velocityY);

#endif