#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include "utils.h"
#include "system.h"

void initialize_file(const char *filename) {
    FILE *file = fopen (filename, "w");
    if (file == NULL) {
        perror ("Erreur lors de l'initialisation du fichier");
            return;
    };
    fprintf(file, "# Temps x y z\n");
    fclose(file);
}


void save_to_file (const char *filename, double t, double x, double y, double z) {
    FILE *file = fopen(filename, "a");
    if (file == NULL) {
        perror ("Erreur lors de l'ouverture du fichier");
        return ;

    }
    fprintf(file, "%lf %lf %lf %lf\n", t, x, y, z);
    fclose(file);

}

void get_initial_condition(double *x, double *y, double *z, double *dt, int *Tmax){
    printf("Entrez les positions intitiales (x, y, z) : ");
    scanf("%lf %lf %lf", x, y, z);

    printf("Entrez l'incrément de temps dt : ");
    scanf("%lf", dt);

    printf("Entrez le temps maximum Tmax : ");
    scanf("%d", Tmax);

    if (*dt <=0 || *Tmax <= 0) {
        printf("Erreur : dt et Tmax doivent être positifs.\n");
        exit(1);
    }
}

double evaluate_rpn(const char *rpn, double x, double y, double z, struct  parameters *params) {
    double stack[100];
    int sp = 0;

    for (int i =0; rpn[i] != '\0'; i ++) {
        char c = rpn[i];

        if (isspace(c)) {
            continue;
        }
        if (c == 'x'){
            stack[sp++] = x;
        }else if (c == 'y'){
            stack[sp++] = y;
        }else if (c == 'z'){
            stack[sp++] = z;
        }else if(c == 's'){
            stack[sp++] = params->sigma;
        }else if (c == 'r'){
            stack[sp++] = params->rho;
        }else if (c == 'r'){
          stack[sp++] = params->beta;
        }
        else if (c == '+' || c == '*' || c == '/')  {
            if (sp < 2){
                fprintf (stderr, "Erreur : pile insuffisante pour '%C'.\n", c);
                exit(1);
            }
        double b = stack[--sp];
        double a = stack[--sp];

        switch (c) {
            case '+' : stack[sp++] = a + b; break;
            case '-' : stack[sp++] = a - b; break;
            case '*' : stack[sp++] = a * b; break;
            case '/' : stack[sp++] = (b!= 0) ? a /b: 0; break;
        }
        }

    else if (isdigit(c) || c == '.'){
        char buffer[16];
        int j = 0;


        while (isdigit(rpn[i]) || rpn [i] == '.') {
            buffer [j++] = rpn[i++];
        }
        buffer[j] = '\0';
        stack[sp++] = atof(buffer);

        i--;
    }

    else {
        fprintf(stderr, "Erreur : caractère non valide '%c'.\n", c);
        exit(1);
    }
    }
    if (sp != 1){
        fprintf(stderr, "Erreur : pile finale invalide.\n");
        exit(1);
    }
    return stack[0];

}













