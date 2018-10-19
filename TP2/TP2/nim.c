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
#define BORNE_TAB 35

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

/*fonction min qui commence

Applique des changements à la configuration du plateau de jeu en retirant
"nb_pieces" de la colonne "colonne" du plateau.
La fonction s'assure que le jeu est valide et renvoie Vrai si le jeu désiré
a pu s'appliquer à la configuration actuelle du jeu.

PARAMETRE(S) le plateau le nombre de colone du tableau, 

SORTIES retourne si la configuration de l'utilsateur est possible ou pas.
*/
int nim_jouer_tour(int plateau[], int nb_colonnes, int colonne, int nb_pieces);

/********************************************************************************/



/*Fonction nim_plateau*/
void nim_plateau_init(int plateau[], int nb_colonnes) {

	// Déclaration de variables
	int i;
	md_srand_interne();

	for (i = 0; i < nb_colonnes; i++) {
		int plateau[i] = md_randi(BORNE_TAB);
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
int nim_jouer_tour(int plateau[], int nb_colonnes, int colonne, int nb_pieces){}