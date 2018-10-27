

/*pour le h*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include "m_distributions.h"

int codage_inverser_tab_bits(int tab_bits[], int nb_bits); 

 /*Fonction codage dec to bin

 Traduit un nombre décimal en binaire. Le résultat est stocké dans le tableau “resultat” et le nombre de bits utilisés est renvoyé.
 Le codage du nombre décimal doit se faire en un maximum de CODAGE_NB_BITS (fixée à 8). La fonction renvoie le nombre de bits qui a 
 été nécessaire pour coder le nombre en binaire. Si le nombre requiert plus que CODAGE_NB_BITS, la fonction renvoie 0.*/

int codage_dec2bin(int nombre, int resultat[]);

int codage_dec2bin(int nombre, int resultat[]) {

	//déclaration de variables.
	int i;

	for (i = 0; i < 7; i++) {

		if (nombre >= 128 / (2 * i) || i == 0) {
			resultat[i] = 1;
			nombre -= 128 / (2 * i);
		}
		else {
			resultat[i] = 0;
		}
	}
}