/**
 * Time.cpp
 * For use with 4003-703-01, Homework 2
 * Winter 2012
 * Department of Computer Science
 * Rochester Institute of Technology
 * Author: Travis Brown
 */
#include <stdlib.h>
#include <vector>
#include <boost/algorithm/string.hpp>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include "Time.h"

using namespace boost;
using namespace std;


class Time
{

public : 
          
Time( void )
{
   seconds = 0;
}

Time( int _seconds )
{
  seconds = _seconds;  //It takes seconds as the input
}

Time( std::string t )
{
   
   setTime( t );    //Constructor is invoked from main with string as the parameter and setTime() is invoked
}

Time add( Time t )
{
   return seconds += t.seconds;       // While popping elements from the vector when a plus sign is encountered add() is invoked
}

Time subtract( Time t )
{
   return seconds -= t.seconds;      // While popping elements from the vector when a plus sign is encountered subtract() is invoked
}

string str() 
{
   /* Use ostringstream to convert from int to string. This will be covered in
    * detail in week 8
    */
   ostringstream oss;
   oss << seconds / 3600 << ":" << setfill('0') << setw(2) << ( seconds % 3600 ) / 60;
   return oss.str();                                                                  //This is invoked when the seconds are sent are converted as strings and displayed

}

void setTime( std::string t )
{

      
     vector <string> temp;
     for(int i=0;i<t.length();i++)
     {

         if( t[0] == ':' )
          {						//This is the case handled for inputs where in hours aren't mentioned
     
            t ="00"+t;             
          }

     }

     split(temp,t,is_any_of(":"));               // With : as the delimiter the input is seperated as hours and minutes

      
  
    int size=temp.size();
    const char *temp1;
    string var;                               
    vector <int> numbers (size);      // vector of the digits where in the strings are converted into digits
    
    for(int i=0; i<numbers.size(); i++)
    {
             
	var=temp.at(i);     
       temp1=var.c_str();             //Here is where the basic conversion of the strings into the numbers
       numbers.at(i)=atoi(temp1);
        
    } 
    
    
   for (int i=0;i<numbers.size();i++)
     {  
        
        
        int num1=numbers.at(0);
        int num2=numbers.at(1);
       
        seconds=(num1*3600+num2*60);     //Here is where the first part of the number and the second part of the number are taken as hours and minutes and the total seconds conversion
                                         //  is computed.

          
       
         
    }

 
}

private : int seconds;
};
