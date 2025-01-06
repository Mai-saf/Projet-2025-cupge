#include "system.h"
 #ifndef UTILS_H

 #define UTILS_H

 void initialize_file(const char *);
 void save_to_file(const char *, double , double , double , double  );
 void get_initial_condition(double *, double*,double*,double*,int *);
 double evaluate_rpn(const char *, double ,double , double , struct parameters * );
 #endif

