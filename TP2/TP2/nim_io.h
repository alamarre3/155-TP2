#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>

/*=====MODULE NIM_IO======
Ce module inclut les fonctions assurant l’interactivité du jeu avec
l’usager. Il comprend les fonctions permettant de gérer le jeu (alterner entre les joueurs), de demander
à l’usager de saisir les données nécessaires, et de mettre à jour l’état du plateau du jeu au fur et à
mesure. Les fonctions de ce module feront souvent appel aux fonctions du module « nim » ainsi qu’aux
fonctions du module « nim_ihm » décrit ci-dessous.*/


/* Fonction lire_entier
	Description : Demande à l'usager de saisir un entier entre les bornes min et max
	(inclusivement). La fonction doit valider la saisie et redemander à l'usager
	de saisir une valeur jusqu'à l'obtention d'une valeur satisfaisante.
	Paramètres :
		- min (entier) : borne minimale
		- max (entier) : borne maximale
	Sortie :
		- Pour une valeur saisie incorrecte, la fonction affiche l'erreur et renvoie la valeur de -1.
		Pour une valeur saisie valide, la fonction renvoie la valeur saisie.*/

int lire_entier(int min, int max);

/* Fonction plateau_afficher
	Description : Affiche la configuration du plateau à l'écran. Elle affiche chacune des
	colonnes en mettant une pièce par ligne, selon le nombre de pièces présentes
	dans la colonne en question.
	Paramètres :
		- plateau (const entier) : plateau de jeu
		- nb_colonnes (entier) : nombre de colonnes utilisés par le jeu
	Sortie :
		- aucune
*/

void plateau_afficher(const int plateau[], int nb_colonnes);

/* Fonction tour_humain
	Description : Déclenche le tour de l'humain en demandant à l'usager de choisir la colonne
	(appel à ihm_choisir_colonne) et le nombre de pièces à retirer du plateau de
	jeu. Une fois le choix effectué, la fonction doit faire appel à
	nim_jouer_tour pour appliquer les changements au plateau.
	Paramètres :
		- plateau (entier) : plateau de jeu actuel
		- nb_colonnes (entier) : nb_colonne du plateau de jeu actuel
	Sortie :
		- aucune */

void tour_humain(int plateau[], int nb_colonnes);

/* Fonction tour_ia
	Description : Déclenche le tour de l'ordinateur. Pour connaitre le choix de l'ordinateur,
	on faisant appel à la fonction nim_choix_ia. Une fois le choix effectué, la fonction
	doit faire appel à nim_jouer_tour pour appliquer les changements au plateau.
	Paramètres :
		- plateau (entier) : plateau de jeu actuel
		- nb_colonnes (entier) : Nombres de colonnes du plateau de jeu
		- difficulte (double) : niveau de difficulté de l'ordinateur
	Sortie :
		- aucune */

void tour_ia(int plateau[], int nb_colonnes, double difficulte);
