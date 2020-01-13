
// =======================================================
// HW#: HW1P2 stack
// Your name: Jerry Compton
// Compiler:  g++ 
// File type: headher file 
//=======================================================
#ifndef vstack_H
#define vstack_H
#include<iostream>
#include <vector>

//----- Globally setting up the alias ----------------

typedef int el_t;      // the el_t type is ** for now
                      // el_t is unknown to the client
//-------------------------------------------------------
class stack
{ 
  // to be hidden from the client
 private: 
  vector<el_t> el;  // el is  a vector of el_t's
 public:
   // the rest will be exactly the same as HW1P1. Therefore
   // the client should not have to change at all.
  // prototypes to be used by the client
  // Note that no parameter variables are given

  // exception handling classes
  class Overflow{};
  class Underflow{};  // thrown when the stack underflows

  stack();   // constructor to create an object
  ~stack();  // destructor  to destroy an object
  // PURPOSE: if not full, enters an element at the top;
  //          otherwise throws an exception - Overflow
  // PARAMETER: pass the element to be pushed
  void push(el_t);
  // PURPOSE: if not empty, removes and gives back the top element;
  //          otherwise throws an exception - Underflow
  // PARAMETER: provide variable to receive the popped element (pass by ref)
  void pop(el_t&);
  // PURPOSE: if not empty, gives the top element without removing it;
  //          otherwise, throws an exception - Underflow
  // PARAMETER: ***
  void topElem(el_t&);
  // ** Must add good comments for each function - See Notes1B
  //PURPOSE: This will check to see if the stack is empty and return true if it is
  bool isEmpty();
  //PURPOSE: This will see if the stack is full and return true if it is
  bool isFull();
  //PURPOSE: This outputs the contents of the stack
  void displayAll();
  //PURPOSE: empties a stack. POPS everything.
  void clearIt();

};
#endif
