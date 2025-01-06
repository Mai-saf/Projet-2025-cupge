#include <stdio.h>
#include <string.h>
#include"stdlib.h"
#include "system.h"
#include "utils.h"

int configure_system( struct System *system){
    char update_funtion[256];
    printf("Définissez la fonction de mise à jour (lorenz ou custom) :\n");
    scanf("%s", update_funtion);
    if (system->mouna == NULL) {
        system->mouna = malloc(sizeof(struct parameters));
        if (system->mouna == NULL) {
            printf("Erreur d'allocation mémoire.\n");
            return 0;
        }
    }
    printf("Entrer les paramètres du système (sigma, rho, beta) :\n");
    scanf("%lf %lf %lf" , &system->mouna->sigma, &system->mouna->rho, &system->mouna->beta);

    if(strcmp(update_funtion, "lorenz") == 0){
        printf("Système de Lorenz sélectionné. \n");
        system->update = update_lorenz;
    } else if (strcmp(update_funtion, "custom") == 0){
        printf("Système personaalisé sélectionné. \n");

        char rpn_x[256],rpn_y[256], rpn_z[256];
        printf("Entrez la formule RPN pour dx/dt :\n");
        scanf(" %255s", rpn_x);
        printf("Entrez la formule RPN pour dy/dt :\n");
        scanf(" %255s", rpn_y);
        printf("Entrez la formule RPN pour dz/dt :\n");
        scanf(" %255s", rpn_z);



        system->mouna->rpn_x = strdup(rpn_x);
        system->mouna->rpn_y = strdup(rpn_y);
        system->mouna->rpn_z = strdup(rpn_z);

        system->update= update_custom;

    } else {
        printf("Fonction non reconnue.\n");
        return 0;
    }
    return 1;
}

void update_lorenz(double *x, double *y, double *z, double dt, struct parameters *mouna){
    double dx = mouna->sigma * (*y- *x);
    double dy = *x * (mouna->rho - *z) - *y;
    double dz = *x * *y - mouna->beta * *z;


    *x += dx * dt;
    *y += dy * dt;
    *z += dz * dt;

}
void update_custom(double *x, double *y, double *z, double dt,struct parameters *mouna){
    double new_x = evaluate_rpn(mouna->rpn_x, *x, *y, *z, mouna);
    double new_y = evaluate_rpn(mouna->rpn_y, *x, *y, *z, mouna);
    double new_z = evaluate_rpn(mouna->rpn_z, *x, *y, *z, mouna);

    *x += new_x * dt;
    *y += new_y * dt;
    *z += new_z * dt;



}

