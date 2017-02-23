/*
 * File:        ola3.cpp
 * Author:      Norris, Joel R.
 * Course:      CSCI 3110
 * Instructor:  Zhijiang Dong
 * Date:        2017_02_16
 *
 * Purpose: This file is a part of the 3rd open lab assignment, which
 *	includes Player.h, Deck.h, Card.h, and ola3.cpp. 
 *	learn to work with multiple classes. 
 *	review operator overloading.
 *	review friends.
 */

#include <iostream>
#include "Player.h"
#include "Deck.h"
#include "Card.h"

using std::cout;
using std::endl;

int main()
{

	//std::cout << ((char)0x03); //print Heart symbol  
	//std::cout << ((char)0x04); //print Diamond symbol  
	//std::cout << ((char)0x05); //print Club symbol  
	//std::cout << ((char)0x06); //print Spade symbol
	//std::cout << std::endl;

	int hand = 1;	// track which hand is being played

	Player player1 = Player("William");
	Player player2 = Player("Computer");

	// generate the deck
	Deck deck = Deck();
	cout << "The original deck has the following cards" << endl;
	cout << deck << endl;
	deck.Shuffle();
	cout << "After shuffle, the deck has the following cards" << endl;
	cout << deck << endl;

	// Player1 Draw 3 Cards
	player1.drawCard(deck);
	player1.drawCard(deck);
	player1.drawCard(deck);

	// Player2 Draw 3 Cards
	player2.drawCard(deck);
	player2.drawCard(deck);
	player2.drawCard(deck);

	// As long as the players have cards, keep playing
	while ( !player1.emptyHand() && !player2.emptyHand() ) {
		
		cout << endl;
		cout << "************* Hand " << hand << " *************" << endl;

		player1.printHand();	// print player1's hand
		player2.printHand();	// print Player2's hand
		cout << endl;

		Card player1card = player1.playCard();	// Player1 play card
		Card player2card = player2.playCard();	// Player2 play card

		cout << player1.getName() << " played card: " << player1card 
			<< " --- " <<
			player2.getName() << " played card: " << player2card << endl << endl;

		// compare cards
		// assign points to the winner
		// check if it's a draw
		if ( player1card.getFaceValue() > player2card.getFaceValue() ) {
			// TODO : hey wait, do they get the score of BOTH cards? or just the highest?
			player1.addScore(player1card);
			player1.addScore(player2card);
			cout << player1.getName() << " takes this hand" << endl;
		} else if ( player1card.getFaceValue() < player2card.getFaceValue() ) {
			player2.addScore(player1card);
			player2.addScore(player2card);
			cout << player2.getName() << " takes this hand" << endl;
		} else if ( player1card.getFaceValue() == player2card.getFaceValue() ) {
			// nobody wins! ergo everyone wins!
			cout << "the cards are the same" << endl;
		}
		cout << endl;

		player2.printHand();	// print Player2's hand
		player1.printHand();	// print player1's hand

		player1.drawCard(deck);	// Player 1 draw card
		player2.drawCard(deck);	// Player 2 draw card

		++hand;		// what hand is it?

	}

	// output winner's score.
	cout << endl;
	if ( player1.getScore() > player2.getScore() ) {
		cout << player1.getName() << " WINS with a score of: " << player1.getScore() << endl;
	} else if ( player1.getScore() < player2.getScore() ) {
		cout << player2.getName() << " WINS with a score of: " << player2.getScore() << endl;
	} else {
		// in the unlikely event of a tie.
		// actually, now that I think of it, I'm not sure this is even possible, point-wise.
		cout << "huh. it's a tie?" << endl;
		cout << player1.getName() << "'s score: " << player1.getScore() << endl;
		cout << player2.getName() << "'s score: " << player2.getScore() << endl;
	}

	return 0;
}

