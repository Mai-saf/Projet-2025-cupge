 #ifndef SYSTEMS_H
 #define SYSTEMS_H
 struct parameters{
    double sigma;
    double rho;
    double beta;
    char *rpn_x;
    char *rpn_y;
    char *rpn_z;
 };

 struct System{
    struct parameters *mouna;
    void (*update) (double*, double*,double* ,double , struct parameters*);
 };

 int configure_system( struct System *);
 void update_lorenz(double*,double*,double*,double , struct parameters*);
 void update_custom(double*,double*,double*,double , struct parameters*);

#endif
