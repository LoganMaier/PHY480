#include <gsl/gsl_integration.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include "routines.h"

using namespace std;


double my_integrand (double x);
double gsl_integrand (double x, void *);


int main() {


    // set up the integration specifictions
    const int max_intervals = 10000;    // maximum number of intervals
    const double lower = 0.0;    // lower limit of integration
    const double upper = 1.0;    // upper limit of integration

    //const double answer = 32.4453;    // the "exact" answer for the test
    double result = 0.;  // approximate answer
    double answer = 2.489088475303216;


    //file output preparation
    ofstream int_out ("int.dat");
    int_out << "#  log10(N)   log10(Simpsons)     log10(Milne)      log10(GSL)  " << endl;
    int_out << "#################################################################" << endl;

    // Simpson's rule requires an odd number of intervals
    for (double i = 5; i <= max_intervals; i += 4) {
        int_out << setw(4) << log10(i);

        //simpsons
        result = simpsons_rule(i, lower, upper, &my_integrand);
        int_out << "  " << scientific << log10(fabs((result - answer) / answer));

        //milne
        result = milne_rule(i, lower, upper, &my_integrand);
        int_out << "  " << scientific << log10(fabs((result - answer) / answer));

        //GSL
        result = gsl_approach(lower, upper, &gsl_integrand);
        int_out << "  " << scientific << log10(fabs((result - answer) / answer));

        int_out << endl;

    }
    cout << "table of data can be found in int.dat" << endl;
    int_out.close ();
}
double my_integrand (double x)
{
    return (exp(cos(pow(x,2))));
}

double gsl_integrand(double x, void *)
{
    return exp(cos(pow(x,2)));
}

