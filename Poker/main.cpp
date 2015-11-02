// main.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include "deck.h"
#include "hand.h"
#include <vector>
#include <iostream>
#include <stdlib.h>

using namespace std;

/*Shravya Narayan Sarma */
/*sxn8837*/

int main()
{
   
   vector<Hand> hands;	  //vector to store Hand objects
   vector<Card> temp_cards;   //Temporary cards vector
   Deck deck;
   int players; 
   int seed;
   int sizeOfHand = 5;

   cout << "Enter seed: ";
   cin >> seed;			//The seed required
   srand(unsigned(seed));

   cout << "Enter number of players: ";
   cin >> players; 

   deck.Shuffle();   //Shuffle a deck of cards.

   /* Your code here */
   /* Deal cards from the deck and do a round robin distribution to the
    * players.  Thus, if you had 5 players, and they each needed 5 cards you
    * would pull 5 cards off the deck and assign the first card to player one,
    * the second to player 2, etc.. Then you would deal 5 more and repeat the
    * process until 25 cards are dealt 
    */

   
      for(int i=0; i<players ; i++)
      {
         Hand h;				//Iterate through the number of players and create Hand objects and assign them to the vector.
         hands.push_back(h);
      }

       for(int i=0; i<sizeOfHand; i++)
      {
                                          //Loop through five times
         for(int i= 0; i< players; i++)
            { 
                temp_cards=deck.Deal(players);  //Loop through the number of players and deal with the players
                Hand h = hands[0];              //Assign the hand object with the first element of vector
                h.add(temp_cards[i]);           //add the corresponding temp cards vector to the hand object
                hands.erase(hands.begin());     //erase the first element
                hands.push_back(h);             //push the first element of the vector
             }
      }

       for(int i=0; i<players; i++)
       {
          cout<<"Player " << i+1 << " hand :" ;		//basic premise is loop through the number of players and invoke the showHand() to display the cards			
          (hands[i]).showHand();
          cout<<" ";
	   (hands[i]).check();				//Displays the type of the hand whether it is one/two pair or three/four of a kind /Flush
           cout<<endl;
       }

   	return 0;
}

