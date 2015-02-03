//Triangle.h
//
#ifndef Triangle_h
#define Triangle_h

#include <string>
#include <iostream>

class Triangle
{
public:
   Triangle(int a, int b, int c): side1(a), side2(b), side3(c)
   {
   }

   ~Triangle()
   {
   }

   int getSide(int index)
   {
      switch (index)
      {
      case 1:
         return side1;
      case 2:
         return side2;
      case 3:
         return side3;
      default:
         std::cout << "Index not in valid range (1, 2, 3)";
         return -1;
      }
   }
   
   static bool isATriangle(int i, //length 1
                           int j, //length 2
                           int k) //length 3
   {
      // the sum of any two sides must be greater than the 
      // remaining side (must be true for any triangle)
      if ((i + j) > k && (i + k) > j && (j + k) > i)
      {
         return true;
      }
      else
      {
         return false;
      }
   }

   bool isAEquilateral()
   {
      //check that all sides are equal
      if (getSide(1) == getSide(2) && getSide(2) == getSide(3))
      {
         scalene = false;
         equilateral = true;
         isoscelese = false;
      }
      else
      {
         equilateral = false;
      }

      return equilateral;
   }
   bool isAScalene()
   {
      //check to see that no sides are equal
      if (getSide(1) != getSide(2) && getSide(2) != getSide(3))
      {
         scalene = true;
         equilateral = false;
         isoscelese = false;
      }
      else
      {
         scalene = false;
      }

      return scalene;
   }

   bool isAIsoscolese()
   {
      bool side12 = false;
      bool side13 = false;
      bool side23 = false;

      //check to see that only two sides are equal
      if (getSide(1) == getSide(2) && getSide(2) != getSide(3))
      {
         side12 = true;
      }
      if (getSide(1) == getSide(3) && getSide(3) != getSide(2))
      {
         side13 = true;
      }
      if (getSide(2) == getSide(3) && getSide(3) != getSide(1))
      {
         side23 = true;
      }

      if ((side12 && !side13 && !side23) ||
         (!side12 && side13 && !side23) ||
         (!side12 && !side13 && side23))
      {
         scalene = false;
         equilateral = false;
         isoscelese = true;
      }
      else
      {
         isoscelese = false;
      }

      return isoscelese;
   }
private:
   int side1; //length of side 1 of triangle
   int side2; //length of side 2 of triangle
   int side3; //length of side 3 of triangle
   bool equilateral; //all side lengths are equal
   bool isoscelese; //only two side lenghts are equal
   bool scalene; //no side lengths are equal
}; //end class Triangle

#endif