//  file: gsl_spline_test_class_H.cpp
// 
//  Test program for the gsl spline routines using the Spline class
//
//  Programmer:  Dick Furnstahl  furnstahl.1@osu.edu
//
//  Revision history:
//      02/10/09 -- created from gsl_cubic_spline_test.cpp
//
//  Notes:
//   * uses the GSL interpolation functions (see online documentation) 
//
//*****************************************************************
// include files
#include <iostream>    // cout and cin
#include <iomanip>     // manipulators like setprecision
#include <cmath>
#include <fstream>
#include <string>     // C++ strings                                 
using namespace std;    
#include "GslSpline.h"  // Header file for the GSL Spline class
#include <gsl/gsl_integration.h>


inline double sqr (double z) {return z*z;}  // inline function for z^2
double my_integrand (double x, void *params);

int
main (void)
{
  const int NMAX = 3000;   // maximum number of array points 
  double x_values[NMAX], y_values[NMAX];

  int npts;
  double min_bound = 0.;
  double max_bound = 5.;
  double delta_x = 0.0;
  
  gsl_integration_workspace *work_ptr
    = gsl_integration_workspace_alloc (1000);

  double result;
  double error_for_integrand;
  double alpha = 1.0;           // parameter in integrand
  
  gsl_function My_function;
  void *params_ptr = &alpha;                                                                                            
  
  My_function.function = &my_integrand;
  My_function.params = params_ptr;
  
  gsl_integration_qags (&My_function, min_bound, max_bound,
                        1.0e-8, 1.0e-8, 1000, work_ptr, &result,
                        &error_for_integrand);

  
  for (npts = 10; npts <= NMAX; npts++)
  {
    delta_x = (max_bound - min_bound) / double(npts - 1);
  
  
  for (int i = 0; i < npts; i++)
  {
    double x_temp = min_bound + double(i) * delta_x;
    x_values[i] = x_temp;
    y_values[i] = 2. * x_temp * exp(-x_temp);  
        
  }

  // Make the spline object (only cubic)
  Spline my_cubic_spline (x_values, y_values, npts, "cubic");


  double absolute_error = 0.0;
  
  // for integral
  
  double integral;
  double relative_error;
  
  if (npts < 50) {
  integral = my_cubic_spline.integrate(min_bound, max_bound);
  relative_error = fabs((integral-result)/result);
  }
  
  for(double x = 1.; x <= 4.; x += 0.001)
  {
  
  double cubic_der = my_cubic_spline.yp (x);
  double error = fabs(cubic_der + 2. * exp(-x) * (x-1.));
  
  if (error > absolute_error) {
  
    absolute_error = error;
  }
  }

  if (relative_error > .0001){ 
  cout << npts << " delta_x:" << delta_x << "  absolute_error:" << absolute_error << "  relative_error:" << relative_error << endl;
 
  }
  
  if (absolute_error < 1e-6){
    break;
   } 
   
  if (relative_error <= .0001){ 
    
    cout << npts << " delta_x:" << delta_x << "  absolute_error:" << absolute_error << endl;
    
    }

   
  } 
  
    
  
       

  return (0);      // successful completion 
}



double my_integrand (double x, void *params)
{
  double alpha = *(double *) params;

  return alpha * 2. * x * exp(-x);
}
