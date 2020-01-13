//INSTRUCTION
//Look for ** to complete this program 
//The output should match my hw1stackDemo.out 

//=========================================================
//HW#: HW1P1 stack
//Your name: Jerry Compton
//Complier:  g++
//File type: client program
//===========================================================
#ifndef client1_C
#define client1_C
using namespace std;

#include <iostream>
#include <stdlib.h>
#include <string>
#include "vstack.h"

//Purpose of the program: This algorithm is used to evaluate postfix expressions using 
//a stack that is implemented with a vector.

//Algorithm: The algorithm simply adds opperands to the stack and when a
// operator is found 2 of the top operands are popped and used with the operator
// After the entire operation is complete it will either output an error or
// the final result will be the last element in the stack.
//In this specific case, the stack is now implemented using a Vector
int main()
{
  stack postfixstack;  // integer stack
  string expression;   // user entered expression
  
  cout << "type a postfix expression: " ;
  cin >> expression;
  
  int i = 0;  // character position within expression
  char item;  // one char out of the expression
  int result; //this will be the determined result of the expression
  
  int box1;  // receive things from pop
  int box2;  // receive things from pop

  //While the null terminator is not reached  
  while (expression[i] != '\0')
    {
      int numForm;//will be the integer translation of the character
      try
	{
	  item = expression[i];  // current char
	  if(item >= 48 && item <= 57)//if it is an Integer
	    {
	      numForm = (int)item - 48;//convert char number to integer number
	      postfixstack.push(numForm);//push it into stack
	    }
	  //2.  if it is an operand (number),^^^^^^^^^^^^^ 
	  //    push it (you might get Overflow exception)

	 
	  //3.  else if it is an operator,
	  //    pop the two operands (you might get Underflow exception), and
	  //	apply the operator to the two operands, and
	  //    push the result.
	  else if ( (item == '+') || (item == '-') || (item == '*'))
	    {
	      //pop 2 operands
	      postfixstack.pop(box1);
	      postfixstack.pop(box2);
	      //cases for different operators follow:
	      if (item == '-') result = box2-box1;
	      //also do the + and * cases
	      else if(item == '+') result = box2 + box1;

	      else if(item == '*') result = box2 * box1; 
	      //Finally push the result
	      postfixstack.push(result);
	    }
	  else throw "invalid item";//throw invalid item if it is not a valid item
	} // this closes try
      
      // Catch exceptions and report problems and quit the program now. 
      // Error messages describe what is wrong with the expression.
      catch(stack::Overflow) 
	{
	  cerr<<"Expression is too long..." << endl;return 0; 
	}
      catch(stack::Underflow) // for too few operands
	{
	  cerr<<"Expression has too few operands..." << endl; return 0;
	}
      catch (char const* error) // for invalid item
	{
	  cerr<< error << endl; return 0;
	}
      // go back to the loop after incrementing i
      i++;
    }// end of while

  //------------------------------------------------------------------------------  
  // After the loop successfully completes: 
  // The result will be at the top of the stack. Pop it and show it.
  try{

    postfixstack.pop(box1);     //Pull out the "result"
    
    //Throw OVERFLOW if the stack is still NOT empty
    if(!postfixstack.isEmpty())
      throw stack::Overflow();
    
   
    postfixstack.push(box1);     //if no error was found push the result back in
  }

  //There were still items in the stack
  catch(stack::Overflow)
    {
      cerr<<"Incomplete Expression"<<endl; return 0;
    }

  cout<<"\nThe Result is: ";
  postfixstack.displayAll();


  return 0;
}// end of the program


#endif
