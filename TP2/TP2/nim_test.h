#ifndef NIM_TEST_H_
#define NIM_TEST_H_

#include "nim.h"
#include "nim_ihm.h"
#include <assert.h>

/*=====MODULE DE TEST=====
 Ce module comprend les fonctions de test du modules nim. Il doit inclure une fonction
 de test pour chaque fonction du module nim, ainsi qu’une fonction qui appelle toutes
 les fonctions de test du module.*/

/* Fonction nim_test
	Description : La fonction appele toutes les autres fonctions de test du module.
	Paramètres :
		- Aucun
	Sortie :
		- Aucune*/

void nim_test(void);

/* Fonction nim_test_plateau_init
	Description : La fonction teste la fonction nim_plateau_init
	Paramètres :
		- Aucun
	Sortie :
		- Aucune*/

void nim_test_plateau_init(void);

/* Fonction nim_test_qui_commence
	Description : La fonction teste la fonction nim_qui_commence
	Paramètres :
		- Aucun
	Sortie :
		- Aucune*/

void nim_test_qui_commence(void);

/* Fonction nim_test_jouer_tour
	Description : La fonction teste la fonction nim_jouer_tour
	Paramètres :
		- Aucun
	Sortie :
		- Aucune*/

void nim_test_jouer_tour(void);

/* Fonction nim_test_plateau_supprimer_colonne
	Description : La fonction teste la fonction nim_plateau_supprimer_colonne
	Paramètres :
		- Aucun
	Sortie :
		- Aucune*/

void nim_test_plateau_supprimer_colonne(void);

/* Fonction nim_test_plateau_defragmenter
	Description : La fonction teste la fonction nim_plateau_defragmenter
	Paramètres :
		- Aucun
	Sortie :
		- Aucune*/

void nim_test_plateau_defragmenter(void);

/* Fonction nim_test_choix_ia_aleatoire
	Description : La fonction teste la fonction nim_choix_ia_aleatoire
	Paramètres :
		- Aucun
	Sortie :
		- Aucune*/

void nim_test_choix_ia_aleatoire(void);

/* Fonction nim_test_construire_mat_binaire
	Description : La fonction teste la fonction nim_construire_mat_binaire
	Paramètres :
		- Aucun
	Sortie :
		- Aucune*/

void nim_test_construire_mat_binaire(void);

/* Fonction nim_test_sommes_mat_binaire
	Description : La fonction teste la fonction nim_sommes_mat_binaire
	Paramètres :
		- Aucun
	Sortie :
		- Aucune*/

void nim_test_sommes_mat_binaire(void);

/* Fonction nim_test_position_premier_impaire
	Description : La fonction teste la fonction nim_position_premier_impaire
	Paramètres :
		- Aucun
	Sortie :
		- Aucune*/

void nim_test_position_premier_impaire(void);

/* Fonction nim_test_choix_ia
	Description : La fonction teste la fonction nim_choix_ia
	Paramètres :
		- Aucun
	Sortie :
		- Aucune*/

void nim_test_choix_ia(void);

#endif