/*
 * File:        Card.h
 * Author:      Norris, Joel R.
 * Course:      CSCI 3110
 * Instructor:  Zhijiang Dong
 * Date:        2017_02_16
 *
 * Purpose: This file is a part of the 3rd open lab assignment, which
 *	includes Player.h, Deck.h, Card.h,
 *	and ola3.cpp. 
 */


#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <string>

using std::ostream;
using std::string;

enum suit {clubs, hearts, spades, diamonds};

class Card
{
public:
    //default constructor. It is required since another class
    //may declare an array of Card objects.
	Card();

    //another constructor
	Card (int faceValue, suit type);

    // overload the << operator
    friend ostream& operator << (ostream& os, const Card& cd);

    // compare the point value of cards *this and cd.
    // return true if *this has a smaller pointer value than cd.
    // otherwise, return false.
	bool operator < (const Card& cd) const;

    // compare the point value of cards *this and cd.
    // return true if *this has a larger point value than cd.
    // otherwise, return false.
	bool operator > (const Card& cd) const;

    // compare the point value of cards *this and cd
    // return true if they have the same point value,
    // otherwise return false.
	bool operator== (const Card& cd) const;

    // return the point value
	int getPointValue() const;
	int getFaceValue() const;

private:
	suit	type;       // the suit of the card
	int     faceValue;  // the face value of the card
	int     pointValue; // the point value of the card, it is a derived value
                        // from type and faceValue.
	char	typeChar;	// holds the Unicode char for the suit type
	string	faceStr;	// holds the Unicode char for the face type	
};
#endif