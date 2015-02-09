#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "card.h"
#include "card_deck.h"

using namespace std;

bool CardDeck::seeded = false;

CardDeck::CardDeck() {
	for (int s = 0; s < 4; s++) {
		for (int r = 0; r < 13; r++) {
			cards[s * 13 + r] = Card((Suit)s, (Rank)r);
		}
	}

	if (!seeded) {
		srand(time(0));
		seeded = true;
	}

	currentCardIndex = 0;
}

void CardDeck::swap(int index1, int index2) {
	::swap(cards[index1], cards[index2]);
}

void CardDeck::print() {
	for (Card *c = cards; c < cards + SIZE; c++) {
		cout << c->toString() << endl;
	}
}

void CardDeck::printShort() {
	for (Card *c = cards; c < cards + SIZE; c++) {
		cout << c->toStringShort() << endl;
	}
}

void CardDeck::shuffle() {
	for (int i = 0; i < 10000; i++) {

	}
}
