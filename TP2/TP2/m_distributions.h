/*==========================================================*/
// pour et par l'équipe  du SEG
/*==========================================================*/
/* 
	Ce module simple 

	1-) offre une interface nécessaire au générateur pseudo-aléatoire  de stdlib 

	2-) assure un accès fonctionnel  correct à diverses distributions classiques dont
		des uniformes diverses, la distribution normale et la distribution exponentielle

	3-) Les 9 fonctions présentes assurent
		l'initialisation du générateur 
			( sous 2 formes, implicite et explicite avec une valeur entière en paramètre )
		
		l'émission d'une entier dans une distribution uniforme
			( sous 2 formes, entre 1 et N  et entre deux bornes )
		
		l'émission d'une réel dans une distribution uniforme 
			( sous 2 formes, entre 0 et 1 et entre deux bornes)
		
		l'émission d'une réel dans une distribution normale 
			( sous 2 formes, dans Z (0,1) et à partir de mu et sigma)

		l'émission d'une réel dans une distribution exponentielle 
			(1 forme avec un lambda explicite)

*/
/*==========================================================*/


/*==========================================================*/

#ifndef _M_RAND_458221_H_
#define _M_RAND_458221_H_
/*==========================================================*/

#include<stdlib.h>
#include<math.h>
#include<time.h>

/*==========================================================*/

/*==========================================================*/
// un epsilon réel sert à mesurer la proximité du 0
#define EPS_DOUBLE 0.00000001


/*==========================================================*/

/* VOICI UNE INTERFACE MODULAIRE STANDARD POUR NOS ÉTUDIANTS */

/*==========================================================*/
/*  D'abord l'offre de deux fonctions d'initialisation du générateur. Un générateur 
	non-initialisé s'initialise en fait à 0 et émet la même séquence ce qui fait 
	douter du caractère aléatoire.... 
	C'est au client de l'initialiser
	MAIS JUSTE UNE FOIS dans tout le programme

	réinitialiser dans  une fonction appellée en boucle fera 
	définitivement perdre toute qualité au générateur 
	(surtout que rand de stdlib n'en a déjà pas beaucoup hs)
*/

/*==========================================================*/
/* La fonction md_srand 
 la forme d'initialisation la plus classique d'un générateur  
 à partir d'un entier quelconque, la séquence pseudo aléatoire 
 à venir est totalement déterminée par la valeur reçue en paramètre

PARAMETRE(s): s, un entier positif quelconque

SORTIE: aucune

SPECS: aucune
*/
void md_srand(unsigned int s);

/*==========================================================*/


/*==========================================================*/
/* la fonction md_srand_interne 
 une forme alternative d'initialisation du générateur à partir 
 de l'horloge interne de la machine,  l'horloge donne un entier
 qui sert de paramètre à la fonction précédente. 
 Cette valeur est retournée pour des motifs de possible reproduction
 des conditions initiales d'une simulation numérique.

PARAMETRE(s): Aucun

SORTIE: l'entier qui a véritablement initialisé le générateur

SPECS: aucune
*/
unsigned int md_srand_interne(void);
/*==========================================================*/

/* LES FONCTIONS D'ÉMISSION DANS LES DISTRIBUTIONS SPÉCIFIÉES */

/*==========================================================*/
/* La fonction md_rand   
L'émission d'un nombre réel dans la distribution uniforme 0,1 

PARAMETRE(s): Aucun

SORTIE : la valeur réelle émise dans cette distribution

SPECS : aucune
*/
double md_rand(void);
/*==========================================================*/

/*==========================================================*/
/* La fonction md_randf
L'émission d'un nombre réel dans une  uniforme [b1, b2] 

PARAMETRE(s): deux valeurs réelles quelconques qui serviront 
               de bornes à l'intervalle

SORTIE : la valeur réelle émise dans cette distribution

SPECS : l'ordre des paramètres n'a aucune importance
*/
double md_randf(double b1, double b2);
/*==========================================================*/

/*==========================================================*/
/* La fonction md_randi
L'émission d'un nombre entier  dans une uniforme[1, borne]

PARAMETRE(s): une valeur entière quelconque

SORTIE : la valeur entiere positive émise dans cette distribution

SPECS :  si le paramètre effectif est négatif, c'est sa valeur absolue
		 qui sera considérée 
		 recevant 0, retour automatique de 0 (le seul 0 possible)
*/
int md_randi(int borne);
/*==========================================================*/

/*==========================================================*/
/* La fonction md_randint
L'émission dans la distribution uniforme obtenue des deux paramètres

PARAMETRE(s) : les deux valeurs entières quelconques  servent 
               de bornes à l'intervalle

SORTIE : la valeur entiere émise dans cette distribution

SPECS :peu importe l'ordre des paramètres
*/
int md_randint(int b1, int b2);
/*==========================================================*/

/*==========================================================*/
/* La fonction md_randZ
L'émission d'un nombre réel dans la distribution normale Z,
	la plus classique  de moyenne 0 et d'écart type 1

PARAMETRE(s) : Aucun

SORTIE : la valeur réelle émise dans cette distribution

SPECS : celle-ci a une parité d'émission
	ce qui peut déconcerter si on réinitialise le générateur
	en cours d'exécution de la simulation ( ce qui en réalité ne doit JAMAIS être fait)
*/
double md_randZ(void);
/*==========================================================*/
/*==========================================================*/
/* La fonction md_randnormal
L'émission d'un nombre réel dans une distribution normale quelconque, 
   de moyenne mu  et d'écart-type sigma donnés en paramètres

PARAMETRE(s) : mu définit la moyenne voulue et sigma l'écart-type

SORTIE : la valeur réelle émise dans cette distribution

SPECS : mêmes que la précédente et retour automatique de mu si sigma est négatif
*/
double md_randnormal(double mu, double sigma);

/*==========================================================*/
/*==========================================================*/
/* La fonction md_randexpo
   L'émission d'un temps d'attente dans une distribution exponentielle 
   le temps d'attente  moyen est donné par l'inverse du paramètre

PARAMETRE(s) : lambda un réel positif 

SORTIE : la valeur réelle émise dans cette distribution

SPECS : retour automatique de 0 si lambda <= 0 
*/
double md_randexpo(double lambda);
/*==========================================================*/

/*==========================================================*/
// 	C'EST FINI 
/*==========================================================*/

/*==========================================================*/
#endif	
/*==========================================================*/

