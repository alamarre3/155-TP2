/*
Titre: MODULE NIM

Description: C�est le � cerveau � du programme. Inclut les fonctions n�cessaires � la gestion du plateau de
jeu en m�moire et les fonctions de calcul de la strat�gie de l�ordinateur. 

Auteur: Alexande Lamarre et Francis Alonzo
Date: 2018-10-19
*/

/***********COMMANDES PR�PROCESSEUR*************/
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include "m_distributions.h"
#define BORNE_TAB 35

//===============d�claration pour le fichier.h================

/*Fonction nim_plateau

Initialise le plateau de jeu en remplissant les nb_colonnes d'un nombre
al�atoire de pi�ces entre 1 et PLATEAU_MAX_PIECES=35.

PARAMETRE(S) le tableau du jeu et le nombre de colone

SORTIES  aucun*/
void nim_plateau_init(int plateau[], int nb_colonnes);

/********************************************************************************/

/*fonction min qui commence

Fonction qui d�termine, al�atoirement, qui doit jouer en premier

PARAMETRE(S) aucun

SORTIES retourne l'identifiant du joueur (JOUEUR_HUMAIN==0 ou JOUEUR_IA==1).
*/
int nim_qui_commence(void);

/********************************************************************************/

/*fonction min qui commence

Applique des changements � la configuration du plateau de jeu en retirant
"nb_pieces" de la colonne "colonne" du plateau.
La fonction s'assure que le jeu est valide et renvoie Vrai si le jeu d�sir�
a pu s'appliquer � la configuration actuelle du jeu.

PARAMETRE(S) le plateau le nombre de colone du tableau, 

SORTIES retourne si la configuration de l'utilsateur est possible ou pas.
*/
int nim_jouer_tour(int plateau[], int nb_colonnes, int colonne, int nb_pieces);

/********************************************************************************/



/*Fonction nim_plateau*/
void nim_plateau_init(int plateau[], int nb_colonnes) {

	// D�claration de variables
	int i;
	md_srand_interne();

	for (i = 0; i < nb_colonnes; i++) {
		int plateau[i] = md_randi(BORNE_TAB);
	}
}


/*fonction nin qui commence*/
int nim_qui_commence(void) {

	// D�claration de variables
	int personne;
	md_srand_interne();

	personne = md_randint(0, 1);

	return personne;
}

/*Fonction tour*/
int nim_jouer_tour(int plateau[], int nb_colonnes, int colonne, int nb_pieces){}