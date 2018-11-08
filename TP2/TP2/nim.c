/*=====MODULE NIM=====*/
#include "nim.h"
#include "codage_numerique.h"

// Fonction nim_plateau

void nim_plateau_init(int plateau[], int nb_colonnes) {

	// Déclaration de variables
	int i;

	for (i = 0; i < nb_colonnes; i++) {
		plateau[i] = md_randi(BORNE_PIECE);
	}
}

// Fonction nim_qui_commence

int nim_qui_commence(void) {

	// Déclaration de variables
	int personne; // Variable pour le choix

	personne = md_randint(0,1);

	return personne;
}


// Fonction nim_jouer_tour

int nim_jouer_tour(int plateau[], int nb_colonnes, int colonne, int nb_pieces){

	// Déclaration de variable
	int validite; // Variable de renvoit pour le choix

	if (plateau[colonne] - nb_pieces >= 0 && colonne < nb_colonnes) {
		plateau[colonne] -= nb_pieces;
			validite = 1;
	}
	else {
		validite = 0;
	}
	return validite;
}


// Fonction nim_plateau_supprimer_colonne

void nim_plateau_supprimer_colonne(int plateau[], int nb_colonnes, int col_a_supprimer) {

	// Déclaration des variables
	int i; // Variable d'incrémentation

	for (i = col_a_supprimer; i < nb_colonnes-1; i++) {

		plateau[i] = plateau[i + 1];
	}

	plateau[nb_colonnes] = 0;
}


// Fonction nim_plateau_defragmenter

int nim_plateau_defragmenter(int plateau[], int nb_colonnes) {

// Déclaration de variable.
	int i; // Variable d'incrémentation
	int compteur=0; // Compteur pour le nombre de colonne à retirer
	int nv_nb_colonnes; // Nouveau nombre de colonnes

	for (i = 0; i < nb_colonnes; i++) {

		if (plateau[i] == 0) {
			nim_plateau_supprimer_colonne(plateau, nb_colonnes, i);
			compteur++;
		}
	}
	nv_nb_colonnes = nb_colonnes - compteur;
	return nv_nb_colonnes;
}

// Fonction nim_choix_ia_aleatoire

void nim_choix_ia_aleatoire(const int plateau[], int nb_colonnes, int *choix_colonne, int *choix_nb_pieces) {

	*choix_colonne = md_randi(nb_colonnes)-1;
	*choix_nb_pieces = md_randi(plateau[*choix_colonne]);
	
}

// Fonction nim_construire_mat_binaire

void nim_construire_mat_binaire(const int plateau[], int nb_colonnes, int matrice[][CODAGE_NB_BITS]) {

	// Déclaration des variables
	int bit; // Variable  pour le transfert de décimal à binaire
	int i; // Variable d'incrémentation
	int j; // Variable d'incrémentation
	int temp[8]; // Tableau temporaire binaire

	for (i = 0; i < nb_colonnes; i++) {
		bit = codage_dec2bin(plateau[i], temp);

		for (j = 0; j < CODAGE_NB_BITS; j++) {
			matrice[i][j] = temp[j];
		}
	}
}

/*Fonction nim_sommes_mat_binaire*/

void nim_sommes_mat_binaire(const int matrice[][CODAGE_NB_BITS], int nb_lignes, int sommes[]) {

	// Déclaration des variables
	int i; // Variable d'incrémentation
	int j; // Variable d'incrémentation

	for (i = 0; i < CODAGE_NB_BITS; i++) {
		sommes[i] = 0;

		for (j = 0; j < nb_lignes; j++) {
			sommes[i] += matrice[j][i];
		}
	}
}

/*Fonction nim_position_premier_impaire*/

int nim_position_premier_impaire(const int tab[]) {

	// Déclaration des variables
	int i; // Variable d'incrémentation
	int indice = -1; // Variable retournée en cas d'erreur

	for (i = 0; i < CODAGE_NB_BITS; i++) {
		if (tab[i] % 2 != 0) {
			indice = i;
			break;
		}
	}
	return indice;
}

/*Fonction nim_choix_ia*/

void nim_choix_ia(const int plateau[], int nb_colonnes, double difficulte, int *choix_colonne, int *choix_nb_pieces) {

	// Déclaration de variables
	double pourcentage_borne;
	double pourcentage;
	double resultat=-1;
	int matrice[BORNE_TAB][CODAGE_NB_BITS];
	int sommes[CODAGE_NB_BITS];
	int premier_impaire=-1;
	int i;
	int temp[CODAGE_NB_BITS];

	/* si la la difficulter est a moyen, générer les valeur pour savoir si lordi utilise l'ago*/
	if (difficulte == 2) {
		pourcentage_borne = md_rand();
		pourcentage = md_rand();
		resultat= pourcentage_borne - pourcentage >= 0 ? 1 : 0;
	}

	/*effectue l'algo si la difficulte est a 3 ou si les valeur generer lus haut son positif*/
	if (difficulte == 3 || resultat==1) {

		nim_construire_mat_binaire(plateau, nb_colonnes, matrice);
		nim_sommes_mat_binaire(matrice, nb_colonnes, sommes);
		premier_impaire = nim_position_premier_impaire(sommes);
	}

	/*continue l'algo seulement si le jeu est impaire*/
	if (premier_impaire != -1 && (difficulte == 3 || resultat == 1))
	{

		/*trouver dans quelle colone jouer*/
		for (i = 0; i < nb_colonnes; i++) {

			if (matrice[i][premier_impaire] == 1) {
				*choix_colonne = i;
				break;
			}
		}

		/*inverser les bit de la colone si sa somme est impaire et transferer les bit dans un tampon*/
		for (i = 0; i < CODAGE_NB_BITS; i++) {
			if (sommes[i] % 2 != 0) {
				temp[i] = matrice[*choix_colonne][i] == 0 ? 1 : 0;
			}
			else {
				temp[i] = matrice[*choix_colonne][i];
			}
		}

		/*Convertire la valeur binaire en decimale, la soustraire au nombre present dans la colone et revoyer le nombre de jeton a enlever*/
		*choix_nb_pieces = plateau[*choix_colonne]-codage_bin2dec(temp);
	}
	/*si le choix de dificulter est a 1, que le mode moyen ne fait pas lalgo ou que le jeu est pair, effectuer aléatoirement*/
	if(difficulte==1 || premier_impaire == -1 || resultat == 0){
		*choix_colonne = md_randi(nb_colonnes) - 1;
		*choix_nb_pieces = md_randi(plateau[*choix_colonne]);
		//nim_choix_ia_aleatoire(plateau, nb_colonnes, *choix_colonne, *choix_nb_pieces);
	}
}
	



