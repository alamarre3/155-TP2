/*
Titre: MODULE NIM

Description: C’est le « cerveau » du programme. Inclut les fonctions nécessaires à la gestion du plateau de
jeu en mémoire et les fonctions de calcul de la stratégie de l’ordinateur. 

Auteur: Alexande Lamarre et Francis Alonzo
Date: 2018-10-19
*/

/***********COMMANDES PRÉPROCESSEUR*************/
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include "m_distributions.h"
#define BORNE_TAB 20
#define BORNE_PIECE 35

//===============déclaration pour le fichier.h================

/*Fonction nim_plateau

Initialise le plateau de jeu en remplissant les nb_colonnes d'un nombre
aléatoire de pièces entre 1 et PLATEAU_MAX_PIECES=35.

PARAMETRE(S) le tableau du jeu et le nombre de colone

SORTIES  aucun*/
void nim_plateau_init(int plateau[], int nb_colonnes);

/********************************************************************************/

/*fonction min qui commence

Fonction qui détermine, aléatoirement, qui doit jouer en premier

PARAMETRE(S) aucun

SORTIES retourne l'identifiant du joueur (JOUEUR_HUMAIN==0 ou JOUEUR_IA==1).
*/
int nim_qui_commence(void);

/********************************************************************************/

/*fonction tour

Applique des changements à la configuration du plateau de jeu en retirant
"nb_pieces" de la colonne "colonne" du plateau.
La fonction s'assure que le jeu est valide et renvoie Vrai si le jeu désiré
a pu s'appliquer à la configuration actuelle du jeu.

PARAMETRE(S) le plateau le nombre de colone du tableau, 

SORTIES retourne si la configuration de l'utilsateur est possible ou pas.
*/
int nim_jouer_tour(int plateau[], int nb_colonnes, int colonne, int nb_pieces);

/********************************************************************************/

/*fonction supprimer tableau

Supprime la colonne col_a_supprimer du plateau.

PARAMETRE(S) le plateau le nombre de colone du tableau et la colone a suprimer,

SORTIES aucun
*/
void nim_plateau_supprimer_colonne(int plateau[], int nb_colonnes, int col_a_supprimer);

/********************************************************************************/

/*fonction defragmenter.

Fonction qui supprime les colonnes vides du tableau en utilisant la fonction
nim_plateau_supprimer_colonne

PARAMETRE(S) le plateau le nombre de colone du tableau,

SORTIES le nouveau nombre de colones.
*/
int nim_plateau_defragmenter(int plateau[], int nb_colonnes);

/********************************************************************************/

/*Fonction nombre aléatroie.

Fonction qui effectue un jeu aléatoire en choisissant au hasard une colonne,
puis au hasard le nombre de pièces à jouer de cette colonne.

PARAMETRE(S) le plateau le nombre de colone du tableau et les pointeur des choix,

SORTIES aucun.
*/
void nim_choix_ia_aleatoire(const int plateau[], int nb_colonnes, int * choix_colonne, int * choix_nb_pieces);






/*Fonction nim_plateau*/
void nim_plateau_init(int plateau[], int nb_colonnes) {

	// Déclaration de variables
	int i;
	

	for (i = 0; i < nb_colonnes; i++) {
		int plateau[i] = md_randi(BORNE_PIECE);
	}
}


/*fonction nin qui commence*/
int nim_qui_commence(void) {

	// Déclaration de variables
	int personne;
	md_srand_interne();

	personne = md_randint(0, 1);

	return personne;
}


/*Fonction tour*/
int nim_jouer_tour(int plateau[], int nb_colonnes, int colonne, int nb_pieces){

	// Déclaration de variable
	int validite;

	if (plateau[colonne] - nb_pieces >= 0 && colonne > nb_colonnes) {
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


/*fonction defragmenter.*/
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


/*Fonction nombre aléatroie.*/
void nim_choix_ia_aleatoire(const int plateau[], int nb_colonnes, int * choix_colonne, int * choix_nb_pieces) {

	*choix_colonne= md_randi(nb_colonnes);

	*choix_nb_pieces= md_randi(plateau[*choix_colonne]);
}