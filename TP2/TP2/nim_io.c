/*=====MODULE NIM_IO======*/

#include "nim_io.h"
#include "nim_ihm.h"
#include "nim.h"

// Fonction lire_entier

int lire_entier(int min, int max) {

	// Déclaration des variables
	int entier; // Valeur d'un entier saisi par l'usage

	ihm_scanf("%d", &entier);
	if (entier >= min && entier <= max) {
		return entier;
	}
	else {
		ihm_printf("Valeur saisie non valide, veuillez saisir une valeur dans l'intervalle %d et %d.\n", min, max);
		return -1;
	}
}

// Fonction plateau_afficher
 
void plateau_afficher(const int plateau[], int nb_colonnes) {

	// Déclaration de variables
	int i, y; // Valeur d'incrémentation

	ihm_changer_taille_plateau(BORNE_PIECE, nb_colonnes);

	for (i = 0; i < BORNE_PIECE; i++) {

		for (y = 0; y < nb_colonnes; y++) {
			if (plateau[i] > i) {
				ihm_ajouter_piece(i, y);
			}
		}
	}
}

// Fonction tour_humain

void tour_humain(int plateau[], int nb_colonnes) {

	// Déclaration des variables
	int colonne; // Colonne choisi par l'usager
	int pieces = -1; // Nombre de pièces saisies par l'usager

	ihm_printf(" ===== TOUR HUMAIN =====");
	ihm_printf("Choisir une colonne du plateau.");
	colonne = ihm_choisir_colonne;
	ihm_printf("Choisir un nombre de pièces entre 1 et %d : ", plateau[colonne]);
	do {
		pieces = lire_entier(MIN_PIECES, plateau[colonne]);
	} while (pieces == -1);	
	ihm_scanf("%d", pieces);
	nim_jouer_tour(plateau, nb_colonnes, colonne, pieces);
}

// Fonction tour_ia

void tour_ia(int plateau[], int nb_colonnes, double difficulte) { // Un jour Vérification des valeurs à -1

	// Déclaration des variables
	int choix_colonne; // Choix de la colonne par l'ia
	int choix_pieces; // Choix du nombre de pièces à enlever par l'ia
	int *choix_colonne_ptr = &choix_colonne; // Pointeur de la variable choix_colonne
	int *choix_pieces_ptr = &choix_pieces; // Pointeur de la variables choix_pieces

	ihm_printf(" ===== TOUR ORDINATEUR =====");
	nim_choix_ia(plateau, nb_colonnes, difficulte, choix_colonne_ptr, choix_pieces_ptr);
	ihm_printf("L'ordinateur retire %d dans la colonne %d.\n", choix_pieces, choix_colonne);
	nim_jouer_tour(plateau, nb_colonnes, choix_colonne, choix_pieces);
}