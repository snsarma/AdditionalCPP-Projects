#ifndef _CARD_H_
#define _CARD_H_

#include <string>
/**
 * Card class. This class represents a single playing card 
 */


class Card
{
public:
   /**
    * Suits of playing cards
    */
   typedef enum SUITS { CLUBS = 1 , DIAMONDS, HEARTS, SPADES } SUITES;

   /**
    * The value of the card: 2 through Ace
    */
   typedef enum COUNT { TWO = 2, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE } COUNT;

   /** 
    * Default constructor
    */
   Card();

   /**
    * Constructor to initialize our suit and value
    *
    * @param _suit enum of SUITS
    * @param _val  value of the card (COUNT enum)
    */

   Card( Card::SUITS _suit, Card::COUNT _val );


   /**
    * Get a string representation of the card.
    * @return string in the format similar to this: "10D", which would be 10
    * of diamonds
    */
   std::string str();

   /**
    * Accessor to get this card's suit
    * @return value of this card's suit
    */
   SUITS getSuit();
   
   /**
    * Accessor to get this card's value
    * @return value of this card
    */
   COUNT getValue();

   private:
   Card::SUITS suit;
   Card::COUNT value;

   std::string valToStr();
   std::string suitToStr();


/* Your code here */


};

#endif // _CARD_H_
