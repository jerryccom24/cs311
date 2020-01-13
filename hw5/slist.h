// =======================================================
// HW#: HW3P3 slist
// Your name: Jerry Compton
// Compiler:  g++
// File type: header file
//=======================================================
//UPDATED
#include "llist.h"

class slist : public llist //public access of llist
{
 private:

 public:
  slist();//same constructor as llist

  slist(const slist&);//copy constructor

  slist & operator=(const slist&);//will overload the assignment operator to make one list equal another

  bool operator==(const slist&);//overload the "==" to check if two lists are equal in comparison

  int search(el_t Key);//searches for an node's element WITH a Key

  void replace(el_t newElem, int I);//replaces the element of a NODE given a certain position.
  
};
