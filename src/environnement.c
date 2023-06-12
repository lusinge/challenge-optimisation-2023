#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

    int i, j;
    char strEtat[20];
    while (fscanf(fichier, "%s %d %d", strEtat, &i, &j) == 3) {
        env->grille[i][j].etat = readEtat(strEtat);
        if (strcmp(strEtat, "CIBLE")
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
}

void incrementer(case_st sommet, environnement_st env)
{
    int i,j;
    sommet.priorite=1;
    i=sommet.coord[0];
    j=sommet.coord[1];
    while (env->grille[i][j].etat!=2 && 0<i<env->l-1)
    {
        sommet.priorite+=1;
        i++;
    }

    i=sommet.coord[0];
    j=sommet.coord[1];
    while (env->grille[i][j].etat!=2 && 0<i<env->l-1)
    {
        sommet.priorite+=1;
        i--;
    }

    i=sommet.coord[0];
    j=sommet.coord[1];
    while (env->grille[i][j].etat!=2 && 0<j<env->c-1)
    {
        sommet.priorite+=1;
        j++;
    }

    i=sommet.coord[0];
    j=sommet.coord[1];
    while (env->grille[i][j].etat!=2 && 0<j<env->c-1)
    {
        sommet.priorite+=1;
        j--;
    }
}

void decrementer(case_st sommet, environnement_st *env)
{
    int i,j;
    sommet.priorite=1;
    i=sommet.coord[0];
    j=sommet.coord[1];
    while (env->grille[i][j].etat!=2 && 0<i<env->l-1)
    {
        sommet.priorite-=1;
        i++;
    }

    i=sommet.coord[0];
    j=sommet.coord[1];
    while (env->grille[i][j].etat!=2 && 0<i<env->l-1)
    {
        sommet.priorite-=1;
        i--;
    }

    i=sommet.coord[0];
    j=sommet.coord[1];
    while (env->grille[i][j].etat!=2 && 0<j<env->c-1)
    {
        sommet.priorite-=1;
        j++;
    }

    i=sommet.coord[0];
    j=sommet.coord[1];
    while (env->grille[i][j].etat!=2 && 0<j<env->c-1)
    {
        sommet.priorite-=1;
        j--;
    }
}
void creation_tab(int taille_tab,case_st *tab, environnement_st *env)
{
 int i,j;
 int k=0;
 tab=malloc(sizeof(case_st)*taille_tab);
 while(k<taille_tab)
 {
 for (i=0;i<env->l;i++)
    {
        for (j=0;j<env->c;j++)
        {
            tab[k]=env->grille;
            k++;
        }
    }
 }
 
}
void tri_fusion(case_st tab[],int deb,int fin,environnement_st *env)
{
   int lg, finSequence1;

  lg = fin - deb + 1;
  finSequence1 = deb + lg/2 - 1;
  if (lg > 1)
  {
    tri_fusion(tab, deb, finSequence1,&env);
    tri_fusion(tab, finSequence1 + 1, fin,&env);
    fusion(tab, deb, finSequence1, fin,&env);
  }
}

void fusion(case_st tab[], int deb1, int fin1, int fin2,environnement_st *env)
{
  case_st temp[TAILLE_MAX];
  int i1 = deb1, i2 = fin1 + 1, itemp = 0, i;

 
  while (i1 <= fin1 && i2 <= fin2)
  {
    if (tab[i1].priorite <= tab[i2].priorite)
    {
      temp[itemp] = tab[i1];
      i1++;
    }
    else
    {
      temp[itemp] = tab[i2];
      i2++;
    }
    itemp++;
  }
  // a ce stade on a fini le parcours d'au moins l'une des 2 sequences,
  // on copie les elements restants de l'autre sequence
  while (i1 <= fin1)
  {
      temp[itemp] = tab[i1];
      i1++;
      itemp++;
  }
  while (i2 <= fin2)
  {
      temp[itemp] = tab[i2];
      i2++;
      itemp++;
  }

  // recopie du tableau temporaire dans la sequence finale
  for (i = deb1; i <= fin2; i++)
    tab[i] = temp[i - deb1];
  
}

void placement_surveillant(environnement_st *env)
{
    case_st tab;
    int taille_tab=env->l*env->c;
    creation_tab(taille_tab,&tab,&env);
    tri_fusion(&tab,0,taille_tab-1,&env);
    while  ()

}

