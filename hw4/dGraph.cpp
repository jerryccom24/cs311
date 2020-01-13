// ====================================================
//HW#: HW4   dGraph
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
    }
  count = 0; //set initial count to zero

}
//does nothing
dGraph::~dGraph(){}

//Purpose: Display the contents of the Graph Table in a neat/clear/readable fashion
void dGraph::displayContents()
{
  cout<<endl;
  cout<<"--------------------------------------------------"<<endl;
  cout<<left<<setw(15)<<"VertexName"<<setw(15)<<"VertexDegree"<<setw(15)<<"Adjacents"<<endl;

  for(int i = 0; i < count; i++)//go through each used slot and output
    {
      cout<<setw(15)<<Table[i].vertexName; //output vertex name
      cout<<setw(15)<<Table[i].outDegree; //output vertex degree

      if((Table[i].adjacent).isEmpty())
	cout<<setw(15)<<"\t [No Adjacents]"<<endl; //NO adjacent list

      else
	(Table[i].adjacent).displayAll();//Displays Adjacent list

    }
  cout<<"--------------------------------------------------"<<endl;

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
