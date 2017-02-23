/*
 * File:        Deck.cpp
 * Author:      Norris, Joel R.
 * Course:      CSCI 3110
 * Instructor:  Zhijiang Dong
 * Date:        2017_02_16
 *
 * Purpose: This file is a part of the 3rd open lab assignment, which
 *	includes Player.h, Deck.h, Card.h,
 *	and ola3.cpp. 
 */

#include "Deck.h"
#include <iostream>
#include <algorithm>
#include <time.h>

Deck::Deck() {
	
	// create a new deck of cards
	// there's probably a cleaner, neater way to do this...
	// could iterate through the enum types for card suit...
	int i = 0;	
	for(int j = 1; j < 14; j++) {

		theDeck[i] = Card( j, clubs );
		i++;
	}
	for(int j = 1; j < 14; j++) {

		theDeck[i] = Card( j, hearts );
		i++;
	}
	for(int j = 1; j < 14; j++) {

		theDeck[i] = Card( j, spades );
		i++;
	}
	for(int j = 1; j < 14; j++) {

		theDeck[i] = Card( j, diamonds );
		i++;
	}

	topCard = 0;

}

// Shuffle the deck
void Deck::Shuffle() {

	// using stl's random_shuffle, passing in reference to the first and last elements in theDeck array
	std::srand(time(0));
	std::random_shuffle( &theDeck[0], &theDeck[Card_Num] );	
	//std::shuffle( &theDeck[0], &theDeck[Card_Num] );	

	topCard = 0;
}

// Remove the top card from the deck
// and return it.
Card Deck::dealCard() {
	
	if ( !this->isEmpty() ) {
		int i = topCard;
		++topCard;	
		return theDeck[i];
	} else {
		std::cout << "hey the deck is empty" << std::endl;
	}
}

bool Deck::isEmpty() {
	return topCard == Card_Num;
}	

// overload the << operator
ostream& operator << (ostream& os, const Deck& dk) {

	for (int i=0; i < dk.Card_Num; i++) {
	
		os << dk.theDeck[i] <<  '\t';
	}
	return os;
	
}
