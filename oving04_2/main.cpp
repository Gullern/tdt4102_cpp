#include <iostream>
#include "main.h"
#include "card.h"

using namespace std;

int main() {
	CardStruct card_s;
	card_s.s = CLUBS;
	card_s.r = ACE;

	std::cout << toString(card_s) << std::endl;
	std::cout << toStringShort(card_s) << std::endl;

	Card card;
	card.initialize(SPADES, ACE);

	return 0;
}
