// ====================================================
//HW#: HW5   dGraph (Updated for homework 5)
//Your name: Jerry Compton
//Complier:  G++
//File type: dGraph implementation file
//=====================================================
#include<iostream>
#include "dGraph.h"
#include<fstream>
#include<iomanip>
using namespace std;

//Basic contructor: initilizes all names to BLANK
dGraph::dGraph()
{
  //For loop fills in each vertex name with 'blank'
  for(int i = 0; i < SIZE; i++)
    {
      Table[i].vertexName = ' ';
      Table[i].visit = 0; //initialize to zero (unvisited)
    }
  count = 0; //set initial count to zero

}
//does nothing
dGraph::~dGraph(){}

//Purpose: Display the contents of the Graph Table in a neat/clear/readable fashion
void dGraph::displayContents()
{
  cout<<endl;
  cout<<"------------------------------------------------------------------"<<endl;
  cout<<left<<setw(15)<<"VertexName"<<setw(15)<<"VertexDegree"<<setw(15)<<"Visit"<<setw(15)<<"Adjacents"<<endl;

  for(int i = 0; i < count; i++)//go through each used slot and output
    {
      cout<<setw(15)<<Table[i].vertexName; //output vertex name
      cout<<setw(15)<<Table[i].outDegree; //output vertex degree
      cout<<setw(15)<<Table[i].visit;     //output visited #

      if((Table[i].adjacent).isEmpty())
	cout<<setw(15)<<"\t [No Adjacents]"<<endl; //NO adjacent list

      else
	(Table[i].adjacent).displayAll();//Displays Adjacent list

    }
  cout<<"------------------------------------------------------------------"<<endl;

}

//Purpose: Read in the contents for the graph from a file
void dGraph::readContents()
{
  el_t x;//character that will be put into list of adjacents
  
  ifstream fin;
  fin.open("table.txt");//open table.txt

    //while reading a name
    while(fin>> Table[count].vertexName)//fin the vertex name
      {
	fin>> Table[count].outDegree;//fin the vertex out degree

	for(int i = 0; i < Table[count].outDegree; i++) //while 'i' is less that out degree...
	  {
	    fin>> x; //take in character
	    (Table[count].adjacent).addRear(x);//add to rear of slist of adjacent degrees
	  }

	count++;//increment count
      }
  fin.close();//close file
}

//Purpose: Returns the Out degree of a searched Vertex
int dGraph::findOutDegree(char find)
{
  //linear search for the Vertex Name
  for(int i = 0; i < count;i++)
    {
      if(Table[i].vertexName == find)
	return Table[i].outDegree;//returns out degree
    }

  return -1;//if not found returns zero

}

//Purpose: returns slist of adjacents 
slist dGraph::findAdjacent(char find)
{
  //linear search for vertex
  for(int i = 0; i < count; i++)
    {
      if(Table[i].vertexName == find)
	return Table[i].adjacent;//returns slist
    }
}

//Purpose: is passed a vertx name (char) and then adds the Number visited to the Gvertex
void dGraph::visit(int visitNum,char vertexName)
{
  int slot = vertexName - 65;//This will give us the number in array

  Table[slot].visit = visitNum;// set the visit number the the Given Vertex
}

//all this function does is check to see if it has been Visited
bool dGraph::isVisited(char vertexName)
{
  int slot = vertexName - 65; // x is now the slot in the array of the vertex Name
 
 //Return False if it is NOT visited
  if(Table[slot].visit == 0)
    return false;
  //Return True if it IS visited
  else 
    return true;
  
}
