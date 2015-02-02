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
   int lengthA = 0;
   int lengthB = 0;
   int lengthC = 0;
   char response;

   //loop over how ever many triangles the user wants to input
   do
   {
      //get input
      cout << "This program will evaluate three integers that make up"
         << "a triangle.\n Enter the first side length: ";

      while (!(cin >> lengthA))
      {
         cout << "Bad value!" << "Try again.";
         cin.clear();
         cin.ignore(numeric_limits<streamsize>::max(), '\n');
      }

      cout << "\nEnter the second side length: ";
      while (!(cin >> lengthB))
      {
         cout << "Bad value!" << "Try again.";
         cin.clear();
         cin.ignore(numeric_limits<streamsize>::max(), '\n');
      }

      cout << "\nEnter the third side length: ";
      while (!(cin >> lengthC))
      {
         cout << "Bad value!" << "Try again.";
         cin.clear();
         cin.ignore(numeric_limits<streamsize>::max(), '\n');
      }

      //construct the triangle--calls isATriangle, catch exception
      try
      {
         Triangle test(lengthA, lengthB, lengthC);

         //figure out what type and print output to console
         if (test.isAEquilateral())
         {
            cout << "Those sides form an equilateral triangle\n";
         }

         if (test.isAIsoscolese())
         {
            cout << "Those sides form an isoscolese triangle\n";
         }

         if (test.isAScalene())
         {
            cout << "Those sides form a scalene triangle";
         }
      }
      catch (string err_code)
      {
         cout << "ERROR CODE: " << err_code;
      }

      cout << "Do you wish to enter another set of"
         << "side lengths? (Y or N)";
      cin >> response;
   } while (toupper(response) == 'Y');

   cout << "\nEnd Program. Press any key to exit.\n";
   getchar();
   return 0;
} // end main()