//INSTRUCTION
//Look for ** to complete all of them
//The output should match my assingment sheet
//DO not forget to Tab on each line
//=========================================================
//HW#: HW3P2 slist
//Your name: Jerry Compton
//Complier:  g++
//File type: client program (tester)
//===========================================================

using namespace std;

#include <iostream>
#include "slist.h"

//PURPOSE of the program: to utilize inheritance between classes
//using the members from the llist class and use them in the 
//searchable linked list class
//------------------------------------------------------------
//ALGORITHM:
//The slist class has inherited from the llist class.
//So, now we can continue with our actions on the llist with
//the use of the slist class. Performing search and replace functions
//on the slist object as well as the previous llist class.
//

int main()
{ 
  slist L;  // the list 
  int foundPos; // to hold the found position 
  int counter = 1; // used to display test line number
  try
    {
      //  1)add to front once (element 4)
      cout << counter << endl; counter++;
      L.addFront(4);
      
      //  2)add to rear 3 times (elements 6,7,8)
      cout << counter << endl; counter++;
      L.addRear(6);
      L.addRear(7);
      L.addRear(8);
      
      //  3)displayAll    - 4 6 7 8
      cout << counter << endl; counter++;
      L.displayAll();
      cout<<endl;
      
      //  4)search for 6, report the result  - found in pos 2
      cout << counter << endl; counter++;
      foundPos = L.search(6);
      
      //CHECK IF POSITION IS FOUND
      if(foundPos >= 1)
	cout<<"Found at position: " << foundPos << endl;
      
      else
	cout<<"Not found"<<endl;
      
      //  5)replace the 6 with 0 using the search result
      cout << counter << endl; counter++;
      L.replace(0,foundPos);
      
      //  6)search for 8 and report the result . found in pos 4
      cout << counter << endl; counter++;
      foundPos = L.search(8);
      
      //CHECK IF POSITION IS FOUND
      if(foundPos >= 1)
	cout<<"Found at position: " << foundPos<<endl;
      
      else
	cout<<"Not Found" <<endl;
      
      //  7)replace the 8 with 2 using the search result
      cout << counter << endl; counter++;
      L.replace(2,foundPos);
      
      //  8)displayAll                       - 4 0 7 2
      cout << counter << endl; counter++;
      L.displayAll();
      
      //  9)search for 5 and report the result   - not found
      cout << counter << endl; counter++;
      foundPos = L.search(5);
      
      //CHECK IF POSITION IS FOUND
      if(foundPos >= 1)
	cout<<"Found at position: " << foundPos<<endl;
      
      else
	cout<<"Not Found" <<endl;
      
      // 10) replace postion 7 with 10
      cout << counter << endl; counter++;
      L.replace(7,10);
      
    }//end of try
  catch(slist::OutOfRange)
    { cerr << "ERROR: Bad position was given" << endl;}
  
}//end of program
