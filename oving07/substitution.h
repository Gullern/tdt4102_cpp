#ifndef SUBSTITUTION_H
#define SUBSTITUTION_H

#include <map>
#include <string>

class Substitution {
public:
	Substitution(char filename[]);
	void play();
private:
	static const int maxWords = 5;
	std::map<char, char> cipher;
	std::map<char, char> decodeCipher;
	std::map<char, char> guessCipher;
	std::string plainText;
	std::string cipherText;
	std::string rawText;

	char encodeChar(char a, std::map<char, char> &map) const;
	std::string encodeString(std::string plainText, std::map<char, char> &map) const;
	int countSpaces(std::string input) const;
	int checkForErrors(std::string input) const;
	std::string cleanString(std::string input) const;
	void generateCipher();
	void selectRandomText();
	void askUser();
	int printErrors(std::string userPlaintext) const;
	void printUserInformation(std::string userPlaintext) const;
	std::string parseDecryptedText(std::string userPlaintext) const;
};

#endif
