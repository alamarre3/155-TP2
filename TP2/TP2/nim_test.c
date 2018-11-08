// ===== MODULE TEST pour les fonction de NIM.C =====
#include "nim_test.h"
#include "codage_numerique.h"

// Test de la fonction plateau_init

void nim_test_plateau_init() {

	// D�claration de variables
	int i; // Variable d'incr�mentation
	int plateau[BORNE_TAB]; // Plateau de jeu pour le test
	int nb_colonnes = BORNE_TAB; // Nombre de colonnes du tableau

	nim_plateau_init(plateau, nb_colonnes);

	for (i = 0; i < nb_colonnes; i++) {
		assert(plateau[i] >= 1 && plateau[i] <= 35);
	}
}

// Test de la fonction nim_qui_commence

void nim_test_qui_commence(void) {

	// D�claration de variables
	int personne; // Chiffre d�cidant qui commence la partie

	personne = nim_qui_commence();

	assert(personne == 0 || personne ==1);
}

// Test de la fonction jouer_tour

void nim_test_jouer_tour() {

	// D�claration des variables
	int plateau[BORNE_TAB]; // Plateau de test
	int colonne ; // Variable du choix de la colonne
	int nb_pieces; // Variable du nombre de pi�ces
	int nb_colonnes = BORNE_TAB; // Nombre de colonnes du plateau
	
	nim_plateau_init(plateau, BORNE_TAB);
	nb_pieces = plateau[7];
	colonne = 7;
	
	nim_jouer_tour(plateau, nb_colonnes, colonne, nb_pieces);
	
	assert(plateau[colonne]==0);
}

// Test de la fonction plateau_supprimer_colonne

void nim_test_plateau_supprimer_colonne() {

	// D�claration des variables
	int plateau[BORNE_TAB]; // Plateau de jeu
	int col_a_supprimer = 0; // Variable pour la colonne � supprimer
	int i; // Variable d'incr�mentation
	int nb_colonnes = 2; // Variable utilis�e pour le nombre de colonnes

	nim_plateau_init(plateau, nb_colonnes);
	nim_plateau_supprimer_colonne(plateau, nb_colonnes, col_a_supprimer);
	
	assert(plateau[col_a_supprimer]==plateau[col_a_supprimer+1]);
}

// Test de la fonction plateau_defragmenter

void nim_test_plateau_defragmenter() {

	// D�claration des variables
	int i; // Variable d'incr�mentation
	int plateau[BORNE_TAB]; // Plateau de jeu
	int nb_colonnes = BORNE_TAB; // Nombre de colonnes du plateau de jeu

	nim_plateau_init(plateau, BORNE_TAB);
	plateau[6] = 0;
	nb_colonnes = nim_plateau_defragmenter(plateau, nb_colonnes);

	assert(nb_colonnes==19);
}

// Test de la fonction nim_choix_ia_aleatoire

void nim_test_choix_ia_aleatoire() {

	// D�claration des variables
	int plateau[BORNE_TAB]; // Plateau du jeu
	int choix_colonne; // Choix de la colonne o� enlever les pi�ces
	int choix_nb_pieces; // Choix du nombre de pi�ces � enlever
	int *ptr_choix_colonne = &choix_colonne; // Pointeur de choix_colonne
	int *ptr_choix_nb_pieces = &choix_nb_pieces; // Pointeur de choix_nb_pieces
	int nb_colonnes = BORNE_TAB; // Nombre de colonnes du plateau de jeu

	nim_plateau_init(plateau, nb_colonnes);
	nim_choix_ia_aleatoire(plateau, nb_colonnes, ptr_choix_colonne, ptr_choix_nb_pieces);

	assert(plateau[choix_colonne] >= *ptr_choix_nb_pieces);
	assert(*ptr_choix_colonne <= BORNE_TAB);
}

// Test de la fonction nim_construire_mat_binaire

void nim_test_construire_mat_binaire() {

	// D�claration des variables
	int plateau[1] = { 22 }; // Plateau de jeu pour le test
	int matrice[1][CODAGE_NB_BITS]; // Matrice binaire
	int nb_colonnes = 1; // Nombre de colonnes du plateau de jeu

	nim_construire_mat_binaire(plateau, nb_colonnes, matrice);
	
	assert(codage_bin2dec(matrice) == 22);
}

// Test de la fonction nim_sommes_mat_binaire

void nim_test_sommes_mat_binaire() {

	// D�claration des variables
	int matrice[4][CODAGE_NB_BITS] = { { 1 }, { 1 }, { 0 }, { 1 } }; // Matrice binaire de test
	int nb_lignes = 4; // Nombre de lignes de la matrice
	int sommes[CODAGE_NB_BITS]; // R�sultat de la somme de la matrice
	int i; // Variable d'incr�mentation
	int j; // Variable d'incr�mentation

	nim_sommes_mat_binaire(matrice, nb_lignes, sommes);

	assert(sommes[0] == 3);
}

// Test de la fonction nim_position_premier_impaire

void nim_test_position_premier_impaire() {

	// D�claration des variables
	int tab[CODAGE_NB_BITS] = { 4,4,4,4,4,4,4,4 }; // Tableau de position pour le test
	int i; // Variable d'incr�mentation
	int indice; // Variable retourn�e en cas d'erreur

	tab[4] = 3;
	indice = nim_position_premier_impaire(tab);
	assert(indice == 4);

	tab[4] = 2;
	indice = nim_position_premier_impaire(tab);
	assert(indice == -1);
}

// Test de la fonction nim_choix_ia

void nim_test_choix_ia() {

	// D�claration de variables
	int plateau[BORNE_TAB]; // Plateau de jeu pour le test
	int nb_colonnes = BORNE_TAB; // Nombre de colonnes du plateau
	double difficulte = 0; // Difficult� de l'ia (non utilis�e dans le test)
	double resultat; // Variable pour le test
	int choix_colonne; // Choix de la colonne o� enlever les pi�ces
	int choix_nb_pieces; // Choix du nombre de pi�ces � enlever
	int *ptr_choix_colonne = &choix_colonne; // Pointeur de choix_colonne
	int *ptr_choix_nb_pieces = &choix_nb_pieces; // Pointeur de choix_nb_pieces

	nim_plateau_init(plateau, nb_colonnes);
	nim_choix_ia(plateau, nb_colonnes, 1, ptr_choix_colonne, ptr_choix_nb_pieces);
	assert(choix_colonne <= BORNE_TAB || choix_nb_pieces <= BORNE_PIECE);

	nim_choix_ia(plateau, nb_colonnes, 2, ptr_choix_colonne, ptr_choix_nb_pieces);
	assert(choix_colonne <= BORNE_TAB || choix_nb_pieces <= BORNE_PIECE);

	nim_choix_ia(plateau, nb_colonnes, 3, ptr_choix_colonne, ptr_choix_nb_pieces);
	assert(choix_colonne <= BORNE_TAB || choix_nb_pieces <= BORNE_PIECE);
}

// Fonction pour lancer tous les test

void nim_test() {
	nim_test_plateau_init();
	nim_test_qui_commence();
	nim_test_jouer_tour();
	nim_test_plateau_supprimer_colonne();
	nim_test_choix_ia_aleatoire();
	nim_test_construire_mat_binaire();
	nim_test_sommes_mat_binaire();
	nim_test_position_premier_impaire();
	nim_test_choix_ia();
}