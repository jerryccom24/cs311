//INSTRUCTION
//Look for ** to complete this program 
//The string output should match my hw1queueDemo.out 
//except for the trace messages

//=========================================================
//HW#: HW1P1 queue
//Your name: Jerry Compton
//Complier:  G++
//File type: client program
//===========================================================
#ifndef client2_C
#define client2_C
using namespace std;

#include <iostream>
#include <stdlib.h>
#include <string>
#include "queue.h"

//Purpose of the program: The purpose of this program is to utilize a queue data
//structure in order to print all the strings of A B and C.

//Algorithm: The algorithm is just the process of removing an item, displaying
//the item. Then, adding 3 times to the back of the queue. It adds string + A, string + B
//and string + C. This algorithm continues until all the space in the queue is used. 
int main()
{ 
  queue myQueue;

  myQueue.add("A");     //ADD A B and C to the queue first
  myQueue.add("B");
  myQueue.add("C");
  
  while(!myQueue.isFull())//While the Queue is not full
    {
      el_t temp;//string that will be dequeued
      try
	{ 
	  myQueue.remove(temp); //remove
	  cout<<temp<<endl;     // display
	  myQueue.add(temp + "A");         //add STRING + A
	  myQueue.add(temp + "B");         //add STRING + B
	  myQueue.add(temp + "C");        //add STRING + C

	   }

      //CATCH Errors
      catch(queue::Overflow)
	{
	  cerr<<"No more room in Queue..."<<endl; return 0;
	}
      catch(queue::Underflow)
	{
	  cerr<<"Queue is Empty..." <<endl; return 0;
	}
    }
  
  return 0;
}

#endif
