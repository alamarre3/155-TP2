//===== MODULE TEST nim.c =====
#include "nim_test.h"

// Test de la fonction plateau_init

void nim_test_plateau_init(int plateau[],int nb_colonnes) {

	// Déclaration de variables
	int i;
	int test = 1; // Variable utilisé pour la vérification de la fonction

	if (nb_colonnes > BORNE_TAB) {
		test = 0;
	}

	for (i = 0; i < nb_colonnes; i++) {
		plateau[i] = md_randi(BORNE_PIECE);
		if (plateau[i] < 1 || plateau[i]>35) {
			test = 0;
		}
	}

	if (plateau[nb_colonnes + 1] == 0 && nb_colonnes > BORNE_TAB) {
		test = 0;
	}
	assert(test);
}

// Test de la fonction nim_qui_commence

void nim_test_qui_commence(void) {

	// Déclaration de variables
	int test = 1; // Variable utilisé pour la vérification de la fonction
	int personne; // Chiffre décidant qui commence la partie

	personne = md_randint(0, 1);

	assert(personne == 0 || personne ==1);
}

// Test de la fonction jouer_tour

void nim_test_jouer_tour() {

	// Déclaration des variables
	int plateau[BORNE_TAB]; // Plateau de test
	int colonne ; // Variable du choix de la colonne
	int nb_pieces; // Variable du nombre de pièces
	int nb_colonnes = BORNE_TAB; // Nombre de colonnes du plateau
	
	nim_plateau_init(plateau, BORNE_TAB);
	nb_pieces = plateau[7];
	colonne = 7;
	if (plateau[colonne] - nb_pieces >= 0 && colonne < nb_colonnes) {
		plateau[colonne] -= nb_pieces;
	}
	else {
		assert(0);
	}

	assert(plateau[colonne]==0);
}

// Test de la fonction plateau_supprimer_colonne

void nim_test_plateau_supprimer_colonne() {

	// Déclaration des variables
	int plateau[BORNE_TAB];
	int col_a_supprimer; // Variable pour la colonne à supprimer
	int i; // Variable d'incrémentation
	int nb_colonnes; // Variable utilisée pour le nombre de colonnes

	for (i = 0; i < BORNE_TAB; i++) {
		plateau[i] = 0;
	}
	nb_colonnes = 2;
	col_a_supprimer = 0;
	nim_plateau_init(plateau, nb_colonnes);
	
 	for (i = col_a_supprimer; i < nb_colonnes - 1; i++) {
		plateau[i] = plateau[i + 1];
	}
	plateau[nb_colonnes] = 0;

	assert(plateau[col_a_supprimer]==plateau[col_a_supprimer+1]);
}

// Test de la fonction plateau_defragmenter

void nim_test_plateau_defragmenter() {

	// Déclaration des variables
	int i;
	int plateau[BORNE_TAB];
	int compteur = 0;
	int nb_colonnes = BORNE_TAB;
	int nv_nb_colonnes;

	nim_plateau_init(plateau, BORNE_TAB);
	plateau[6] = 0;

	for (i = 0; i < nb_colonnes; i++) {

		if (plateau[i] == 0) {
			nim_plateau_supprimer_colonne(plateau, nb_colonnes, i);
			compteur++;
		}
	}
	nv_nb_colonnes = nb_colonnes - compteur;
	assert(nv_nb_colonnes==19);
}

// Test 
