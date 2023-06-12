#include <stdio.h>
#include <stdlib.h>

#include "environnement.h"

<<<<<<< HEAD
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
=======
void incrementer(case_st sommet, environnement_st env)
{
    int i,j;
    sommet.priorite=1;
    i=sommet.coord[0];
    j=sommet.coord[1];
    while (env.grille[i][j].etat!=2 && 0<i<env.l-1)
    {
        sommet.priorite+=1;
        i++;
    }

    i=sommet.coord[0];
    j=sommet.coord[1];
    while (env.grille[i][j].etat!=2 && 0<i<env.l-1)
    {
        sommet.priorite+=1;
        i--;
    }

    i=sommet.coord[0];
    j=sommet.coord[1];
    while (env.grille[i][j].etat!=2 && 0<j<env.c-1)
    {
        sommet.priorite+=1;
        j++;
    }

    i=sommet.coord[0];
    j=sommet.coord[1];
    while (env.grille[i][j].etat!=2 && 0<j<env.c-1)
    {
        sommet.priorite+=1;
        j--;
    }
}

void decrementer(case_st sommet, environnement_st env)
{
    int i,j;
    sommet.priorite=1;
    i=sommet.coord[0];
    j=sommet.coord[1];
    while (env.grille[i][j].etat!=2 && 0<i<env.l-1)
    {
        sommet.priorite-=1;
        i++;
    }

    i=sommet.coord[0];
    j=sommet.coord[1];
    while (env.grille[i][j].etat!=2 && 0<i<env.l-1)
    {
        sommet.priorite-=1;
        i--;
    }

    i=sommet.coord[0];
    j=sommet.coord[1];
    while (env.grille[i][j].etat!=2 && 0<j<env.c-1)
    {
        sommet.priorite-=1;
        j++;
    }

    i=sommet.coord[0];
    j=sommet.coord[1];
    while (env.grille[i][j].etat!=2 && 0<j<env.c-1)
    {
        sommet.priorite-=1;
        j--;
    }
}

void tri(int *tab);
>>>>>>> 4788a6d3edf44cb20a8dcb7a0266ecdf70a4f6b3
