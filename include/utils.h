 #include<stdio.h>
 #include "systems.h"
 #ifndef UTILS_H
 #define UTILS_H
 
 void initialize_file(const char *filename);
 void save_to_file(const char *filename, double t, double x, double y, double z );
 void get_initial_conditions(double *x, double*y,double*z,double*dt,int *Tmax);
 void evaluate_rpn(const char *rpn, double x,double y, double z, Parameters params);
 #endif

