#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>

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


