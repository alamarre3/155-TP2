#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include "nim_ihm.h"
#include "nim_io.h"
#include "m_distributions.h"

int main(int argc, char *argv[])
{
	double choix_menu = 0;

	md_srand_interne();

	if (!ihm_init_ecran(0, 0)) {
		system("pause");
		return EXIT_FAILURE;
	}
	
	ihm_printf("Choisir la difficulte de l'ordinateur.\n");
	ihm_printf("1- Facile\n");
	ihm_printf("2- Moyen\n");
	ihm_printf("3- Difficile\n");
	ihm_printf("4- Quittez le jeu :(\n");
	ihm_printf("Votre choix : ");
	ihm_scanf("%lf", choix_menu);
	
	demarrer_jeu(choix_menu);

	ihm_pause();
	return 0;
}