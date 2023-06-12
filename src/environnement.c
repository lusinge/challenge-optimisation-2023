#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "environnement.h"

void initEnv(environnement_st *env, char *nomFic) {
    FILE *fichier = fopen(nomFic, "r");
    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier data %s.\n", nomFic);
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

    int i, j;
    char strEtat[20];
    while (fscanf(fichier, "%s %d %d", strEtat, &i, &j) == 3) {
        env->grille[i][j].etat = readEtat(strEtat);
        if (strcmp(strEtat, "CIBLE"))
                env->nbCiblesNonCouvertes++;
        env->grille[i][j].coord[0] = i;
        env->grille[i][j].coord[1] = j;
    }

    fclose(fichier);
}

int readEtat(char* strEtat) {
    int etat = 0;
    if (strcmp(strEtat, "CIBLE") == 0)
        etat = CIBLE_NON_COUVERTE;
    else if (strcmp(strEtat, "OBSTACLE") == 0)
        etat = OBSTACLE;
    return etat;
}

void printEnv(environnement_st *env) {
    for (int i = 0; i < env->l; i++) {
        for (int j = 0; j < env->c; j++){
            printf("%d", env->grille[i][j].etat);
        }
        printf("\n");
    }
    printf("\n");

    for (int i = 0; i < env->l; i++) {
        for (int j = 0; j < env->c; j++){
            printf("%d", env->grille[i][j].priorite);
        }
        printf("\n");
    }
    printf("\n\n");
}

void incrementer(int i, int j, environnement_st *env)
{
    env->grille[i][j].priorite++;

    int k,l;

    k = i+1;
    l = j;
    //Parcours à droite
    while (0 <= k && k < env->l && env->grille[k][l].etat != OBSTACLE)
        {
            (env->grille[k][l].priorite)++;
            k++;
        }

    k = i-1;
    l = j;
    //Parcours à gauche
   while (0 <= k && k < env->l && env->grille[k][l].etat != OBSTACLE)
        {
            (env->grille[k][l].priorite)++;
            k--;
        }

    k = i;
    l = j+1;
    //Parcours en bas
   while (0 <= l && l < env->c && env->grille[k][l].etat != OBSTACLE)
        {
            (env->grille[k][l].priorite)++;
            l++;
        }

    k = i;
    l = j-1;
    //Parcours en haut
   while (0 <= l && l < env->c && env->grille[k][l].etat != OBSTACLE)
        {
            (env->grille[k][l].priorite)++;
            l--;
        }
}

void decrementer(int i, int j, environnement_st *env)
{
    env->grille[i][j].priorite--;

    int k,l;

    k = i+1;
    l = j;
    //Parcours à droite
    while (0 <= k && k < env->l && env->grille[k][l].etat != OBSTACLE)
        {
            (env->grille[k][l].priorite)--;
            k++;
        }

    k = i-1;
    l = j;
    //Parcours à gauche
    while (0 <= k && k < env->l && env->grille[k][l].etat != OBSTACLE)
        {
            (env->grille[k][l].priorite)--;
            k--;
        }

    k = i;
    l = j+1;
    //Parcours en bas
   while (0 <= l && l < env->c && env->grille[k][l].etat != OBSTACLE)
        {
            (env->grille[k][l].priorite)--;
            l++;
        }

    k = i;
    l = j-1;
    //Parcours en haut
   while (0 <= l && l < env->c && env->grille[k][l].etat != OBSTACLE)
        {
            (env->grille[k][l].priorite)--;
            l--;
        }
}

int couvrir(int i, int j, environnement_st *env)
{
    if (env->grille[i][j].etat == OBSTACLE)
        return 0;
    int cnt_cible_couverte = 0;
    if (env->grille[i][j].etat == CIBLE_COUVERTE || env->grille[i][j].etat == CIBLE_NON_COUVERTE) {
        if (env->grille[i][j].etat == CIBLE_NON_COUVERTE) {
            decrementer(i, j, env);
            cnt_cible_couverte++;
        }
        env->grille[i][j].etat = CIBLE_ET_SURVEILLANT;
    }
    else
        env->grille[i][j].etat = SURVEILLANT;


    int k, l;

    //Parcours à droite
    k = i+1;
    l = j;
    while (0 <= k && k < env->l && env->grille[k][l].etat != OBSTACLE)
    {
        if(env->grille[k][l].etat == CIBLE_NON_COUVERTE)
        {
            cnt_cible_couverte++;
            env->grille[k][l].etat = CIBLE_COUVERTE;
            decrementer(k, l, env);
        }
        k++;
    }

    //Parcours à gauche
    k = i-1;
    l = j;
    while (0 <= k && k < env->l && env->grille[k][l].etat != OBSTACLE)
    {
        if(env->grille[k][l].etat == CIBLE_NON_COUVERTE)
        {
            cnt_cible_couverte++;
            env->grille[k][l].etat = CIBLE_COUVERTE;
            decrementer(k, l, env);
        }
        k--;
    }

    //Parcours en bas
    k = i;
    l = j+1;
   while (0 <= l && l < env->c && env->grille[k][l].etat != OBSTACLE)
    {
        if(env->grille[k][l].etat == CIBLE_NON_COUVERTE)
        {
            cnt_cible_couverte++;
            env->grille[k][l].etat = CIBLE_COUVERTE;
            decrementer(k, l, env);
        }
        l++;
    }

    //Parcours en haut
    k = i;
    l = j-1;
   while (0 <= l && l < env->c && env->grille[k][l].etat != OBSTACLE)
    {
        if(env->grille[k][l].etat == CIBLE_NON_COUVERTE)
        {
            cnt_cible_couverte++;
            env->grille[k][l].etat = CIBLE_COUVERTE;
            decrementer(k, l, env);
        }
        l--;
    }

    return cnt_cible_couverte;
}

void algo2(environnement_st *env)
{
    for (int i = 0; i < env->l; i++) {
        for (int j = 0; j < env->c; j++){
            if (env->grille[i][j].etat == CIBLE_NON_COUVERTE) {
                incrementer(i, j, env);
            }
        }
    }
    
    int priorite_max = -1;
    int i_max = -1;
    int j_max = -1;
    
    while (env->nbCiblesNonCouvertes > 0 && priorite_max != 0) {
        priorite_max = -1;
        j_max = -1;
        i_max = -1;
        for (int i = 0; i < env->l; i++) {
            for (int j = 0; j < env->c; j++){
                if (priorite_max < env->grille[i][j].priorite) {
                    priorite_max = env->grille[i][j].priorite;
                    i_max = i;
                    j_max = j;
                }
            }
        }
        if (j_max >= 0 && i_max >= 0)
            couvrir(i_max, j_max, env);
    }

}

