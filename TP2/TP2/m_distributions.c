/*==========================================================*/
// pour et par l'équipe  du SEG
/*==========================================================*/

#include "m_distributions.h"

/*==========================================================*/

/* implémentation des fonctions  pour nos étudiants */
/*==========================================================*/
// STRATÉGIE 
// appel direct au srand de stdlib
void md_srand(unsigned int s){
	srand(s); 
	// obligatoire pour que le générateur de stdlib active le germe
	rand();
}
/*==========================================================*/
// STRATÉGIE 
// obtenir l'horloge interne et appel de la précédente
unsigned int md_srand_interne(void){
	unsigned int w ;
	w = (unsigned)time(NULL);
	md_srand(w);
	return w;
}
/*==========================================================*/
// STRATÉGIE 
// un exemple parfait d'usage de l'aide classique
// cet exemple est partout
double md_rand(void){
	return (1.0*rand())/(RAND_MAX + EPS_DOUBLE);
}
/*==========================================================*/
// STRATÉGIE 
// additioner à une borne une part del'écart(signé) entre les paramètres
double md_randf(double b1, double b2){
	return b1 + (md_rand()*(b2 - b1));
}
/*==========================================================*/
// STRATÉGIE 
// choisir un réel aléatoire entre 0 et borne-1
// on lui ajoute 1
int md_randi(int borne){
	borne = abs(borne);
	// j'utilise l'opérateur ? : pour résoudre borne == 0
	return borne == 0 ? 0: (int)(1 + md_rand()* borne);
}

/*==========================================================*/

int md_randint(int b1, int b2) {
	// ajouter 1 à la distance entre les bornes
	// c'est pour laisser la même chance à la borne supérieure
	double distance_plus = 1.0 + abs(b2 - b1);
	// on trouve la borne minimum
	int mini = (b1 < b2) ? b1 : b2;
	int ajout;
	// on va  ajouter au minimum une part aléatoire de cette distance_plus
	ajout = (int)(md_rand() * distance_plus);

	return  mini + ajout;
}

/*==========================================================*/
// STRATÉGIE 
/* 
    obtenu de la Marsaglia’s polar method 
    telle que décrite sur wiki
*/
double md_randZ(void) {
    // un calcul  assure la génération de deux valeurs
	static int test_regener = 1;
	static double v1;
	static double v2;
	static double w;
	static double discriminant;
	double sortie;

    // recalcul nécessaire à tous les 2 usages
	if (test_regener) {
        //boucle de controle
		do {
			v1 = md_randf(-1, 1);
			v2 = md_randf(-1, 1);
            // calcul de la valeur controlée
			w = v1*v1 + v2*v2;

		} while (w >= 1); // tant que le piont n'est pas dans le cercle de rayon 1

		discriminant = sqrt(-2 * log(w) / w);
		sortie = v1*discriminant; // premiere valeur calculée 
	}
	else {
		sortie = v2*discriminant; // seconde valeur calculée 
	}

    // passage du test aux valeurs 1,0,1,0,1,0.... successivement
	test_regener = (test_regener + 1) % 2;
	return sortie;
}/*==========================================================*/



/*==========================================================*/
// STRATÉGIE 
// obtenue d'une simple transformation linéaire de la normale Z
// consultez au besoin un cours très élémentaire de stats
double md_randnormal(double mu, double sigma){

	// j'utilise l'opérateur ? : pour résoudre si sigma <= 0
	return (sigma<=0)? mu : mu + md_randZ()*sigma;
}
/*==========================================================*/
// STRATÉGIE 
// inverser la fonction de répartition d'une distributon exponentielle
// qui n'implique qu'un exp se fait naturellement avec le log
// c'est un calcul simple et direct.
// consultez au besoin un cours très élémentaire de stats
double md_randexpo(double lambda){

	double repartition = md_rand();
	double inverse_repartition = (-log(1.0 - repartition) / lambda);
	if (inverse_repartition < EPS_DOUBLE) inverse_repartition = 0;
	// j'utilise l'opérateur ? : pour résoudre si lambda <= 0
	return (lambda <= 0) ? 0 : inverse_repartition;
}
/*==========================================================*/
// 	C'EST FINI 
/*==========================================================*/