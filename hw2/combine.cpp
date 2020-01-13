//=========================================================
//HW#: HW2P2 Sorting__ Merge Sort's Combine
//Your name: Jerry Compton
//Complier:  g++
//File type: main program
//===========================================================
#include<iostream>
#include<vector>
using namespace std;
/*************************************************************
Purpose: The purpose of this Program is to simulate the combine
part of the merge sort. 

Algorithm: This is a direct comparison algorithm.  
**************************************************************/
//Prototype
void combine(vector<int> A, vector<int> B, vector<int>& R);

int main()
{
  int size;//number of elements user wants to enter
  vector<int> L1,L2,L3; //Declare 3 vectors to be 
  int temp;// temporary variable to hold integers entered by the user

  //Prompt User for the number of elements to be added to the vector
  cout<<"How many numbers do you want to enter? : ";
  cin>> size;
  
  //User inputs L1
  //Use for loop to retrieve the correct amount of Numbers
  cout<<"\nTyoe integers in increasing order into L1:\n ";
  for(int i = 0; i < size; i++)
    {
      cin>>temp;
      L1.push_back(temp);//add number to L1
    }

  //User inputs L2
  //Use for loop to retrieve the correct amount of Numbers
  cout<<"\nType integers in increasing order into L2:\n ";
  for(int i = 0; i < size; i++)
    {
      cin>>temp;
      L2.push_back(temp);//add number to L2
    }

  combine(L1,L2,L3);//Call "Combine" Function
  
  //L3 is returned by Reference
  //OUTPUT THE CONTENTS OF L3
  cout<<"\nContents of L3 are: ";
  for(int i = 0; i < L3.size(); i++)
    {
      cout<<L3[i]<< "  ";
    }

  cout<< endl<<endl;

  return 0;
}
/************************************************************
Function Header:This Function takes two vectors A and B that
were loaded with sorted elements and combines them into 
vector 'R' which is returned by reference.
 ***********************************************************/
void combine(vector<int> A, vector<int> B, vector<int>& R)
{
  int ia = 0;//vector A start index
  int ib = 0;//vector B start index

  // Runs until vector A or B runs out of elements
  while(ia < A.size() && ib < B.size())
    {
      if( A[ia] < B[ib])//compares index ia to index ib
	{
	  R.push_back(A[ia]); //pushes back smaller 
	  ia++; //increments index
	}

      else//Vector B was smaller
	{
	  R.push_back(B[ib]);  //pushback element in index in ib
	  ib++; //increment index
	}
      cout<<"\nComparison ";
    }

  //------------------End Of While --------------------------------
  //Now, If there is any remaider in either 'A' or 'B' it will be pushed back on 'R'
  if( ia != A.size())
    {
      while( ia != A.size())//index 'ia' has not reached maxSize
	{
	  R.push_back(A[ia]);//pushback remainder
	  ia++; //increment
	}
    }
  else
    {
      while(ib != B.size())//index 'ib' has not reached maxSize
	{
	  R.push_back(B[ib]);//pushback remainder
	  ib++; //increment
	}
    }

}
