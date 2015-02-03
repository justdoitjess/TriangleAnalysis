//********************************************************************
// TriangleAnalysis
// main.cpp
// Author: Jessica Hatch
// Date: February 2, 2015
// Class: 605.404 O-O Programming in C++
// Purpose: This program categorizes triangles based on side lengths.
// Input: (from standard input) 3 integers--side one, two, and three
// Output: (to console) The category of triangle--equilateral, 
//         isosceles, scalene, or not a triangle
//********************************************************************
#include "Triangle.h"

#include <ctype.h> //For toupper()
#include <iostream>
using namespace std;

int main(void)
{
   //define lengths and response condition
   char response;

   //loop over how ever many triangles the user wants to input
   do
   {
      //get input
      int lengthA = 0;
      int lengthB = 0;
      int lengthC = 0;
	   string temp;

      bool validTri = false;
      cout << "\n\nThis program will evaluate three integers that make up"
         << " a triangle.\n**Any decimal values or extraneous input will be truncated**\n" 
		   << "Enter the first side length: ";
      //remove any unread characters that were truncated
	   cin.sync();
      
      //only accept numeric values
      while (!(cin >> lengthA))
      { 
         cout << "Bad value!" << "Try again.\n";
		   cin.clear();
         cin.ignore(numeric_limits<streamsize>::max(), '\n');
      }

	  //remove any unread characters that were truncated
	  cin.sync();
     
     cout << "\nEnter the second side length: ";
      
     //only accept numeric values
     while (!(cin >> lengthB))
     {
        cout << "Bad value!" << "Try again.\n";
		  cin.clear();
		  cin.ignore(numeric_limits<streamsize>::max(), '\n');
     }

	  //remove any unread characters that were truncated
	  cin.sync();
     cout << "\nEnter the third side length: ";
     
     //only accept numeric values
     while (!(cin >> lengthC))
     {
        cout << "Bad value!" << "Try again.\n";
		  cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
     }
	  //remove any unread characters that were truncated
	  cin.sync();
	  
     //test to see if lengths define a triangle
	  validTri = Triangle::isATriangle(lengthA, lengthB, lengthC);
	  
	  //construct the triangle--calls isATriangle
	  if (validTri)
	  {
        Triangle test(lengthA, lengthB, lengthC);
		  cout << "Triangle created with side lengths: "
           << lengthA << ", " << lengthB << ", " << lengthC
			  << "\n\n";

        //figure out what type and print output to console
        if (test.isAEquilateral())
        {
           cout << "Those sides form an equilateral triangle\n\n";
        }

        if (test.isAIsoscolese())
        {
           cout << "Those sides form an isoscelese triangle\n\n";
        }

        if (test.isAScalene())
        {
           cout << "Those sides form a scalene triangle\n\n";
        }
     } //end if(validTri)
	  else
	  {
        cout << "\n\nSides: " 
           << lengthA
			  << ", "
			  << lengthB
			  << ", "
			  << lengthC
			  << "--Those lengths do not define a triangle. Start Over.\n\n\n"
			  << endl;
     }

     cout << endl;
     cout << "Do you wish to enter another set of"
        << " side lengths? (Y or N): ";
     cin >> response;
   } while (toupper(response) == 'Y'); //end do while loop
   
   cout << "\nEnd Program.";
   return 0;
} // end main()


//********************************************************************
//Sample Output of Running Program
//This program will evaluate three integers that make up a triangle.
//**Any decimal values or extraneous input will be truncated**
//Enter the first side length: 8
//
//Enter the second side length: 4
//
//Enter the third side length: 11
//Triangle created with side lengths: 8, 4, 11
//
//Those sides form a scalene triangle
//
//
//Do you wish to enter another set of side lengths? (Y or N): y
//
//
//This program will evaluate three integers that make up a triangle.
//**Any decimal values or extraneous input will be truncated**
//Enter the first side length: 24
//
//Enter the second side length: 24
//
//Enter the third side length: 10
//Triangle created with side lengths: 24, 24, 10
//
//Those sides form an isoscelese triangle
//
//
//Do you wish to enter another set of side lengths? (Y or N): y
//
//
//This program will evaluate three integers that make up a triangle.
//**Any decimal values or extraneous input will be truncated**
//Enter the first side length: 3
//
//Enter the second side length: 3
//
//Enter the third side length: 3
//Triangle created with side lengths: 3, 3, 3
//
//Those sides form an equilateral triangle
//
//
//Do you wish to enter another set of side lengths? (Y or N): y
//
//
//This program will evaluate three integers that make up a triangle.
//**Any decimal values or extraneous input will be truncated**
//Enter the first side length: a
//Bad value!Try again.
//2
//
//Enter the second side length: a5d
//Bad value!Try again.
//7
//
//Enter the third side length: 7.1
//Triangle created with side lengths: 2, 7, 7
//
//Those sides form an isoscelese triangle
//
//
//Do you wish to enter another set of side lengths? (Y or N): y
//
//
//This program will evaluate three integers that make up a triangle.
//**Any decimal values or extraneous input will be truncated**
//Enter the first side length: 27
//
//Enter the second side length: 1
//
//Enter the third side length: 2
//
//
//Sides: 27, 1, 2--Those lengths do not define a triangle. Start Over.
//
//
//
//
//Do you wish to enter another set of side lengths? (Y or N): y
//
//
//This program will evaluate three integers that make up a triangle.
//**Any decimal values or extraneous input will be truncated**
//Enter the first side length: -5
//
//Enter the second side length: 0
//
//Enter the third side length: 7
//
//
//Sides: -5, 0, 7--Those lengths do not define a triangle. Start Over.
//
//
//
//
//Do you wish to enter another set of side lengths? (Y or N): y
//
//
//This program will evaluate three integers that make up a triangle.
//**Any decimal values or extraneous input will be truncated**
//Enter the first side length: 4ww5
//
//Enter the second side length: 3
//
//Enter the third side length: 5
//Triangle created with side lengths: 4, 3, 5
//
//Those sides form a scalene triangle
//
//
//Do you wish to enter another set of side lengths? (Y or N): n
//
//End Program.
//********************************************************************/