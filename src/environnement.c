#include <stdio.h>
#include <stdlib.h>

#include "environnement.h"

void initEnv(environnement_st *env, char *nomFic) {
    FILE *fichier = fopen(nomFic, "r");
    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        exit(1);
    }

    int nbLignes, nbColonnes;
    fscanf(fichier, "LIGNES %d\n", &nbLignes);
    fscanf(fichier, "COLONNES %d\n", &nbColonnes);

    env->l = nbLignes;
    env->c = nbColonnes;

    env->grille = (case_st **)malloc(nbLignes * sizeof(case_st *));
    for (int i = 0; i < nbLignes; i++) {
        env->grille[i] = (case_st *)malloc(nbColonnes * sizeof(case_st));
    }

    int etat, i, j;
    char strEtat[20];
    while (fscanf(fichier, "%s %d %d", strEtat, &i, &j) == 3) {
        env->grille[i][j].etat = readEtat(strEtat);
        env->grille[i][j].coord[0] = i;
        env->grille[i][j].coord[1] = j;
    }

    fclose(fichier);
}

void readEtat(char* strEtat) {
    int etat;
    //TODO: Convertir les strings du fichier en constante
    return etat;
}
