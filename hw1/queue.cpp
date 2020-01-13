//INSTRUCTION
//Look for **
//Fill in the function body
//When done, compile queue.cpp to make sure it has no syntax errors

//=========================================================
//HW#: HW1P1 queue
//Your name: Jerry Compton
//Complier:  g++
//File type: Implementation file for the class, Queue
//===========================================================

using namespace std;
#include <iostream>
#include<string>
#include "queue.h"  

// constructor 
queue::queue()
{
  count = 0;
  front = 0;
  rear = -1;
}

//destructor 
queue::~queue()
{
}

// PURPOSE: returns true if queue is empty, otherwise false
bool queue::isEmpty()
{
  if(count == 0)
    return true;

  else
    return false;
}

// PURPOSE: returns true if queue is full, otherwise false
bool queue::isFull()
{

  if(count >= MAX_SIZE)
    return true;

  else 
    return false;
}

// PURPOSE: if full, throws an exception Overflow
// if not full, enters an element at the rear 
// PAREMETER: provide the element (newElem) to be added
void queue::add(el_t newElem)
{
  //if it is full throw OVERFLOW
 
  if(isFull())
    throw queue::Overflow();
 
  else
    {
      rear = (rear+1)% MAX_SIZE;//set new rear
      el[rear] = newElem;//assign to rear of queue
      count++; //increment count
    }

}

// PURPOSE: if empty, throw Underflow
// if not empty, removes the front element to give it back 
// PARAMETER: provide a holder (removedElem) for the element removed (pass by ref)
void queue::remove(el_t& removedElem)
{
  //throw underflow if empty
  if(isEmpty())
    throw queue::Underflow();
  
  else//dequeue front element
    {
      removedElem = el[front];//pass by reference removed element
      front = (front+1) % MAX_SIZE;//set new front
      count--;//decrement count
    }
      
}

// PURPOSE: if empty, throws an exception Underflow
// if not empty, give back the front element (but does not remove it)
//PARAMETER: provide a holder (theElem) for the element (pass by ref)
void queue::frontElem(el_t& theElem)
{
  //if empty throw underflow
  if(isEmpty())
    throw queue::Underflow();

  else
    {
      theElem = el[front];
    }
}

// PURPOSE: returns the current size to make it 
// accessible to the client caller
int queue::getSize()
{
  return count;
}

// PURPOSE: display everything in the queue horizontally from front to rear
// enclosed in []
// if empty, displays [ empty ]
void queue::displayAll()
{

  if(isEmpty())     //empty
    {
      cout<<"\n [ Empty ] "<<endl;
    }
  else     //Not empty and use for loop to display contents
    {
      for(int i = front; i <= rear; i++)
	{
	  cout<<el[i]<<endl;
	}
      cout<<endl; 
    }
}

// PURPOSE: if empty, throws an exception Underflow
//if queue has just 1 element, does nothing
//if queue has more than 1 element, moves the front one to the rear by
//doing remove followed by add.
void queue::goToBack()
{
// ** comment a local variable
  string temp;

  if(isEmpty())
    throw queue::Underflow();

  else if(count == 1)
    return;

  else
    {
      remove(temp);
      add(temp);
    }
}





