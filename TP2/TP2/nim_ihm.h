/*
MODULE NIM_IHM

Module qui définit l'interface homme-machine du jeu de nim. Ce module 
repose sur la librairie ncurses et subdivise l'écran en 3 zones: 
- La zone de titre (qui affiche "Jeu de NIM")
- La zone de plateau, qui affiche les pièces réparties sur des colonnes
- La zone console, où sont faits les affichages et les lectures au clavier.

Le module comporte des fonctions et des macros fontions permettant au programmeur
de faire abstraction de l'interface usager. Les principales sont: 

- ihm_init_ecran: Initialise l'interface (les 3 zones d'affichage)
- int ihm_changer_taille_plateau: spécifie le nombre de lignes et de colonnes du plateau
  de jeu.
- ihm_ajouter_piece: Ajoute une pièce sur le plateau de jeu, à l'endroit désiré
- ihm_choisir_colonne: Fait choisir à l'usager une colonne, en utilisant les touches
  flèchées.
- ihm_effacer_plateau: Efface le plateau de jeu.
- ihm_printf: Affiche une chaine formatée (à la printf) dans la console de NIM
- ihm_scanf: Lit une valeur depuis la console de NIM (à la scanf)
- ihm_effacer_ecran: Efface le contenu de la console de NIM
- ihm_pause: Interrompe l'exécution du programme jusqu'à ce que l'usager presse
  sur une touche.
*/
#ifndef IHM_H_
#define IHM_H_

#include "curses.h"
#include <string.h>

/*
* MACRO_FONCTIONS
*/

/*
IHM_PRINTF (macro-fonction)
Fonction équivalente à printf, à utiliser dans l'environnement de l'interface du 
jeu de NIM. Elle affiche une chaine de caractères formatée dans la console du jeu. 
Les codes de formatage du printf (%d, %lf, etc.) peuvent être utilisés avec cette
fonction.

Paramètres:
- chaine: chaine formatée à afficher
- ...: ensemble variable de paramètres, selon ce qui est requis par chaine.
Retour: Aucun
*/
#define ihm_printf(...) wprintw(ihm_get_zone_texte(),__VA_ARGS__);wrefresh(ihm_get_zone_texte())

/*
IHM_SCANF (macro-fonction)
Fonction équivalente à scanf, à utiliser dans l'environnement de l'interface du
jeu de NIM. Elle lit une valeur depuis la console du jeu.
Les codes de formatage du scanf (%d, %lf, etc.) peuvent être utilisés avec cette
fonction.

Paramètres:
- chaine: chaine formatée spécifiant la/les valeur(s) à lire
- ...: liste de pointeurs, selon ce qui est requis par chaine.
Retour: Aucun
*/
#define ihm_scanf(...) wscanw(ihm_get_zone_texte(),__VA_ARGS__)

/*
IHM_PAUSE (macro-fonction)
Interrompe l'exécution du programme jusqu'à ce que l'utilisateur
presse sur une touche.

Paramètres: Aucun
Retour: Aucun
*/
#define ihm_pause() wgetch(ihm_get_zone_texte());

/*
IHM_EFFACER_ECRAN (macro-fonction)
Efface la zone console de l'interface usager de NIM.

Paramètres: Aucun
Retour: Aucun
*/
#define ihm_effacer_ecran() wclear(ihm_get_zone_texte());wrefresh(ihm_get_zone_texte())

/*
IHM_INIT_ECRAN
Initialise l'affichage du jeu de NIM en subdivisant l'écran en trois zones: 
	- La zone de titre
	- Le plateau de jeu ayant nb_lignes et nb_colonnes
	- La console du jeu
La fonction renvoie Faux si l'environnement ne supporte par l'affichage du jeu de
NIM. Si le nombre de lignes et de colonnes du jeu n'est pas connu, la fonction
doit être appelée avec des paramètres nuls.

Paramètres: 
nb_lignes: le nombre de lignes du plateau de jeu
nb_colonnes: le nombre de colonnes du plateau de jeu
*/
int ihm_init_ecran(int nb_lignes, int nb_colonnes);

/*
IHM_AJOUTER_PIECE
Ajoute une piece de monnaie sur le plateau de jeu à la coordonnée spécifiée. 
Les indices des coordonnées commencent à 0. La fonction vérifie que les 
coordonnées spécifiées sont valides. 

Paramètres: 
- ligne (entier): Indice de la ligne sur le plateau
- colonne (entier): Indice de la colonne sur le plateau
Retour: (entier) Vrai si la pièce a bien été placée, faux sinon. 
*/
int ihm_ajouter_piece(int ligne, int colonne);

/*
IHM_CHOISIR_COLONNE
Permet à l'utilisateur de choisir une des colonnes du plateau de jeu de façon intéractive
(en utilisant les touches fléchées). 
Note: La zone de jeu doit avoir été initialisée et le nombre de colonnes et de lignes de la
zone de jeu a été défini à une valeur non-nulle (avec ihm_init_ecran ou ihm_changer_taille_plateau).

Paramètres: Aucun
Retour (entier): La colonne choisie par l'utilisateur, ou -1 si une erreur s'est produite.
*/
int ihm_choisir_colonne(void);

/*
ÍHM_CHANGER_TAILLE_PLATEAU
Modifie le nombre de colonnes et de lignes du plateau de jeu. Le plateau de jeu
est effacé puis redessiné en conséquence.

NOTE: Le nombre de lignes et de colonnes doit être positif et ne pas excéder la 
limite définie par les constantes IHM_PLATEAU_MAX_LIGNES et 
IHM_PLATEAU_MAX_COLONNES.

Paramètres: 
lignes (entier): nouveau nombre total de lignes du plateau.
colonnes (entier): nouveau nombre total de colonnes du plateau.
Retour: (entier): Vrai si la modification a bien eu lieu. Faux sinon.
*/
int ihm_changer_taille_plateau(int lignes, int colonnes);

/*
IHM_GET_ZONE_TEXT
Fonction utilitaire qui renvoie une référence vers la zone zonsole de l'interface.
Cette fonction sert aux macro-fonctions ihm_printf, ihm_scanf et ihm_pause et ne devrait
pas être utialisée pour d'autres contextes.
Paramètres: Aucun
Retour: (WINDOWS*) Référence vers la zone console.
*/
WINDOW* ihm_get_zone_texte();

#endif