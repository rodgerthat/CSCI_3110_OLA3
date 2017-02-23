/*
 * File:        Player.cpp	
 * Author:      Norris, Joel R.
 * Course:      CSCI 3110
 * Instructor:  Zhijiang Dong
 * Date:        2017_02_16
 *
 * Purpose: This file is a part of the 3rd open lab assignment, which
 *	includes Player.h, Deck.h, Card.h,
 *	and ola3.cpp. 
 */

#include <iostream>
#include "Player.h"

using std::cout;
using std::endl;

// still having issues initializing member arrays in initialize list...
// played{false}
Player::Player(string name) :name("unknown"), score(0), played() {
	this->name = name;
	this->played[0] = true;
	this->played[1] = true;
	this->played[2] = true;
}

// The player removes one card from his hand
// and return it.
// You can use whatever strategy you want here such as
// choose a card randomly, choose the largest card,
// choose the first card, or other more complicated algorithm
Card Player::playCard() {
	
	// search through hand, return card w/ highest pointValue
	// check through played array to verify card is actually 'there'
	int highest = 0;
	for (int i=0; i < Max_Cards; i++) {
		if ( hand[i].getFaceValue() > highest && played[i] == false ) {
			highest = i;
		}
	}
	played[highest] = true;		// update the played array, no more card here, 
	return hand[highest];		// return the card

}

// The player gets one card from the deck
void Player::drawCard(Deck& dk) {
	// check played hand, see where there's an empty spot
	// should probably check to see if the hand is full, 
	// although this method should never be called unless a card has already been played

	// so, as long as the deck is NOT empty...
	// draw a card and place it in the first empty spot
	if ( !dk.isEmpty() ) {
		int i;
		for ( i = 0; i < Max_Cards; i++ ) {

			if ( played[i] == true) {
				this->played[i] = false;
				this->hand[i] = dk.dealCard();
				break;
			}
		}
		// add the drawn card to the player's hand
		// in the empty spot
	} 

}

// Add the point value of the card
// to the score of the player
void Player::addScore(Card acard) {
	this->score += acard.getPointValue();
}

// Accessor for the player's score
int Player::getScore() const {
	return this->score;
}

// Return the score the player has earned so far
int Player::total() const {
	return this->score;
}

// return the name of the player
string Player::getName() const {
	return this->name;
}

// Return true if no more cards in the player's hands,
// otherwise false
bool Player::emptyHand() const {
	
	for (int i=0; i < Max_Cards; i++ ) {

		if (played[i] == false ) {
			return false;
		}
	}
	return true;
}

// print out the cards in the player's hand. 
// don't forget to check if there's not a card in that slot, 
void Player::printHand() const {
	
	cout << name << "\'s hand: ";

	for (int i=0; i < Max_Cards; i++ ) {

		if ( played[i] == true ) { cout << "_____ "; }
		else { cout << hand[i] << " "; }
	}

	cout << " with score: " << score << endl;

}


// overload the << operator to display all cards in player's hand
std::ostream& operator << (std::ostream& os, const Player& pl) {
	for (int i=0; i < pl.Max_Cards; i++) {
		os << pl.hand[i] << ' '; 
	}
	return os;
}
