//=========================================================
//HW#: HW2P1 recursive Binary Search
//Your name: Jerry Compton
//Complier:  g++
//File type: main program
//===========================================================
#include<iostream>
#include<cmath>
using namespace std;
/*************************************************************
Purpose: The purpose of this program is to search an array
using a recursive binary search. We are finding the location 
of an element.

Algorithm: This Algorithm is a recursive binary search function.
it calculates the rounded down median index and checks if the 
number is greater or less than. It will ultimately either
find the number or the FIRST index will surpass the LAST index 
and return -1.
**************************************************************/

//Prototype
int binarySearch(int L[], int x, int first, int last);

int main()
{
  int n = 10;//Array Size
  int myFirst = 0;//First Index
  int myLast = n-1;//Last Index

  int findNum;//This is the number a user wants to find
  int indexFound;//This is the index that we find the number at
  int ar[]={1,3,5,7,9,11,13,15,17,19};//fill an integer array with 10 slots

  //Promt User
  cout<<"Enter a number to look for: ";
  cin>>findNum;

  indexFound = binarySearch(ar,findNum,myFirst,myLast);//find the location

  //OUTPUT
  if(indexFound == -1)
    cout<<"Number was not found..."<<endl<<endl;
  else
    cout<<"Number found at position  "<< indexFound+1 <<endl<<endl;  

  return 0;
}

//-------------------------------------------------------------------
//This Binary Search Function will recieve the array, the Number that 
//is being searched for, the index of the first element and last element.
//Then it will recursively call itself as it narrows its search.
int binarySearch(int L[], int x, int first, int last) 
{
  int middle;//middle of the scope of elements being analyzed
  middle = floor(first + last)/2; //finds rounded down median index

  if(first > last)//Element could not be found
    return -1;

  else if(x == L[middle])//number is the middle element
    return middle;

  else if(x < L[middle])//less that middle
    last = middle - 1;//set new last

  else if(x > L[middle])//greater than middle
    first = middle + 1;//set new first

  return binarySearch(L,x,first,last);//recursive call
}
