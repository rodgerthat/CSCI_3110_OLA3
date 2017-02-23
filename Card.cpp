/*
 * File:        Card.cpp
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
#include "Card.h"
#include <string>

using std::string;

// default constructor, specify a card w no parameters, you get an unplayable card
Card::Card() : faceValue(0), type(spades) {}

Card::Card( int faceValue, suit type ) {

	this->faceValue = faceValue;
	this->type = type;

	// Assign Unicode char to suit type
	// 0x03 //print Heart symbol  
	// 0x04 //print Diamond symbol  
	// 0x05 //print Club symbol  
	// 0x06 //print Spade

	switch(type) {
		case hearts :
			typeChar = 0x03;
			break;
		case diamonds :
			typeChar = 0x04;
			break;
		case clubs :
			typeChar = 0x05;
			break;
		case spades :
			typeChar = 0x06;
	}

	// determine and set point value of card. 
	// A ( 1 ) = 15
	// J Q K ( 11, 12, 13 ) = 10 points
	// All others equal the faceValue int of the card

	switch(faceValue) {
		case 1:
			pointValue = 15;
			faceStr = 'A';
			break;
		case 11 :
			faceStr = 'J';
			pointValue = 10;
			break;
		case 12 :
			faceStr = 'Q';
			pointValue = 10;
			break;
		case 13 : 
			faceStr = 'K';
			pointValue = 10;
			break;
		default :
			pointValue = faceValue;
			faceStr = std::to_string(faceValue);
	}
}

// Accessor for pointValue
int Card::getPointValue() const {
	return this->pointValue;
}

int Card::getFaceValue() const {
	return this->faceValue;
}

// compare the point value of cards *this and cd.
// return true if *this has a smaller pointer value than cd.
// otherwise, return false.
bool Card::operator < (const Card& cd) const {
	return faceValue < cd.faceValue;
}


// compare the point value of cards *this and cd.
// return true if *this has a larger point value than cd.
// otherwise, return false.
bool Card::operator > (const Card& cd) const {
	return faceValue > cd.faceValue;
}

// compare the point value of cards *this and cd
// return true if they have the same point value,
// otherwise return false.
bool Card::operator== (const Card& cd) const {
	return faceValue == cd.faceValue;
}

// overload the << operator
ostream& operator << (ostream& os, const Card& cd) {
	os << cd.faceStr << cd.typeChar << '[' << cd.pointValue << ']';
	return os;
}

