#include <stdlib.h>
#include "nim_ihm.h"
#include "m_distributions.h"

int main(int argc, char *argv[])
{
	int choix_menu; 

	md_srand_interne();

	if (!ihm_init_ecran(0, 0)) {
		system("pause");
		return EXIT_FAILURE;
	}
	
	ihm_printf("Votre coquille du projet fonctionne convenablement. \n");
	
	ihm_pause();
	return 0;
}