//INSTRUCTION:
//Use the provided text to help create llist.cpp
//based on Yoshii  CS311  Notes-6A

//- Make sure PURPOSE and PARAMETER comments are given
//  DO NOT DELETE my descriptions but USE them.
//- Make sure all if-then-else are commented describing which case it is
//- Make sure all local variables are described fully with their purposes
// ====================================================
//HW#: HW3P1 llist
//Your name: Jerry Compton
//Complier:  G++
//File type: llist implementation file
//=====================================================
using namespace std;
#include<iostream>
#include"llist.h" 
/*****************************************************
Constructor
- initialize Front and Rear to be NULL and Count = 0.
- This does not create any node.  The new list is empty.
*****************************************************/  
llist::llist()
{
  Front = NULL;
  Rear = NULL;
  Count = 0;
}
//--------------------------------------------------------------------
//Destructor  
//- while the list is not empty, call deleteFront repeatedly to delete all nodes.
//- Please place a cout in this function "calling the llist desctructor."
llist::~llist()
{
  el_t value;

  while(!isEmpty())
    {
      deleteFront(value);  //deletes each node while the LIST is not empty
    }

}

//--------------------------------------------------------------------
//Check if Front == NULL and Rear == NULL and COunt == 0
//- (all 3 conditions must be checked)
//returns true if it is empty
bool llist::isEmpty()
{
  if(Count == 0 && Front == NULL && Rear == NULL)//Empty List
    return true;

  else//Not empty List
    return false;

}

//--------------------------------------------------------------------
//  - Special case: if the list is empty, display [ empty ] ).
//  - Regular: 
//    displays each element of the list horizontally starting from Front in [ ].
void llist::displayAll()
{
  //If it is Empty
  if(isEmpty())
    cout<<"[ Empty ]"<<endl;

  else
    {
      Node * P = Front;//Local Pointer to front
      while(P != NULL)//While P is poiting at Nodes
	{
	  cout<<"[ "<< P->Elem <<" ]"<<"   "; //Show Element
	  P = P->Next;//increment Pointer
	}
      cout<<endl;
    }


}

//--------------------------------------------------------------------
//2 cases:
//- Special case: if this is going to be the very first node, you must
//    create a new node and make Front and Rear point to it. Place NewNum and
//    Count is updated.
//  - Regular: adds a new node at the rear and puts NewNum in the Elem field
//    of this new node. Count is updated. 
void llist::addRear(el_t NewNum) 
{
  if ( Count == 0)//If the list is empty
    {
      Node * P = new Node;//Create new node
      P->Elem = NewNum; //set Element
      Front = P; //set P to front
      Rear = P; //set P to rear
      Rear -> Next = NULL; //set next to NULL
      Count++;//increment count
    }
  else
    {
      //Regular case:
      Rear->Next = new Node; //Create New Node as rears next
      Rear = Rear->Next; //new node is now the rear
      Rear->Elem = NewNum; //set element
      Rear->Next = NULL; //set rears next to NULL
      Count++; //increment count
    }
}  

//--------------------------------------------------------------------
//2 cases:
//- Special case: if this is going to be the very first node, you must
//   create a new node and make Front and Rear point to it. Place NewNum and
//   Count is updated.
//  - Regular: add a new node to the front of the list and
//    Count is updated.
void llist::addFront(el_t NewNum)
{
  //Special Case
  if(Count == 0)
    {
      //ADD TO THE FRONT
      Node * P = new Node; 
      P->Elem = NewNum;  
      Front = P;
      Rear = P;
      Rear->Next = NULL;
      Count++;
    }
  // Regular case:
  else
    {
      Node *x;
      x = new Node;
      x->Next = Front; //inserts before front
      Front = x; //set as front
      Front->Elem = NewNum;
      Count++;
    }
}

//--------------------------------------------------------------------
//3 cases:
//- Error case: if the List is empty, throw Underflow
//- Special case: if currently only one Node,give back the front node 
//    element through OldNum (pass by reference) and make sure both
//     Front and Rear become NULL. Count is updated.
//- Regular: give back the front node element through OldNum (pass by reference)
//    and also removes the front node.  Count is updated.
void llist::deleteFront(el_t& OldNum)
{
  //ERROR case
  if(isEmpty())
    {
      throw Underflow();//if its empty THROW underflow
    }
  //Special case
  //ONLY 1 element
  else if(Count == 1)
    {
      OldNum = Front -> Elem; //takes first Node's Element
      //cout<<"Element Removed: "<<OldNum<<endl;//display removed element
      delete Front;
      Front = NULL;//Set NULLS
      Rear = NULL;
      Count--;//decrement Count
    }
  //Regular case
  else
    {
      OldNum = Front->Elem;
      //cout<<"Element Removed: "<<OldNum<<endl;
      Node *Second;
      Second = Front->Next; //set second to front's next
      delete Front;
      Front = Second; //set front to second
      Count--; //decrement
    }
}

//--------------------------------------------------------------------
// 3 cases:
// - Error case: if empty, throw Underflow
// - Special case: if currently only one node,
//   give back the rear node element through OldNum (pass by reference) and
//   make sure both Front and Rear become NULL. Count is updated.
// - Regular: give back the rear node element through OldNum (pass by reference)
//   and also remove the rear node. Count is updated.
void llist::deleteRear(el_t& OldNum)
{ 
  if(isEmpty())
    {
      throw Underflow();//it it is empty throw UNDERFLOW
    }

  //IF there is only 1 Node, Delete front
  else if(Count == 1)
    {
      OldNum = Front -> Elem;
      //cout<<"Element Removed: "<<OldNum<<endl;
      delete Front;
      Front = NULL;
      Rear = NULL;
      Count--;
    }
  else//Regular Case(There are multiple NODES)
    {

      OldNum = Rear->Elem;//give rear element
      //cout<<"Element Removed: "<<OldNum<<endl;
      Node *p = Front;

      //Make p go to the NODE  before rear (using while)
      while(p->Next->Next != NULL)
	{
	  p = p->Next;
	}

      delete Rear;
      Rear = p; //set node before REAR to P
      Rear->Next = NULL; //set next to null
      Count--; //decrement Count
    }
}


//--------------------------------------------------------------------
//4 cases:
//- Error case: 
//  If I is an illegal value (i.e. > Count or < 1) throw OutOfRange.
//- Special cases: this should simply call deleteFront when I is 1 or 
//  deleteRear when I is Count
//- Regular: delete the Ith node (I starts out at 1).  Count is updated.
//<see the template loops in the notes to move 2 pointers to the right nodes;
//and make sure you indicate the purposes of these local pointers>

void llist::deleteIth(int I, el_t& OldNum)
{
  
  //IF OUT OF RANGE
  if(I > Count || I < 1)
    throw OutOfRange();
  
  //If I is the Front node, DELETE FRONT
  else if(I == 1)
    deleteFront(OldNum);
  //If I is the Rear node, DELETE REAR
  else if( I == Count) 
    deleteRear(OldNum);
  
  else
    {
      Node *p = Front;//This will go to the Ith node
      Node *t = Front;//This will go to the Node before the Ith node

      for(int j = 1; j <= I-2; j++)
	{
	  t = t->Next;//Increment t to Node behind Ith Node
	}

      p = t->Next;//Put this Pointer (p)  on the Node to be deleted

      OldNum = p->Elem; //Extract Element from node to be deleted
      cout<<"Element Removed: "<<OldNum<<endl;
      t->Next = p->Next;//connect bridge from t to p->next
      delete p;//Safe to delete p now
      Count--;//decrease count
    }
}


//--------------------------------------------------------------------
//4 cases:
//-  Error case:If I is an illegal value (i.e. > Count+1 or < 1) throw OutOfRange.
//-  Special cases: this should simply call addFront when I is 1 or addRear when
//   I is Count+1
//-  Regular: add right before the Ith node. Cout if updated.
//   <see the template loops in the notes to move 2 pointers to the right nodes
//   and make sure you indicate the purposes of these local pointers>
void llist::addbeforeIth(int I, el_t newNum)
{

  //Error Case which is Out of the Range
  if(I > Count+1 || I < 1)
    throw OutOfRange();

  //Special Case &add before front
  else if( I == 1)
    addFront(newNum);

  //add after Rear
  else if(I == Count +1)
    addRear(newNum);

  //Regular Case
  else
    {
      Node *newNodePointer = new Node; // New node that will be inserted
      Node *temp1= Front;//The will point to the Ith node
      Node *temp2 = Front;//This will Point to the Node before the Ith

      for( int i = 1; i < I-1; i++)
	{
	  temp2 = temp2->Next; //Increment to Node before Ith
	}
      temp1 = temp2->Next;//Assign temp1 to Ith Node

      temp2->Next = newNodePointer; //insert before Ith
      newNodePointer->Elem = newNum; //Add Element
      newNodePointer->Next = temp1; //Next Node is now the Ith Node
      Count++;//increment Count

    }

}
