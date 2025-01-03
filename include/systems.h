 #include<stdio.h>
 #ifndef SYSTEMS_H
 #define SYSTEMS_H
 struct Parameters {
    double sigma;
    double rho;
    double beta;
    char *rpn_x;
    char *rpn_y;
    char *rpn_z;
 };

struct System{
    Parameters params;
    void(*update)(double*,double*,double*,double,Parameters);
};
int configure_system(System*system);
void update_lorenz(double*x,double*y,double*z,double dt,Parameters params);
void update_custom(double*x,double*y,double*z,double dt,Parameters params);

#endif 