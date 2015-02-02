//Triangle.h
//
#ifndef Triangle_h
#define Triangle_h

#include <string>
#include <iostream>

class Triangle
{
public:
   Triangle(int a, int b, int c)
   {
      if (isATriangle(a, b, c))
      {
         side1 = a;
         side2 = b;
         side3 = c;
      }
      else
      {
         throw "Side lengths do not define a triangle!";
      }
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

   bool isATriangle(int i, int j, int k)
   {
      if ((i + j) > k && (i + k) > j && (j + k) > i)
      {
         trueTriangle = true;
      }
      else
      {
         trueTriangle = false;
      }

      return trueTriangle;
   }

   bool isAEquilateral()
   {
      if (getSide(1) == getSide(2) && getSide(2) == getSide(3))
      {
         scalene = false;
         equilateral = true;
         isoscolese = false;
      }
      else
      {
         equilateral = false;
      }

      return equilateral;
   }
   bool isAScalene()
   {

      if (getSide(1) != getSide(2) && getSide(1) != getSide(3))
      {
         scalene = true;
         equilateral = false;
         isoscolese = false;
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
         isoscolese = true;
      }
      else
      {
         isoscolese = false;
      }

      return isoscolese;
   }
private:
   int side1;
   int side2;
   int side3;
   bool trueTriangle;
   bool equilateral;
   bool isoscolese;
   bool scalene;
}; //end class Triangle

#endif