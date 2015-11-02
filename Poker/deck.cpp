//#include "stdafx.h"
#include "deck.h"
#include <iostream>
#include <algorithm>

using namespace std;

Deck::Deck()
{
   Shuffle();
}

void Deck::Shuffle()
{
   cards.erase(cards.begin(), cards.end());
   for ( int i = Card::CLUBS; i <= Card::SPADES; i++ )
   {
      for ( int j = Card::TWO; j <= Card::ACE; j++ )
      {
         cards.push_back( Card(Card::SUITS(i),Card::COUNT(j)));       //The basic shuffle function shuffles the deck of cards
      }
   }
   random_shuffle ( cards.begin(), cards.end() );
}

void Deck::ShowDeck()
{

	vector<Card>::iterator it;
	for(it=cards.begin();it!=cards.end();it++)
	{

		cout<<it->str()<<" ";                               //Displays the deck of cards.
	}
   


}

std::vector<Card> Deck :: Deal( int count )
{
	vector <Card> dealtCards;
	for(int i=0;i<count;i++)
	{
	  Card ca = cards.front();
	  dealtCards.push_back(ca);                                 //Function to deal with the deck of cards
	  cards.erase(cards.begin());


	}
	return(dealtCards);
}
	
	/* Your code here */
