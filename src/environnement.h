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

#endif // ENVIRONNEMENT_H