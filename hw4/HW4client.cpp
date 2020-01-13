/*-------------------------------------------------------------------------
Name:        Jerry Compton
Assignment:  HW4 directed graph
Compiler:    G++
File:        Main Client
--------------------------------------------------------------------------
Purpose: The purpose of this client is to utilize a directed graph class.
Each dGraph object has an array of Gvertex structs. The structs have a letter Name,
a Out degree, and a slist of adjacent vertecies. This will read in a file and then
output the contents of the graph. It will also search each individual Vertex.

Algorithm: The algorithm utilizes a directed graph. The graph is basically 
an array of vertecies. We also use a slist abstract data type to handle the 
list of adjacents. The contents are easily searched based on their vertex name.O(1)
--------------------------------------------------------------------------*/
#include<iostream>
#include "dGraph.h"
using namespace std;

int main()
{
  slist list;//This is a slist that will be used for searching for adjacents
  dGraph G;//This is the directed Graph that has an array of G vertecies

  //---------------------------------------------
  cout<<"***Read in Contents of Graph***"<<endl;
  G.readContents(); //reads in contents from file

  //---------------------------------------------
  cout<<"***Display Contents of Graph***"<<endl;
  G.displayContents(); //displays table



  //----------------------------------------------------------  
  //Now do the searching for each letter...
  //----------------------------------------------------------

  cout<<"\n***Doing Searches for each vertex***"<<endl;

  char vertexName = 'A'; //start at First Vertex Name  
  cout<<endl;
 
  //Do Individual Searches on each Gvertex 'A' - 'I' 
  //Find  all Out Degrees and Adjacents of each vertex and output 
  //use G.getCount so I am only seraching through the filled array slots
  for(int i = 0; i < G.getCount(); i++)
    {
      list = G.findAdjacent(vertexName); // gets list of adjacents fot each Letter

      //Output Labels
      //Do the individual searches on each vertex 
      cout<<"---------------------------\n";
      cout<<"Vertex Name : " << vertexName << endl;  // Letter of Vertex  
      cout<<"Out Degree  : " << G.findOutDegree(vertexName)<<endl; //Returns out degree of the letter searched
      cout<<"Adjacents   : "; list.displayAll(); //displays list of adjacents
      cout<<"---------------------------\n";
  
      vertexName++; // increment i.e A -> B -> C -> D
    }

  cout<<endl;
  return 0;
}
