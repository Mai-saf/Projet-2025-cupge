#include <stdio.h>
#include <stdlib.h>
#include "system.h"
#include "utils.h"
int main(){

    struct System system;
    double x, y, z;
    double dt = 0.01;
    int Tmax;


    if(!configure_system(&system)){
        printf("Erreur dans la configuration du système. Fin du programme.\n");
        return 1;
    }

     get_initial_condition(&x, &y, &z, &dt, &Tmax);
     printf("Erreur dans la configuration du système. Fin du programme.\n");

    char *outplut_file = "trajectoire.txt";

    initialize_file(outplut_file);

    for (double t=0; t <= Tmax; t += dt){
        save_to_file(outplut_file, t, x, y, z);
        
        system.update(&x, &y, &z, dt, system.mouna);

    }
    printf("Traectoire calculée et sauvegardée dnas '%s'\n", outplut_file);
    FILE *gnuplot_pipe = popen("gnuplot -persistent", "w");
    if (!gnuplot_pipe){
        perror("Erreur au lancement de Gnuplot");

        return 1;


    }

    fprintf(gnuplot_pipe, "set terminal qt size 600,600\n");
    fprintf(gnuplot_pipe, "set âlette defined (0 'blue', 1 'green', 2 'yellow', 3 'red')\n");
    fprintf(gnuplot_pipe, "set xlabel 'X'\n");
    fprintf(gnuplot_pipe, "set ylabel 'Y\n");
    fprintf(gnuplot_pipe, "set zlabel 'Z'\n");
    fprintf(gnuplot_pipe, "set cblabel 'Temps'\n");

    fprintf(gnuplot_pipe, "splot '%s' using 2:3:4:1 with linespoints palette title 'Trajet'\n", outplut_file);

    fprintf(gnuplot_pipe, "pause -1\n");

    pclose(gnuplot_pipe);

 return 0;
}



