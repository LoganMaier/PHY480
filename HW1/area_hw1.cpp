//  file: area.cpp
//
//  This program calculates the area of a circle, given the radius.
//
//  Programmer:  Dick Furnstahl  furnstahl.1@osu.edu
//
//  Revision history:
//      02-Jan-2004  original version, for 780.20 Computational Physics
//      01-Jan-2010  updates to "To do" wishlist
//      12-Jan-2016  comment out "using namespace std;"
//
//  Notes:  
//   * compile with:  "g++ -o area.x area.cpp"
//
//  To do:
//   1. output the answer with higher precision (more digits)
//   2. use a "predefined" value of pi or generate it with atan
//   3. define an inline square function
//   4. split the calculation off into a function (subroutine)
//   5. output to a file (and/or input from a file)
//   6. add checks of the input (e.g., for non-positive radii)
//   7. rewrite using a Circle class
//
//*********************************************************************// 

// include files
#include <iostream> // this has the cout, cin definitions
#include <iomanip>
#include <cmath>
#include <fstream>
using namespace std;     // if omitted, then need std::cout, std::cin

//*********************************************************************//

const double pi_old = 3.1415926535897932385;    // define pi as a constant

                                                //M_PI is a predefined value for pi in the cmath library

inline double square(int radius){               //inline function to calculate the square
  return (radius * radius);
}

double area_function(double radius){            //split the calculation off into a seperate function (I think this is what it meant)
  return (M_PI * square(radius));
}


int
main ()
{
  double radius;                                // every variable is declared as int or double or ...

  cout << "Enter the radius of a circle: ";	// ask for radius
  cin >> radius;

  if (radius > 0){                              //checking for valid radii
  
  double area = area_function(radius);	        // standard area formula
  

  ofstream myfile;                              // Writing outpt to file
  myfile.open ("area.txt");
  myfile << "radius = " << setprecision(15) << radius << ",  area = " << area << endl;
  myfile.close();

  
  cout << "radius = " << setprecision(15) << radius << ",  area = " << area << endl;
  }

  if (radius <= 0){
    cout << "Invalid Radii Provided" << endl;
  }
  
  return 0;			                // "0" for successful completion
}

//*********************************************************************//
