// ====================================================
//HW#: HW5   dGraph (Updated for Homework 5)
//Your name: Jerry Compton
//Complier:  G++
//File type: dGraph Header file
//=====================================================
#include<iostream>
#include<string>
#include "slist.h"
#include "stack.h"

using namespace std;

const int SIZE = 20; //Global const array size

//Each Vertex in the graph is a struct
struct Gvertex
{
  char vertexName; //Letter of the Vertex
  int outDegree; //Number of vertecies it points to
  slist adjacent; // a searchable linked list of the adjacent verticies
  int visit;// will be the number in sequence of visited vertecies
};
  

class dGraph : public slist, public stack
{
 private:
  Gvertex Table[SIZE]; // Array of Gvertexs
  int count; //number of Gvertexes used in array of Gvertexs
  
 public:

  dGraph();//constructor
  ~dGraph();//destructor ALSO! all of the slist destructors are still called within the client
  void displayContents();
  void readContents();//this will read in the contents of a graph from a file
  int findOutDegree(char); // searches for the out degree of a vertex Name
  slist findAdjacent(char); // finds the adjacent of a vertex Name
  int getCount(){return count;} //return number of Gvertexes... For use in main
  //-------------------------------------------------------------------------
  //additional funtions for Homework 5
  void visit(int,char);//adds a number visited to a given vertex
  bool isVisited(char);//function will return true if it has been visited OR false if Not visited

};
