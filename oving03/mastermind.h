#ifndef MASTERMIND_H
#define MASTERMIND_H

extern void playMasterMind();
extern int checkCharactersAndPosition(char *code, char *guess, int length);
extern int checkCharacters(char *code, char *guess, int length, int letters);

#endif