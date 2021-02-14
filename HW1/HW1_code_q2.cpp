/* 
Graph Analysis:

In the beginning of the graph we see no difference between the Up and Down sums, so there is noe slope indicating a diffeerence between the methods. This is also why we cannot do these comparisons at small values. It is only after we get to larger values that we see the differences between the two become substantial. This is indicated by the sloped section that is increasing with every step to higher order. 



*/


// include files
#include <iostream>		
#include <iomanip>		
#include <fstream>		
#include <cmath>
using namespace std;		

//*********************************************************************//
float up(int n){
    float val = 0;
    for (int i = 1; i <= n; i++){
        val += 1./i;
    }
  return val;
}

float down(int N){
    float val = 0;
    for (int i = N; i >= 1; i--){
        val += 1./i;
    }
  return val;
}

float diff(int n){
  return ((abs(up(n) - down(n)))/(0.5*(abs(up(n)) + abs(down(n)))));
}

int
main ()
{

  // open the plot file stream
  ofstream fplot ("Up_down.dat"); 
  fplot << "#     N    |UP|  |DOWN|  |DIFFERENCE|" << endl;

  
  long limit = pow(10,8);
  for(int i = 100; i <= limit; i *= 10){
    
    fplot << "  " << scientific << setprecision(6) << i <<
 	"   " << up(i)  << "  " << down(i)  << "        " << diff(i) << endl;
  }

  fplot.close();

  

  return (0);
}

