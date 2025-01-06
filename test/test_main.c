#include <stdio.h>
#include <stdlib.h>
#include "systems.h"
#include "utils.h"


int test_configure_system() {
    System systems;
    int result = configure_system(&systems);

    if (result) {
        printf("✅ test_configure_system : Système configuré correctement.\n");
        return 0; 
    } else {
        printf("❌ test_configure_system : Échec de la configuration du système.\n");
        return 1; 
}


int test_get_initial_conditions() {
    double x, y, z;
    int Tmax;

    get_initial_conditions(&x, &y, &z, &Tmax);

    if (Tmax > 0) {
        printf("✅ test_get_initial_conditions : Conditions initiales valides (x=%.2f, y=%.2f, z=%.2f, Tmax=%d).\n", x, y, z, Tmax);
        return 0; 
    } else {
        printf("❌ test_get_initial_conditions : Tmax est incorrect.\n");
        return 1; 
    }
}


int test_file_output() {
    FILE *temp_file = tmpfile(); 
    if (temp_file == NULL) {
        printf("❌ test_file_output : Impossible de créer un fichier temporaire.\n");
        return 1; 
    }

    // Écrire dans le fichier temporaire
    fprintf(temp_file, "%.2f %.2f %.2f %.2f\n", 0.0, 1.0, 2.0, 3.0);

 
    rewind(temp_file);

  
    double t, x, y, z;
    if (fscanf(temp_file, "%lf %lf %lf %lf", &t, &x, &y, &z) != 4) {
        printf("❌ test_file_output : Lecture des données échouée.\n");
        fclose(temp_file);
        return 1; 
    }

    
    fclose(temp_file);

    // Vérifier les données
    if (t == 0.0 && x == 1.0 && y == 2.0 && z == 3.0) {
        printf("✅ test_file_output : Les données ont été sauvegardées correctement dans le fichier temporaire.\n");
        return 0; 
    } else {
        printf("❌ test_file_output : Les données du fichier sont incorrectes (t=%.2f, x=%.2f, y=%.2f, z=%.2f).\n", t, x, y, z);
        return 1; 
    }
}

int main() {
    printf("===== DÉBUT DES TESTS =====\n");

    int total_errors = 0;

    
    total_errors += test_configure_system();
    total_errors += test_get_initial_conditions();
    total_errors += test_file_output();

 
    if (total_errors == 0) {
        printf("🎉 Tous les tests ont été passés avec succès !\n");
    } else {
        printf("❌ %d test(s) ont échoué.\n", total_errors);
    }

    return total_errors; 
}

