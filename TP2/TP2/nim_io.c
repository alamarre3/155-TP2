/*=====MODULE NIM_IO======*/

#include "nim_io.h"

// Fonction lire_entier

int lire_entier(int min, int max) {

	// Déclaration des variables
	int entier; // Valeur d'un entier saisi par l'usage


	scanf("%d", &entier);
	if (entier >= min && entier <= max) {
		return entier;
	}
	else {
		printf("Valeur saisie non valide, veuillez saisir une valeur dans l'intervalle %d et %d.\n", min, max);
		return -1;
	}

}

// Fonction plateau_afficher
 
void plateau_afficher(const int plateau[], int nb_colonnes) {


}

