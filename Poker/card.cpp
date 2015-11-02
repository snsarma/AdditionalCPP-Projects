//#include "stdafx.h"
#include "card.h"
#include <sstream>

using namespace std;

Card::Card()
{
	
}



Card::Card( Card::SUITS _suit, Card::COUNT _val )
{
    suit  =_suit;
	value =_val;

}

std::string Card::str()
{
   ostringstream os;
   os << valToStr() << suitToStr();//Convert the value to string and the suit to string
   return os.str();
}

/* Your code here */
Card::SUITS Card::getSuit()
{

	return(this->suit);    //returns the current suit

}

Card::COUNT Card::getValue()
{

	return(this->value); //returns the count or the card's actual value

}
std::string Card::valToStr()
{
	Card::COUNT value = getValue();   //get the corresponding value of the card
       string str;
	if(value == 2)
       str="2";                         //If the value of the card is 2 return the string 2 and so forth until 14
	else if(value == 3)
       str="3";
	else if(value == 4)
       str="3";
	else if(value == 5)
       str="5";
	else if(value == 6)
       str="6";
	else if(value == 7)
       str="7";
	else if(value == 8)
       str="8";
	else if(value == 9)
       str="9";
	else if(value == 10)
       str="10";
	else if(value == 11)
       str="J";
	else if(value == 12)
       str="Q";
	else if(value == 13)
       str="K";
	else if(value == 14)
       str="A";

	return(str);
}

std::string Card::suitToStr()
{

	Card::SUITES suit = getSuit();
	string card;
	if(suit == 1)
       card = "C";			//Depending on the value of the suit assign Clubs/Diamonds/Hearts/Spades as C...S
	else if(suit == 2)
       card = "D";
       else if(suit == 3)
       card = "H";
	else if(suit == 4)
       card = "S";

	return(card);

}