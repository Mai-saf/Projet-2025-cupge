int main(){
    
    double x,y,z;
    double dt;
    double rho, sigma, beta;
    int Tmax;
    printf ("Entrez l'increment");
    scanf("%lf", &dt );
    printf ("Entrez les positions initiales(x,y,z):");
    scanf("%lf %lf %lf", &x, &y, &z);
    printf ("Entrez le temps d'arrêt maximale");
    scanf("%lf",&Tmax);
    return 0;
}


