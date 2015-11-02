#include<iostream>
using namespace std;

/*

  Shravya Narayan Sarma
  sxn8837


*/
/*Program to compare or verify whether all the elements in List 1 are present in List 2*/
int main()
{

 /*Initialize the variables with respect to the sizes of the lists and a counter to keep track of counter */
  int n1,n2,i,j,counter=0;
  bool flag;/*A boolean variable flag to check if all the elements are present*/
  

  cout<<"List 1 size:";    /*Enter the size of first list*/
  cin>>n1;
   
   int a1[n1];            /*Initialize the size of first list*/


  cout<<"List 1 data:";  /*Enter the elements  of First list*/
  for(i=0;i<n1;i++)
   cin>>a1[i];

  cout<<"List 2 size:";  /*Enter the size of second List*/
  cin>>n2;

  int a2[n2];            /*Initialize the size of second List*/

  cout<<"List 2 data:";  /*Enter the elements of the second List*/
   for(i=0;i<n2;i++)
    cin>>a2[i];
 
  for(i=0;i<n1;i++)
  {
   flag=false;		/*Loop through both the Lists and verify if each element of the First List is present in the second one*/	
    for(j=0;j<n2;j++)
    {
      if(a1[i] == a2[j])
      {
        counter++;
	flag=true;         /*Compare the elements in both the lists and increement the counter if it is present in both of them and set the flag */
     
      }
    }
  }  

  if((counter == n1)&&(flag=true)) /*Check the counter value and verify the flag value*/
   cout<<"TRUE"<<endl;
  else				/*Display True or False based on that*/
   cout<<"FALSE"<<endl;

}
