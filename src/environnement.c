#include <stdio.h>
#include <stdlib.h>

#include "environnement.h"

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