#ifndef CARD_H
#define CARD_H

enum Suit {CLUBS, DIAMONDS, HEARTS, SPADES};
enum Rank {TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE};

struct CardStruct {
	Suit s;
	Rank r;
};

std::string suitToString(Suit suit);
std::string rankToString(Rank rank);
std::string toString(CardStruct card);
std::string toStringShort(CardStruct card);
std::string intToString(int number);

class Card {
	Suit s;
	Rank r;
	bool invalid;
public:
	Card();
	Card(Suit s, Rank r);
	void initialize(Suit s, Rank r);
	Suit getSuit();
	Rank getRank();
	std::string toString();
	std::string toStringShort();
};

#endif
