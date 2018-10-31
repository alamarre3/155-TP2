#ifndef NIM_H_
#define NIM_H_

#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include "m_distributions.h"
#define BORNE_TAB 20
#define BORNE_PIECE 35
#define MIN_PIECES 1
#define CODAGE_NB_BITS 8

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

/* Fonction nim_jouer_ia

Description : Fonction qui détermine quel doit être le jeu de l'ordinateur. Cette fonction
implémente l'algorithme décrit dans l'énoncé du TP. Le choix de l'ordinateur
sera stocké dans les références choix_colonne et choix_nb_pieces.

Paramètres :
	-
Sorties :
	- 

*/

void nim_choix_ia(const int plateau[], int nb_colonnes, double difficulte, int *choix_colonne, int *choix_nb_pieces);

/********************************************************************************/

/*Fonction nombre aléatroie.

Fonction qui effectue un jeu aléatoire en choisissant au hasard une colonne,
puis au hasard le nombre de pièces à jouer de cette colonne.

PARAMETRE(S) le plateau le nombre de colone du tableau et les pointeur des choix,

SORTIES aucun.
*/

void nim_choix_ia_aleatoire(const int plateau[], int nb_colonnes, int * choix_colonne, int * choix_nb_pieces);

/********************************************************************************/
/* Fonction construire matrice binaire

Construit la matrice binaire nécessaire à l'algorithme de choix de jeu de l'ordinateur.
Chaque ligne de la matrice correspond à une colonne du plateau de jeu et contient la représentation
binaire du nombre de pièces présentes sur la colonne en question.

PARAMETRE(S) le plateau le nombre de colone du tableau et la matrice de bit

SORTIES aucun.
*/
void nim_construire_mat_binaire(const int plateau[], int nb_colonnes, int matrice[][CODAGE_NB_BITS]);

#endif // !nim
