//INSTRUCTION
//Look for ** to complete all of them based on my preceding comments
//The output should match my assingment sheet

//=========================================================
//HW#: HW3P3 slist
//Your name: Jerry Compton
//Complier:  g++
//File type: client program (tester)
//===========================================================

//Purpose:The Purpose of HW3P3 is to expand further on the slist class 
//that has inhereted from the llist class. I have added the operator
//overload for the == , and = operators. To allow for lists to be compared
//and assigned. Also the copy constructor is implemented to allow for a deep
//copy to be made.

//Algorithm:The algorithm simply performs by doing actions on a slist.
//By creating copies, comparing, and assigning to new slists.

using namespace std;
#include <iostream>
#include "slist.h"

//PURPOSE: This function simply tests the copy constructor of the slist class
//and adds 6 to a the rear of copiedList and displays the list
//PARAMETER: list passed by value becomes copiedList
void CopyTest(slist copiedList)
{
  cout << "in copy test" << endl;
  copiedList.addRear(6);
  copiedList.displayAll();
  cout << "finished" << endl;
}

//Function Performs 2nd TEST
void part2test()
{ 
  //1. L1 is empty and L2 is empty 
  cout<<"Part: 1"<<endl;
    slist L1, L2;
    if (L1 == L2) cout << "true" << endl; else cout << "false" << endl;

  //2. L1 is empty nd L2 with 4, 5
    cout<<"Part: 2"<<endl; 
    L2.addRear(4); L2.addRear(5);
    if (L1 == L2) cout << "true" << endl; else cout << "false" << endl;
  //3.  The opposite
    cout<<"Part: 3"<<endl;
    if (L2 == L1) cout << "true" << endl; else cout << "false" << endl;

  //4. L1 with 1,2,3 and L2 with  1,2,3
    cout<<"Part: 4"<<endl;
    L1.addRear(1); L1.addRear(2); L1.addRear(3);
    int x;
    L2.deleteFront(x);
    L2.deleteFront(x);
    L2.addRear(1); L2.addRear(2); L2.addRear(3);
    if (L1 == L2) cout << "true" << endl; else cout << "false" << endl;

  //5. L1 with 1,2,3 and L2 with  1,2
    cout<<"Part: 5"<<endl;
    L2.deleteRear(x);
    if (L1 == L2) cout << "true" << endl; else cout << "false" << endl;

    //6. L1 has 1,2,3 and L2 has 1,2,3,4
    cout<<"Part: 6"<<endl;
    L2.addRear(4);
    if (L1 == L2) cout << "true" << endl; else cout << "false" << endl;

    //7. L1 has 1,2,3 and L2 has 1,2,4
    cout<<"Part: 7"<<endl;
    L2.deleteRear(x);
    L2.deleteRear(x);
    L2.addRear(4);
    if (L1 == L2) cout << "true" << endl; else cout << "false" << endl;

 }//end of program


//PURPOSE of the Program: **
//Algorithm/Design: **
int main()
{
  slist L1, L2;
  int temp;
  int counter = 1;

  //1.Create a 5 element list with  1,2,3,4,5 (L1)
  cout << "Step" << counter << endl; counter++;
  L1.addRear(1);
  L1.addRear(2);
  L1.addRear(3);
  L1.addRear(4);
  L1.addRear(5);
  
  //2.Pass the list to a client function called CopyTest to 
  //test your copy constructor.
  cout << "Step" << counter << endl; counter++;
  CopyTest(L1);

  cout << "-- After copytest --- " << endl;
 
  //3.Display L1 (this should still be a 5 element list)
  cout << counter << endl; counter++;
  L1.displayAll();
 
  cout << "-- Testing operator overloading ---" << endl;

  //4.Do L1 = L1;
  cout << "Step " << counter << endl; counter++;
  L1 = L1;

  //5.Display L1    (this should still be 1 2 3 4 5)
  cout << "Step " << counter << endl; counter++;
  L1.displayAll();

  //6.Create a 4 element list L2 with 7,8,9,10.
  cout << "Step " << counter << endl; counter++;
  L2.addRear(7);
  L2.addRear(8);
  L2.addRear(9);
  L2.addRear(10);

  //7.Display L2
  cout << "Step " << counter << endl; counter++;
  L2.displayAll();

  //8.Do L2 = L1;  (L2 becomes 5 elements 1,2,3,4,5)
  cout << "Step " << counter << endl; counter++;
  L2 = L1;

  //9.Display L2.
  cout << "Step " << counter << endl; counter++;
  L2.displayAll();

  //10.Remove a rear node from L1. (This should not affect L2).
  cout << "Step " << counter << endl; counter++;
  L1.deleteRear(temp);

  //11.Display L1.   (L1 is 1,2,3,4)
  cout << "Step " << counter << endl; counter++;
  L1.displayAll();

  //12.Display L1 again. (4 elements . just to make sure)
  cout << "Step " << counter << endl; counter++;
  L1.displayAll();

  //13.Display L2 again. (still 5 elements 1,2,3,4,5)
  cout << "Step " << counter << endl; counter++;
  L2.displayAll();

    cout << "---- First Part testing done ----- " << endl;

  part2test();  // for testing ==

  return 0;
}// end of program


