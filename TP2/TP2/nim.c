/*=====MODULE NIM=====*/
#include "nim.h"

// Fonction nim_plateau

void nim_plateau_init(int plateau[], int nb_colonnes) {

	// Déclaration de variables
	int i;

	for (i = 0; i < nb_colonnes; i++) {
		plateau[i] = md_randi(BORNE_PIECE);
	}
}

/*Fonction nim_qui_commence*/

int nim_qui_commence(void) {

	// Déclaration de variables
	int personne;

	personne = md_randint(0,1);

	return personne;
}


/*Fonction tour*/
int nim_jouer_tour(int plateau[], int nb_colonnes, int colonne, int nb_pieces){

	// Déclaration de variable
	int validite;

	if (plateau[colonne] - nb_pieces >= 0 && colonne < nb_colonnes) {
		plateau[colonne] -= nb_pieces;
			validite = 1;
	}
	else {
		validite = 0;
	}
	return validite;
}


/*fonction supprimer tableau*/
void nim_plateau_supprimer_colonne(int plateau[], int nb_colonnes, int col_a_supprimer) {

	int i;

	for (i = col_a_supprimer; i < nb_colonnes-1; i++) {

		plateau[i] = plateau[i + 1];
	}

	plateau[nb_colonnes] = 0;
}


/*Fonction defragmenter.*/
int nim_plateau_defragmenter(int plateau[], int nb_colonnes) {

// Déclaration de variable.
	int i;
	int compteur=0; 
	int nv_nb_colonnes;

	for (i = 0; i < nb_colonnes; i++) {

		if (plateau[i] == 0) {
			nim_plateau_supprimer_colonne(plateau, nb_colonnes, i);
			compteur++;
		}
	}
	nv_nb_colonnes = nb_colonnes - compteur;
	return nv_nb_colonnes;
}

 // Fonction nim_choix_ai

void nim_choix_ia(const int plateau[], int nb_colonnes, double difficulte, int *choix_colonne, int *choix_nb_pieces) {

	nim_choix_ia_aleatoire(plateau, nb_colonnes, choix_colonne, choix_nb_pieces);
}
 
/*Fonction nombre aléatroie.*/

void nim_choix_ia_aleatoire(const int plateau[], int nb_colonnes, int *choix_colonne, int *choix_nb_pieces) {

	*choix_colonne = md_randi(nb_colonnes-1);
	*choix_nb_pieces = md_randi(plateau[*choix_colonne]);
	
}