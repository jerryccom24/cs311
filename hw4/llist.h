//INSTRUCTION:
//Llist class - header file template (by Yoshii) based on Notes-6A
//You must complete the ** parts and then complete llist.cpp
// Don't forget PURPOSE and PARAMETERS 
// =======================================================
// HW#: HW3P1 llist
// Your name: Jerry Compton
// Compiler:  g++ 
// File type: header file 
//=======================================================

//----- Globally setting up the alias and struct  ----------------
typedef char el_t ;  //set el_t to  integers

//a list node is defined here as a struct Node
// I could have done class Node and add the data members under public
// but it would use too much space
struct Node
{
  el_t Elem;   // elem is the element stored
  Node *Next;  // next is the pointer to the next node
};
//---------------------------------------------------------

class llist
{
  //THIS NEEDS TO BE PROTECTED so it can be inherited  
 protected:
  Node *Front;       // pointer to the front node
  Node *Rear;        // pointer to the rear node
  int  Count;        // counter for the number of nodes
  
 public:

  // Exception handling classes 
  class Underflow{};
  class OutOfRange{};  // thrown when the specified Node is out of range

  llist ();     // constructor to create a list object
  ~llist();     // destructor to destroy all nodes  
  //Checks to see if linked list is empty .
  bool isEmpty();

  //displays all elements of the linked list.
  void displayAll();

  //adds node to fron of linked list.
  //Parameter: takes an el_t element to insert in the list
  void addFront(el_t);
    
  //adds node to rear of linked list.
  //Parameter: takes an el_t element to insert in the list
  void addRear(el_t);

  //deletes first node.
  //Parameter: passes by reference the element that is deleted
  void deleteFront(el_t&);
    
  //deletes last node.
  //Parameter: passes by reference the element that is deleted
  void deleteRear(el_t&);
    
  //deletes node at the ith position.
  //Parameter: Takes an integer that is the number of the 
  //node that is to be deleted. and also the el_t passes by
  //reference the deleted element back
  void deleteIth(int, el_t&);

  //adds node before ith position. 
  //Parameter: takes int which is the number of the Node to be
  //inserted before.. and also recieves an el_t that will be the 
  //element inserted into the Node.
  void addbeforeIth(int, el_t);
    
};
