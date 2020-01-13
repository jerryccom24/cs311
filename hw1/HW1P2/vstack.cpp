//INSTRUCTION
//Look for **. (do control-S)
//Update the comments using the HOW TO COMMENT file, 
//  complete exception handling and 
//  finish ClearIt to make this complete - Yoshii (CS311)
// When done, compile stack.cpp to make sure there are no syntax errors.
  
//=========================================================
//HW#: HW1P2 vstack
//Your name: Jerry Compton
//Complier:  g++
//File type: stack implementation file
//=========================================================

using namespace std;  
#include <iostream>
#include "vstack.h"

//PURPOSE:  None
stack::stack()
{
}
  
//PURPOSE: calls the clearIt function and Clears the vector
stack::~stack()
{
  clearIt();
}
  
//PURPOSE:  checks if vector size is 0 and returns true if so
bool stack::isEmpty()
{ 
  //if vector has a size equal to zero, then it is empty
  if (el.size() == 0) 
    return true; 
  
  else 
    return false; 
}

//PURPOSE: returns empty because vector cannot be full
//** In the comment, make sure you define "full" in terms of top.
bool stack::isFull()
{ 
  return false;
}
  
//PURPOSE: pushes an element to the top of the stack // or append to the rear of vecotr
//PARAMETER: pass the element (elem) to be pushed 
void stack::push(el_t elem)
{ 
  el.push_back(elem);
}
 
 //PURPOSE: calls isEmpty and if true, throws an exception (Underflow)
 //  Otherwise, removes an element from el and gives it back.
 //PARAMETER: provide a holder (elem) for the element popped (pass by ref)
void stack::pop(el_t& elem)
{ 
  if (isEmpty())
    {
      throw stack::Underflow();
    }
  else 
    { 
      elem = el[el.size()-1];
      el.pop_back();
    }
}
 
// PURPOSE: calls isEmpty and if true, throws an exception (underflow)
//    Otherwise, gives back the top element from el.
//PARAMETER: provide a holder (elem) for the element (pass by ref)
void stack::topElem(el_t& elem)
{ 
  if (isEmpty())
    {
      throw stack::Underflow();
    }
  else 
    { 
      elem = el[el.size()-1];
    } 
}
 
//PURPOSE: dislayAll calls isEmpty and if true, displays [ empty ].
//          Otherwise, diplays the elements vertically.
void stack::displayAll()
{  
  if (isEmpty()) 
    cout << "[ empty ]" << endl;
   
  else 
    {
      for (int i= el.size()-1; i>=0; i--)
	{ 
	  cout << el[i] << endl; 
	}
      cout << "--------------" << endl;
    }
}
 
//PURPOSE: pops all elements from the stack to make it empty if it is not empty yet.
void stack::clearIt()
{
  //while it is not empty, POP all the items
  while(!isEmpty())
    {
      el.pop_back();
    }
}


