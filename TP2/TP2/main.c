/*
Titre: TP2
Description: Ce programme implémente les divers algorithmes de tri de tableaux sur place:
le tri par sélection, le tri par insertion et le tri à bulles.

Auteur: Alexande Lamarre et Francis Alonzo
Date: 2018-10-17
*/

/***********COMMANDES PRÉPROCESSEUR*************/
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include "nim_io.h"

void main(void) {

	int max = 100;
	int min = 5;
	int entier=-1;
	do {
		printf("Saisir une valeur entre %d et %d : ", min, max);
		entier = lire_entier(min, max);
	} while (entier == -1);

	printf("Entier = %d.\n", entier);
	system("pause");
}


