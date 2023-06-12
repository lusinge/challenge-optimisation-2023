#include <stdio.h>
#include <stdlib.h>
#include "environnement.h"

#include "challenge.h"

void algo1(environnement_st *env) {
    for (int i = 0; i < env->l; i++) {
        for (int j = 0; j < env->c; j++){
            if (env->grille[i][j].etat == CIBLE_NON_COUVERTE) {
                env->grille[i][j].etat = CIBLE_ET_SURVEILLANT;
            }
        }
    }
}

void writeEnv(char *nomFic, environnement_st *env, int instance) {
    FILE *fichier = fopen(nomFic, "w");
    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier write.\n");
        return;
    }

    fprintf(fichier,"EQUIPE Ronflex\n");
    fprintf(fichier,"INSTANCE %d\n", instance);

    for (int i = 0; i < env->l; i++) {
        for (int j = 0; j < env->c; j++) {
            int etat = env->grille[i][j].etat;
            if (etat == SURVEILLANT || etat == CIBLE_ET_SURVEILLANT) {
                fprintf(fichier, "%d %d\n", i, j);
            }
         }
    }

    fclose(fichier);
}
