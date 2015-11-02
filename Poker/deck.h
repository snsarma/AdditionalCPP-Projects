#ifndef _DECK_H_
#define _DECK_H_

#include "card.h"
#include <vector>

/**
 * This class represents a standard 52-card poker deck
 */
class Deck
{
public:
   /**
    * Default constructor. This will initialize and shuffle the deck
    */
   Deck();

   /**
    * Reinitilaize the deck and shuffle it.
    */
   void Shuffle();

   /**
    * Dump out the contents of the current deck, minus already dealt cards
    */
   void ShowDeck();
  
   /**
    * Return a vector of cards that are dealt. 
    * @param count number of cards to deal
    * @return a set of cards from the front of the deck
    */
   std::vector<Card> Deal( int count );
    

private:
   std::vector<Card> cards;

/* Your code here */

};

#endif //_DECK_H_
