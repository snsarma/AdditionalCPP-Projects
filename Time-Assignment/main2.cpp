/**
 * main.cpp
 * For use with 4003-703-01, Homework 2
 * Winter 2012
 * Department of Computer Science
 * Rochester Institute of Technology
 * Author: Travis Brown
 */

#include <iostream>
#include <string>
#include <vector>
#include <boost/algorithm/string.hpp>
#include <cstdlib>
#include <sstream>
#include <iomanip>
#include <stdlib.h>
using namespace boost;
using namespace std;

/* Your code here */

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
