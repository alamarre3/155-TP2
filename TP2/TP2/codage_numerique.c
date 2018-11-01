
#include"nim.h"
#include"codage_numerique.h"


int codage_dec2bin(int nombre, int resultat[]) {

	//déclaration de variables.
	int i;
	int nb_bits=0;

	for (i = 0; i < CODAGE_NB_BITS; i++) {

		if (nombre >= EXPOSANT_BITS / pow(2,i)) {
			resultat[i] = 1;
			nombre -= EXPOSANT_BITS / pow(2, i);

			if (CODAGE_NB_BITS - i > nb_bits) {
				nb_bits = CODAGE_NB_BITS - i;
			}
		}
		else {
			resultat[i] = 0;
		}
	}
	return nb_bits;
}

void codage_afficher_tab_bits(const int tab_bits[], int nb_bits){

	//déclaration de variables.
	int i;

	for (i = 0; i < CODAGE_NB_BITS - 1; i++) {
		printf("%d ", tab_bits[i]);
	}
}

int codage_bin2dec(const int tab_bits[]) {

	//déclaration de variables.
	int i;
	int nb_dec = 0;

	for (i = 0; i < CODAGE_NB_BITS ; i++) {

		if (tab_bits[i] == 1) {
			nb_dec += EXPOSANT_BITS / pow(2, i);
		}
}
	return nb_dec;
}