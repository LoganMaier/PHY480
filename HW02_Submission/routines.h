//
// Created by Logan  Maier on 3/8/21.
//

extern double simpsons_rule ( int num_pts, double x_min, double x_max,
                       double (*integrand) (double x) );

extern double milne_rule (int num_pts, double x_min, double x_max,
                   double (*integrand) (double x) );

extern double gsl_approach(double x_min, double x_max,
                    double (*integrand) (double x, void *));

