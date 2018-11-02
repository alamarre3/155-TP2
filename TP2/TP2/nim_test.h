#ifndef NIM_TEST_H_
#define NIM_TEST_H_

#include "nim.h"
#include "nim_ihm.h"
#include <assert.h>

void nim_test_plateau_init(int plateau[], int nb_colonnes);
void nim_test_qui_commence(void);
void nim_test_jouer_tour(void);
void nim_test_plateau_supprimer_colonne(void);
void nim_test_plateau_defragmenter(void);


#endif