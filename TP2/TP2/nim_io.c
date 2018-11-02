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
		ihm_printf("Valeur non valide.\n Veuillez saisir une valeur dans l'intervalle %d et %d.\n", min, max);
		return -1;
	}
}

// Fonction plateau_afficher
 
void plateau_afficher(const int plateau[], int nb_colonnes) {

	// Déclaration de variables
	int i, y; // Valeur d'incrémentation

	ihm_changer_taille_plateau(BORNE_PIECE, nb_colonnes);

	for (i = 0; i < nb_colonnes; i++) {

		for (y = 0; y < BORNE_PIECE; y++) {
			if (plateau[i] > y) {
				ihm_ajouter_piece(y, i);
			}
		}
	}
}

// Fonction tour_humain

void tour_humain(int plateau[], int nb_colonnes) {

	// Déclaration des variables
	int colonne; // Colonne choisi par l'usager
	int pieces = -1; // Nombre de pièces saisies par l'usager

	ihm_printf(" ===== TOUR HUMAIN =====\n");
	ihm_printf("Choisir une colonne du plateau.\n");
	colonne = ihm_choisir_colonne();
	ihm_printf("Choisir un nombre de pieces entre 1 et %d : ", plateau[colonne]);
	do {
		pieces = lire_entier(MIN_PIECES, plateau[colonne]);
	} while (pieces == -1);	
	nim_jouer_tour(plateau, nb_colonnes, colonne, pieces);
}

// Fonction tour_ia

void tour_ia(int plateau[], int nb_colonnes, double difficulte) { // Un jour Vérification des valeurs à -1

	// Déclaration des variables
	int choix_colonne; // Choix de la colonne par l'ia
	int choix_pieces; // Choix du nombre de pièces à enlever par l'ia
	int *choix_colonne_ptr = &choix_colonne; // Pointeur de la variable choix_colonne
	int *choix_pieces_ptr = &choix_pieces; // Pointeur de la variables choix_pieces

	ihm_printf(" ===== TOUR ORDINATEUR =====\n");
	nim_choix_ia(plateau, nb_colonnes, difficulte, choix_colonne_ptr, choix_pieces_ptr);
	ihm_printf("L'ordinateur retire %d pieces dans la colonne %d.\n", choix_pieces, choix_colonne);
	nim_jouer_tour(plateau, nb_colonnes, choix_colonne, choix_pieces);
}

// Fonction demarer_jeu

void demarrer_jeu(double difficulte) {

	// Déclaration des variables
	int depart = 0; // Personne qui commence
	int nb_colonnes = 0; // Nombre de colonnes choisies par l'utilisateur
	int plateau[BORNE_TAB]; // Plateau de jeu
	int *plateau_ptr = &plateau; // Pointeur du plateau de jeu
	int victore = 0; // Définit la personne qui a remporté le jeu

	ihm_printf("Nombre de colonnes desirees du plateau entre 2 et 20 : ");
	ihm_scanf("%d", &nb_colonnes);
	depart = nim_qui_commence();
	nim_plateau_init(plateau, nb_colonnes);
	plateau_afficher(plateau, nb_colonnes);
	
	if (depart == 0) {
		tour_humain(plateau, nb_colonnes);
		nb_colonnes = nim_plateau_defragmenter(plateau, nb_colonnes);
		plateau_afficher(plateau, nb_colonnes);
	}
	
	do {
		tour_ia(plateau_ptr, nb_colonnes, difficulte);
		nb_colonnes = nim_plateau_defragmenter(plateau, nb_colonnes);
		plateau_afficher(plateau, nb_colonnes);
		if (plateau[0] == 0) {
			victore = 1;
			break;
		}
		tour_humain(plateau, nb_colonnes);
		nb_colonnes = nim_plateau_defragmenter(plateau, nb_colonnes);
		plateau_afficher(plateau, nb_colonnes);
	} while (plateau[0] != 0);

	if (victore == 0) {
		ihm_printf("=== VICTOIRE DE L HUMAIN ===\n");
	}
	else {
		ihm_printf("=== VICTOIRE DE L ORDINATEUR ===\n YOU SUCKS!!!!\n");
	}
	return;
}