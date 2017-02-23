/*
 * File:        Player.h
 * Author:      Norris, Joel R.
 * Course:      CSCI 3110
 * Instructor:  Zhijiang Dong
 * Date:        2017_02_16
 *
 * Purpose: This file is a part of the 3rd open lab assignment, which
 *	includes Player.h, Deck.h, Card.h,
 *	and ola3.cpp. 
 */


#ifndef PL_H
#define PL_H

#include <iostream>
#include <string>
#include "deck.h"
#include "card.h"

using std::ostream;
using std::string;

class Player
{
public:
    static const int Max_Cards = 3; //Max # of cards a player can have

    // constructor
	Player(string name="unknown");

    // The player removes one card from his hand
    // and return it.
    // You can use whatever strategy you want here such as
    // choose a card randomly, choose the largest card,
    // choose the first card, or other more complicated algorithm
	Card playCard();

    // The player gets one card from the deck
	void drawCard(Deck& dk);

    // Add the point value of the card
    // to the score of the player
	void addScore(Card acard);

	// accessor for the player's score. 
	int getScore() const;

    // Return the score the player has earned so far
	int total() const;

    // return the name of the player
    string getName() const; 

    // Return true if no more cards in the player's hands,
    // otherwise false
	bool emptyHand() const;
	
	// Print out the cards in the player's hand
	void printHand() const;

    // overload the << operator to display all cards in player's hand
    friend std::ostream& operator << (std::ostream&, const Player&);

private:
	string  name;				// player's name
	int     score;				// score the player has earned so far
	Card    hand[Max_Cards];    // the array holding cards 
	bool    played[Max_Cards];  // played[i] indicates if hand[i] has a card or not.
};

#endif
