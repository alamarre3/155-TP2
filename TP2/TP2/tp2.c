#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include "nim_ihm.h"
#include "nim_io.h"
#include "m_distributions.h"

int main(int argc, char *argv[])
{
	int choix_menu = 0;
	
	md_srand_interne();

	if (!ihm_init_ecran(0, 0,choix_menu)) {
		system("pause");
		return EXIT_FAILURE;
	}
	
	do {
		
			ihm_printf("Choisir la difficulte de l'ordinateur.\n");
			ihm_printf("1- Facile\n");
			ihm_printf("2- Moyen\n");
			ihm_printf("3- Difficile\n");
			ihm_printf("4- Quittez le jeu :(\n");
			ihm_printf("Votre choix : ");
			ihm_scanf("%d", &choix_menu);

			while (choix_menu < 1 || choix_menu>4){
				ihm_printf("Le choix n'est pas reconu, veulliez reessayer\n");	
				ihm_scanf("%d", &choix_menu);
			}
		

		ihm_effacer_ecran();
		ihm_init_ecran(0, 0, choix_menu);
		

		if (choix_menu >= 1 && choix_menu <= 4) {
			demarrer_jeu(choix_menu);
			ihm_pause();
			ihm_effacer_ecran();
		}

	} while (choix_menu != 4);
	return 0;
}