//header goes here
// ====================================================
//HW#: HW3P3 slist
//Your name: Jerry Compton
//Complier:  G++
//File type: slist implementation file
//=====================================================
#include "slist.h"
#include<iostream>
using namespace std;

//UPDATED
//---------------------------------------
//Same default constructor as llist
slist::slist()
{
  Front = NULL;
  Rear = NULL;
  Count = 0;
}

//COPY CONSTRUCTOR
//Parameter is a slist that is to be copied into a new slist
slist::slist(const slist& Original)
{
  //initialize THIS data membets
  this->Front = NULL;
  this->Rear = NULL;
  this->Count = 0;

  Node* p;//this pointer will go through the list
  p = Original.Front;//set to front

  //until p = NULL
  while(p != NULL)
    {
      this->addRear(p->Elem); //insert into this's list
      p = p->Next; //increment pointer
    }
}

//OVERLOAD = operator
//This function takes the list that is to be copied into
//the list that is assigned. It adds to the THIS list
slist& slist::operator=(const slist& OtherOne)
{
  //compare pointers
  //if theyre not the same, then empty this and then refill with "OtherOne"
  if(&OtherOne != this)
    {
      el_t temp;//temporary variable to hold removed element

      while(!this->isEmpty())
	{
	  this->deleteRear(temp);
	}
      
      Node* p;//pointer to go through list
      p = OtherOne.Front;//set to front

      //go through list until NULL
      while(p != NULL)
	{
	  this->addRear(p->Elem); //add to THIS list
	  p = p->Next; //increment pointer
	}
    }

  return *this;//Return the result unconditionally
}

//OVERLOAD == operator
//This function allows the == to be used on a slist
//by checking all of the nodes and comparing to make sure
//they are the same. If they are identical, then true is returned
bool slist::operator==(const slist& OtherOne)
{

  //FIRST compare the count to see if it is the same
  //if they are not equal , then return false
  if(OtherOne.Count != this->Count)
    {
      return false;
    }

  //else...they are equal, so check the NODES
  else
    {
      Node* x = this->Front;//Pointer to the Front of THIS
      Node* y = OtherOne.Front;//Pointer to the Front of the OtherOne

      while(x != NULL)
	{
	  if(x->Elem != y->Elem)//If the elements are not the same
	    return false;

	  else
	    {
	      x = x->Next;//Increment Pointer
	      y = y->Next;//Increment Pointer
	    }
	}//end of while
      //if it has not returned false yet then the NODES were the same
      //so return true to indicate they are the same
      return true;
    }
}

//---------------------------------------
//Search through list for the key
//if it is not found return 0
//PARAMETER: it takes the Element
int slist::search(el_t Key)
{

  Node* ptr = Front; //Create node poiting to front of list
  int position = 1;//position that the Key is found in

  //while the ptr is not == to NULL check and increment if not found
  while( ptr != NULL) 
    {
      if(ptr->Elem == Key)//Key is found 
	return position;//return position

      else
	{
	  ptr = ptr->Next;//advance pointer 
	  position++;//increment position
	}
    }

  return 0; //Key was not found in any node
}

//---------------------------------------
/*
This function searches for the position of the element 
to be replaced. It makes sure that it is a valid location 
and then replaces the element of the NODE.
PARAMETERS: the NewElement and the POSTITION.
*/
void slist::replace(el_t newElem, int I)
{

  //checks if valid position
  if(I > Count || I < 1)
    throw OutOfRange();

  else
    {
      Node* ptr = Front; //pointer pointing to front


      //for loop increments pointer to the node that needs to be replaced...
      for(int i = 0; i < I-1; i++)
	{
	  ptr = ptr->Next;
	}
      //after this loop , ptr is pointing at the node in question...

      ptr->Elem = newElem; //assign new Element 
    }
}
