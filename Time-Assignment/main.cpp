/**
 * main.cpp
 * For use with 4003-703-01, Homework 2
 * Winter 2012
 * Department of Computer Science
 * Rochester Institute of Technology
 * Author: Travis Brown
 */
#include "Time.h"
#include <iostream>
#include <string>
#include <vector>
#include <boost/algorithm/string.hpp>
#include <cstdlib>
using namespace boost;
using namespace std;

/* Your code here */
vector <Time>   TimeObjs;
vector <char>   Operators;
vector <string> TimeString;


int main()
{
   std::string str;
   
   
do
   {
      getline( cin, str ); //get the input string from standard input

      split(TimeString,str,is_any_of("+-")); //Split method as a part of the string library based on characters as the delimiters

      
               
      
      for(int i=0;i<str.length();i++)
      {

         if( str[i] == '+'  || str[i] == '-')
           { 
             
              Operators.push_back(str[i]);   //The subsequent operators are inserted into the stack
           } 

      } 
   
     for(int i=0;i<TimeString.size();i++)
      {
          string var=TimeString.at(i);      //Each of the time strings in the form of HH:MM are passed as parameters  
          Time t(var);
          TimeObjs.push_back(t);            //Each of the time objects are inserted into the vector 
      }
   
             
     while(!(Operators.empty()))
     {
      
        
        Time t1 = TimeObjs.front();         //Time Objects in the front as in the first element         
        TimeObjs.erase(TimeObjs.begin()+0); //Time Objects are deleted from the front
        Time t2 = TimeObjs.front();	  //Subsequent Time Objects are obtained	
        TimeObjs.erase(TimeObjs.begin()+0); //They are erased from the queue
        Time res;
        if(Operators.front() == '+')
        {
                                          
          res= t1.add(t2);                 //If the operator is a plus sign the two objects' seconds are added
           
           
        
        }  
        
       else if(Operators.front() == '-')       
        {

           res= t1.subtract(t2);        //If the operator is a plus sign the two objects' seconds are added 

        }
        
        TimeObjs.insert(TimeObjs.begin()+0, res); // The resultant Time object is inserted at the beginning of the vector



       Operators.erase(Operators.begin()+0);    //The Operator vector is checked and the subsequent operators are popped out 
        
        
      
     }
	Time t = TimeObjs.front();  //The resultant Time Object has seconds and is the only element in the vector 
       string total = t.str();     //The str method of the class is invoked and the Time is printed in the format HH:MM
	cout << total << endl;
                      
   } while ( !cin.eof() ); //Until the standard input hasn't reached the end of the file

}
