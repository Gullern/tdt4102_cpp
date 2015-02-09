#include <iostream>
#include <sstream>
#include <string>
#include "card.h"

using namespace std;

string suitToString(Suit suit) {
	switch(suit) {
	case CLUBS:
		return "Clubs";
	case DIAMONDS:
		return "Diamonds";
	case HEARTS:
		return "Hearts";
	case SPADES:
		return "Spades";
	}
}

string rankToString(Rank rank) {
	switch(rank) {
	case TWO:
		return "Two";
	case THREE:
		return "Three";
	case FOUR:
		return "Four";
	case FIVE:
		return "Five";
	case SIX:
		return "Six";
	case SEVEN:
		return "Seven";
	case EIGHT:
		return "Eight";
	case NINE:
		return "Nine";
	case TEN:
		return "Ten";
	case JACK:
		return "Jack";
	case QUEEN:
		return "Queen";
	case KING:
		return "King";
	case ACE:
		return "Ace";
	}
}

string toString(CardStruct card) {
	return rankToString(card.r) + " of " + suitToString(card.s);
}

string toStringShort(CardStruct card) {
	return suitToString(card.s).substr(0, 1) + intToString(card.r + 2);
}

string intToString(int number) {
	stringstream ss;
	ss << number;
	return ss.str();
}

Card::Card() {
	invalid = true;
}

Card::Card(Suit s, Rank r) {
	initialize(s, r);
}

void Card::initialize(Suit s, Rank r) {
	this->s = s;
	this->r = r;
	invalid = false;
}

Suit Card::getSuit() {
	return s;
}

Rank Card::getRank() {
	return r;
}

string Card::toString() {
	if (invalid) {
		return "Invalid card";
	}

	CardStruct card_s;
	card_s.s = s;
	card_s.r = r;

	return ::toString(card_s);
}

std::string Card::toStringShort() {
	if (invalid) {
		return "Invalid card";
	}

	CardStruct card_s;
	card_s.s = s;
	card_s.r = r;

	return ::toStringShort(card_s);
}
