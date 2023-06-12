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
