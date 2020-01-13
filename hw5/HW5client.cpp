/*-------------------------------------------------------------------
Name:        Jerry Compton
Assignment:  HW5 graph Traversal
Compiler:    G++
File:        Main Client
---------------------------------------------------------------------
Purpose: The Purpose of the client is to do a depth first traversal
on a directed graph.

Algorithm: The algorithm is utilized within the do while loop. It is a 
matter of starting with the initial vertex on the graph, popping it, 
displaying it, pushing adjacents onto stack, then repeat, while incrementing 
the visit count so we can tell the order visited.
---------------------------------------------------------------------*/
#include<iostream>
#include "dGraph.h"
using namespace std;

int main()
{
  dGraph myGraph; //Our graph we will traverse
  slist mylist;   //A temporary list
  stack myStack;  //A stack used for holding Names of verticies
  el_t v;         //A temporary variable vertexName
  int vCount = 0; //This will keep track of the number of visits
  

  //First we need to read in contents
  cout<<endl;
  cout<<"-----Reading in Contents of Graph-----"<<endl;
  myGraph.readContents();

  //Second, we Need to Display the initial Graph
  cout<<endl;
  cout<<"-----Displaying Contents of Graph-----"<<endl;
  cout<<"-----     Before Traversal       -----";
  myGraph.displayContents();

  //-------------------------------------------------------------
  //Now the traversal process begins
  cout<<endl<<endl;
  cout<<"-----Now Doing Taversal-----"<<endl;
  myStack.push('A'); //push first vertexName on Stack


  //While the Stack is NOT empty we will do this algorithm
  do{
    
    myStack.pop(v); //remove vertex name from stack
    cout<<"Popped Vertex-Name: " << v << endl; //display name of vertex

    //IF AND ONLY IF V is not MARKED
    if(!myGraph.isVisited(v))
      {

	vCount++; //increment visited count (vCount)
	myGraph.visit(vCount, v);   //Visited and Marked
	cout<< v << " was visited..."<<endl; //inform that it was visited
	mylist = myGraph.findAdjacent(v);    //get list of adjacents

	//Pop the adjacents from List and push onto Stack
	while(!mylist.isEmpty())
	  {
	    mylist.deleteRear(v);//Deletes INTO v
	    myStack.push(v); //pushes V onto Stack
	  }

	//Show the Current Stack
	cout<<"Current Stack: "<<endl;
	myStack.displayAll();
	cout<<endl;
      }

  }while(!myStack.isEmpty());//END OF do while


  //Now Display New graph Table
  cout<<endl;
  cout<<"-----Graph After Traversal-----";
  myGraph.displayContents();

  //After the traversal New graph with visited count updated is now displayed

  return 0;
}
