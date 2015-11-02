//#include "stdafx.h"`
#include "hand.h"
#include <iostream>

using namespace std;
/* Your code here */
void Hand::add(Card card)
{

	cards.push_back(card);    //add the card to the cards vector
	
}

void Hand::showHand()
{

	vector<Card>::iterator it;
	for(it=cards.begin();it!=cards.end();it++)
	{

		cout<<it->str()<<" ";     //Loop through the entire cards vector and display the suit as well as the value
	}
   
	
}

void Hand::check()
{
	bool four_of_a_kind  = false;            //flags as in the boolean types to store the existence of type of hands.
	bool three_of_a_kind = false;	      //Initially all of them are set to false	
	bool one_pair = false;
	bool two_pair = false;
	bool flush = false;

	vector <int> count_value(13,0);        //vector to count the value which is initialized to zero and since there are 13 different types of cards
	vector <int> count_suit(4,0);          //vector to count the number of suits 	

	int suit,value;

	vector<Card>::iterator it;           //An iterator of type Card

	for(it=cards.begin();it!=cards.end();it++)
	{

		suit = (*it).getSuit()-1;     //Loop through the cards' vector and get the corresponding suit as well as the value since they are the members
		value= (*it).getValue()-2;

		count_value[value]=count_value[value]+1;   //Increement the corresponding count's value
		count_suit[suit]=count_suit[suit]+1;	//Increement the corresponding suit's value

	}

	vector<int>::iterator it_value;                       //An iterator to loop through the count_value vector to keep the count

	for(it_value=count_value.begin();it_value!=count_value.end();it_value++)
	{
		if((*it_value == 4) ||(*it_value == 5))
		{
			four_of_a_kind=true;                     //set four of a kind as true
			break;
		}

		if((*it_value == 3)&&((*it_value!=4)||(*it_value!=5)))
		{
			three_of_a_kind = true;            // set three of a kind as true
			break;
		}

		if((*it_value == 2) &&(one_pair == false))
		{
			one_pair = true;			//set one pair as true
			*it_value = 0;
			continue;
		}

		if((*it_value == 2) &&(one_pair == true))
		{
			two_pair = true;			//set two pair as true
			break;
		}
	}

	vector<int>::iterator it_suit;   //an iterator pointing to the no of suits vector

	for(it_suit=count_suit.begin();it_suit!=count_suit.end();it_suit++)
	{
		if(*it_suit == 4)                         //Setting flush as true
			flush=true;
	} 

	if(four_of_a_kind == true)
	{
		cout<<"Four of a kind";
	}

	if((flush== true)&& (four_of_a_kind == false)) //Displays the following statements depending on the kind of the flag it is set to
       {
                cout<<"Flush";
       }

    if((three_of_a_kind== true)&&(four_of_a_kind == false)&&(flush == false))
       {
               cout<<"Three of a kind";
       }

    if((two_pair== true)&&(four_of_a_kind == false)&&(flush == false)&&(three_of_a_kind == false))
       {
               cout<<" Two pair ";
       }

    if((one_pair== true)&&(four_of_a_kind == false)&&(flush == false)&&(three_of_a_kind == false)&&(two_pair ==false))
       {
               cout<<" One pair ";
       }

}
