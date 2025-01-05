#include <stdio.h>
#include <string.h>
#include "systems.h"
#include "utils.h"

int configure_system(System *system){
    char update_funtion[256];
    printf("Définissez la fonction de mise à jour (lorenz ou custom) :\n");
    scanf("%s", update_funtion);

    printf("Entrer les paramètres du système (sigma, rho, beta) :\n");
    scanf("%f %lf %lf , &system->params.sigma, &system->params.rho, &system->params.beta");

    if(strcmp(update_funtion, "lorenz") == 0){
        printf("Système de Lorenz sélectionné. \n");
        system->update = update_lorenz;
    } else if (strcmp(update_funtion, "custom") == 0){
        printf("Système personaalisé sélectionné. \n");

        static char rpn_x[256], rpn_z[256];
        printf("Entrez la formule RPN pour dx/dt :\n");
        scanf(" %[^]s", rpn_x);
        printf("Entrez la formule RPN pour dy/dt :\n");
        scanf(" %[^]s", rpn_y);
        printf("Entrez la formule RPN pour dz/dt :\n");
        scanf(" %[^]s, rpn_z");

    

        system->params.rpn_x = rpn_x;
        system->params.rpn_y = rpn_y;
        system->params.rpn_z = rpn_z;

        system->update = update_custom;

    } else {
        printf("Fonction non reconnue.\n");
        return 0;
    }
    return 1;

}

void update_lorenz(double *x, double *y, double *z, double dt, Parameters params){
    double dx = params.sigma * (*y- *x);
    double dy = *x * (params.rho - *z) - *y;
    double dz = *x * *y - params.beta * *z;

    *x += dx * dt;
    *y += dy * dt;
    *z += dz * dt;

}
void update_custom(double *x, double *y, double *z, double dt, Parameters params){
    double new_x = evaluate_rpn(params.rpn_x, *x, *y, *z, params);
    double new_y = evaluate_rpn(params.rpn_y, *x, *y, *z, params);
    double new_z = evaluate_rpn(params.rpn_z, *x, *y, *z, params);

    *x += new_x * dt;
    *y += new_y * dt;
    *z += new_z * dt;

}

}