#ifndef ENVIRONNEMENT_H
#define ENVIRONNEMENT_H

#define NON_COUVERT 0
#define CIBLE 1
#define OBSTACLE 2
#define SURVEILLANT 3
#define CIBLE_ET_SURVEILLANT 4

typedef struct {
  int priorite;
  int etat;
  int coord[2]; //pour pouvoir trier sans perdre les coordonnées d'origine
} case_st;

typedef struct {
  int l; //nombre de ligne
  int c; //nombre de colonnes
  case_st **grille;
} environnement_st;


void initEnv(environnement_st *env, char *nomFic);
int readEtat(char* strEtat);


void incrementer(case_st sommet,environnement_st *env);
void decrementer(case_st sommet,environnement_st *env);
void tri_fusion(case_st tab[],int deb,int fin,environnement_st *env);
void fusion(case_st tab[], int deb1, int fin1, int fin2,environnement_st *env);
void placement_surveillant(environnement_st *env);
void creation_tab(int taille_tab,case_st *tab, environnement_st *env);

#endif // ENVIRONNEMENT_H


