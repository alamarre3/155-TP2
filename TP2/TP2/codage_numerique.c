

/*pour le h*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include "m_distributions.h"

int codage_inverser_tab_bits(int tab_bits[], int nb_bits); 

 /*Fonction codage dec to bin

 Traduit un nombre d�cimal en binaire. Le r�sultat est stock� dans le tableau �resultat� et le nombre de bits utilis�s est renvoy�.
 Le codage du nombre d�cimal doit se faire en un maximum de CODAGE_NB_BITS (fix�e � 8). La fonction renvoie le nombre de bits qui a 
 �t� n�cessaire pour coder le nombre en binaire. Si le nombre requiert plus que CODAGE_NB_BITS, la fonction renvoie 0.*/

int codage_dec2bin(int nombre, int resultat[]);

int codage_dec2bin(int nombre, int resultat[]) {

	//d�claration de variables.
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