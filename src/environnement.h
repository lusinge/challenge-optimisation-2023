#ifndef ENVIRONNEMENT_H
#define ENVIRONNEMENT_H

#define RIEN 0
#define CIBLE_NON_COUVERTE 1
#define CIBLE_COUVERTE 2
#define OBSTACLE 3
#define SURVEILLANT 4
#define CIBLE_ET_SURVEILLANT 5

typedef struct {
  int priorite;
  int etat;
  int coord[2]; //pour pouvoir trier sans perdre les coordonnées d'origine
} case_st;

typedef struct {
  int l; //nombre de ligne
  int c; //nombre de colonnes
  int nbCiblesNonCouvertes;
  case_st **grille;
} environnement_st;


void initEnv(environnement_st *env, char *nomFic);
int readEtat(char* strEtat);
void printEnv(environnement_st *env);


void incrementer(case_st sommet,environnement_st *env);
void decrementer(case_st sommet,environnement_st *env);
void tri_fusion(case_st tab[],int deb,int fin,environnement_st *env);
void fusion(case_st tab[], int deb1, int fin1, int fin2,environnement_st *env);
void placement_surveillant(environnement_st *env);
void creation_tab(int taille_tab,case_st *tab, environnement_st *env);
void incremation_tab(case_st *tab,int taille_tab,environnement_st *env);
#endif // ENVIRONNEMENT_H


