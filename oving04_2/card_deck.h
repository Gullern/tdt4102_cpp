#ifndef CARD_DECK_H
#define CARD_DECK_H

class CardDeck {
	static const int SIZE = 52;
	static bool seeded;
	Card cards[SIZE];
	int currentCardIndex;
	void swap(int index1, int index2);
public:
	CardDeck();
	void print();
	void printShort();
	void shuffle();
};

#endif
