#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>

/*=====MODULE NIM_IO======
Ce module inclut les fonctions assurant l�interactivit� du jeu avec
l�usager. Il comprend les fonctions permettant de g�rer le jeu (alterner entre les joueurs), de demander
� l�usager de saisir les donn�es n�cessaires, et de mettre � jour l��tat du plateau du jeu au fur et �
mesure. Les fonctions de ce module feront souvent appel aux fonctions du module � nim � ainsi qu�aux
fonctions du module � nim_ihm � d�crit ci-dessous.*/


/* Fonction lire_entier
	Description : Demande � l'usager de saisir un entier entre les bornes min et max
	(inclusivement). La fonction doit valider la saisie et redemander � l'usager
	de saisir une valeur jusqu'� l'obtention d'une valeur satisfaisante.
	Param�tres :
		- min (entier) : borne minimale
		- max (entier) : borne maximale
	Sortie :
		- Pour une valeur saisie incorrecte, la fonction affiche l'erreur et renvoie la valeur de -1.
		Pour une valeur saisie valide, la fonction renvoie la valeur saisie.*/

int lire_entier(int min, int max);

/* Fonction plateau_afficher
	Description : Affiche la configuration du plateau � l'�cran. Elle affiche chacune des
	colonnes en mettant une pi�ce par ligne, selon le nombre de pi�ces pr�sentes
	dans la colonne en question.
	Param�tres :
		- plateau (const entier) : plateau de jeu
		- nb_colonnes (entier) : nombre de colonnes utilis�s par le jeu
	Sortie :
		- aucune
*/

void plateau_afficher(const int plateau[], int nb_colonnes);

/* Fonction tour_humain
	Description : D�clenche le tour de l'humain en demandant � l'usager de choisir la colonne
	(appel � ihm_choisir_colonne) et le nombre de pi�ces � retirer du plateau de
	jeu. Une fois le choix effectu�, la fonction doit faire appel �
	nim_jouer_tour pour appliquer les changements au plateau.
	Param�tres :
		- plateau (entier) : plateau de jeu actuel
		- nb_colonnes (entier) : nb_colonne du plateau de jeu actuel
	Sortie :
		- aucune */

void tour_humain(int plateau[], int nb_colonnes);

/* Fonction tour_ia
	Description : D�clenche le tour de l'ordinateur. Pour connaitre le choix de l'ordinateur,
	on faisant appel � la fonction nim_choix_ia. Une fois le choix effectu�, la fonction
	doit faire appel � nim_jouer_tour pour appliquer les changements au plateau.
	Param�tres :
		- plateau (entier) : plateau de jeu actuel
		- nb_colonnes (entier) : Nombres de colonnes du plateau de jeu
		- difficulte (double) : niveau de difficult� de l'ordinateur
	Sortie :
		- aucune */

void tour_ia(int plateau[], int nb_colonnes, double difficulte);
