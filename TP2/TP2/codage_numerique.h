#ifndef CODAGE_NUMERIQUE_H
#define CODAGE_NUMERIQUE_H

#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include "m_distributions.h"
#include <math.h>
#define CODAGE_NB_BITS 8
#define EXPOSANT_BITS (pow(2,CODAGE_NB_BITS-1))


 /*Fonction codage DECIMAL à BINAIRE

 Traduit un nombre décimal en binaire. Le résultat est stocké dans le tableau “resultat” et le nombre de bits utilisés est renvoyé.
 Le codage du nombre décimal doit se faire en un maximum de CODAGE_NB_BITS (fixée à 8). La fonction renvoie le nombre de bits qui a
 été nécessaire pour coder le nombre en binaire. Si le nombre requiert plus que CODAGE_NB_BITS, la fonction renvoie 0.

PARAMETRE(S) le nombre a convertir et le tableau ou stocker les bits

SORTIES  nombre de bit nessaisaire pour convertir le nombre*/

int codage_dec2bin(int nombre, int resultat[]);

/********************************************************************************/
/* Fonction Afficher tabeau

Affiche un tableau contenant des bits à l'écran. Cette fonction est utilisée pour des fins de test.

PARAMETRE(S) le tableau de bit et le nombre de bit

SORTIES  aucun*/

void codage_afficher_tab_bits(const int tab_bits[], int nb_bits);

/********************************************************************************/
/* Fonction codage dec to dec
Traduit un tableau de bits, représentant un nombre en binaire, vers sa représentation décimale.
La valeur décimale est retournée par la fonction.

PARAMETRE(S) le tableau de bit

SORTIES  la valeur en décimale*/

int codage_bin2dec(const int tab_bits[]);


#endif

