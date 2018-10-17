#include "nim_ihm.h"


#define IHM_LARGEUR_ECRAN 140 //Largeur maximale de l'écran en nombre de caractères
#define IHM_HAUTEUR_ECRAN 40 //Hauteur maximale de l'écran en nombre de caractères
#define IHM_PLATEAU_MAX_LARGEUR (IHM_LARGEUR_ECRAN/2 - 2) //Moitié de l'écran - 2 pour les lignes 
#define IHM_PLATEAU_MAX_HAUTEUR (IHM_HAUTEUR_ECRAN - 3) //Hauteur de l'écran -2 pour les lignes -1 pour texte en haut.
#define IHM_PLATEAU_DECAL_LIGNE 3 //Décalage de la première ligne par rapport au haut du plateau de jeu
#define IHM_PLATEAU_DECAL_COLONNE 3 //Décalage de la première colonne par rapport à la gauche du plateau de jeu
#define IHM_PLATEAU_LARGEUR_COLONNE 3 //Largeur d'une colonne dans le plateau de jeu
//Nombre max de colonnes: la largeur totale -2 pour les coordonnées des lignes / largeur d'une colonne
#define IHM_PLATEAU_MAX_COLONNES ((IHM_PLATEAU_MAX_LARGEUR - IHM_PLATEAU_DECAL_COLONNE) / IHM_PLATEAU_LARGEUR_COLONNE)
#define IHM_PLATEAU_MAX_LIGNES (IHM_PLATEAU_MAX_HAUTEUR - IHM_PLATEAU_DECAL_LIGNE)

#define IHM_COLEUR_NORMALE 1 //Couleur blanc sur fond noir
#define IHM_COULEUR_SURLIGNEE 2 //Couleur blanc sur fond jaune
#define IHM_COULEUR_MESSAGE 3 //Couleur rouge sur fond blanc

//Message d'aide affiché pour la sélection de colonne par l'usager.
#define IHM_MESSAGE_SELECTION_COLONNE "<- -> <ESPACE>: Changer la selection   <ENTREE>: Valider"


/******************************
* Variables privées du module *
*******************************/
//Références vers les zones de l'interface graphique
WINDOW *plateau_jeu;
WINDOW *zone_texte;

//Taille du plateau de jeu en lignes et colonnes. Initialement -1 pour "non-défini"
int nb_lignes = -1;
int nb_colonnes = -1;

/******************************
* Fonctions privées du module *
*******************************/
/*
IHM_AFFICHER_COORDS_PLATEAU
Affiche les coordonnées (indices de lignes et colonnes) sur le plateau du jeu.
*/
void ihm_afficher_coords_plateau(WINDOW *plateau);

/*
IHM_SURLIGNER
Surligne la colonne "colonne" ou déactive le surlignage, selon la valeur du 
paramètre booléen "on".
*/
void ihm_surligner(int colonne, int on);

/*
IHM_AFFICHER_ENTETE
Affiche le message dans la zone de titre, typiquement "Jeu de NIM".
*/
void ihm_afficher_entete(WINDOW *fenetre);

/*
IHM_VERIFIER_TAILLE_PLATEAU
Vérifie que les valeurs lignes et colonnes sont des valeurs valides
pour la taille d'un plateau de jeu.
*/
int ihm_verifier_taille_plateau(int lignes, int colonnes);

/*
IHM_EFFACER_PLATEAU
Efface le contenu du plateau de jeu. 
*/
void ihm_effacer_plateau(void);

/*
IHM_CREER_FENETRE
Crée une fenêtre virtuelle de hauteur*largeur à la position (debut_y,debut_x).
Si contour est Vrai, une bordure est dessinée autour de la fenêtre.
*/
WINDOW *ihm_creer_fenetre(int hauteur, int largeur, int debut_y, int debut_x, int contour);


/**********************************************
Définition des fonctions publiques et privées
***********************************************/

//Initialise la console en mode ncurses, dessine les 3 zones et définit le nombre de lignes
//et colonnes du plateua de jeu.
int ihm_init_ecran(int lignes, int colonnes)
{
	WINDOW *fenetre_entete; //Fenetre dans laquelle on affiche le titre du jeu.

	initscr();										   //Initialise ncurses
	resize_term(IHM_HAUTEUR_ECRAN, IHM_LARGEUR_ECRAN); //Redimentionnement du terminal

	cbreak(); //Désactive le buffer de saisie
	
	if (lignes == 0 && colonnes == 0) {
		lignes = 35;
		colonnes = 20;
	}

	//Initialisation des dimensions du plateau de jeu après vérification de la validité
	//des valeurs
	if (!ihm_verifier_taille_plateau(lignes, colonnes))
	{
		endwin();
		printf("La taille du plateau de jeu n'est pas valide."
			" (Permis: 0..%d lignes et 0..%d colonnes)\n",
			IHM_PLATEAU_MAX_LIGNES + 1,
			IHM_PLATEAU_MAX_COLONNES + 1);
		return FALSE;
	}
	nb_lignes = lignes; 
	nb_colonnes = colonnes;

	if (has_colors() == FALSE)
	{
		endwin();
		printf("Désolé, votre terminal ne permet pas les couleurs. \n");
		return FALSE;
	}
	start_color();

	//On déclare les paires de couleurs utilisées dans l'interface
	init_pair(IHM_COLEUR_NORMALE, COLOR_WHITE, COLOR_BLACK);
	init_pair(IHM_COULEUR_SURLIGNEE, COLOR_WHITE, COLOR_YELLOW);
	init_pair(IHM_COULEUR_MESSAGE, COLOR_RED, COLOR_WHITE);

	//Création de la fenetre entête
	fenetre_entete = ihm_creer_fenetre(4, 70, 0, 0, TRUE);
	ihm_afficher_entete(fenetre_entete);

	//Création et configuration de la zone de texte
	zone_texte = ihm_creer_fenetre(34, 68, 5, 1, FALSE);
	scrollok(zone_texte, TRUE);

	//Création et configuration de la zone du plateau de jeu
	plateau_jeu = ihm_creer_fenetre(40, 70, 0, 70, TRUE);
	keypad(plateau_jeu, TRUE);
	ihm_afficher_coords_plateau(plateau_jeu);

	refresh();

	return TRUE;
}

//Retourne vrai si la taille du plateau est valide. 
int ihm_verifier_taille_plateau(int lignes, int colonnes)
{
	//lignes doit être entre [0..IHM_PLATEAU_MAX_LIGNES]
	//colonnes doit être dans [0..IHM_PLATEAU_MAX_COLONNES]
	if (lignes < 0 ||
		lignes > IHM_PLATEAU_MAX_LIGNES + 1 ||
		colonnes < 0 ||
		colonnes>IHM_PLATEAU_MAX_COLONNES + 1) {
		return FALSE;
	}
	return TRUE;
}

//Modifie la taille du plateau de jeu (après l'avoir initialisé
int ihm_changer_taille_plateau(int lignes, int colonnes)
{
	//Si taille invalide, on affiche un message d'erreur et on retourne faux.
	if (!ihm_verifier_taille_plateau(lignes, colonnes))
	{
		wprintw(zone_texte, "ERREUR dans la fonction ihm_changer_taille_plateau:\n La taille du plateau de jeu n'est pas valide."
			" (Permis: 0..%d lignes et 0..%d colonnes)\n",
			IHM_PLATEAU_MAX_LIGNES + 1,
			IHM_PLATEAU_MAX_COLONNES + 1);
		return FALSE;
	}

	//Sinon on change la taille et on redessine le plateau.
	nb_lignes = lignes;
	nb_colonnes = colonnes;

	ihm_effacer_plateau();

	if(nb_lignes && nb_colonnes)
		ihm_afficher_coords_plateau(plateau_jeu);


	return TRUE;
}

//Efface le contenu du plateau de jeu.
void ihm_effacer_plateau(void)
{
	//On efface tout, puis on re-dessine la bordure.
	wclear(plateau_jeu);
	box(plateau_jeu, 0, 0);
	wrefresh(plateau_jeu);
}


//Affiche le nom du jeu dans la zone de titre
void ihm_afficher_entete(WINDOW *fenetre)
{
	mvwprintw(fenetre, 2, 1, "                              JEU DE NIM                     ");
	wrefresh(fenetre);
}

//Accesseur de la variable privée zone_texte
WINDOW* ihm_get_zone_texte() {
	return zone_texte;
}

//Crée une fenêtre dans la console aux dimensions spécifiées, éventuellement avec un contour déssiné
WINDOW *ihm_creer_fenetre(int hauteur, int largeur, int debut_y, int debut_x, int contour)
{
	WINDOW *fenetre;

	fenetre = newwin(hauteur, largeur, debut_y, debut_x);
	if(contour) 
		box(fenetre, 0, 0);	 //Dessine une bordure autour de la fenêtre
	wrefresh(fenetre);		//Et on affiche les changements

	return fenetre;
}

//Ajoute une pièce sur le plateau du jeu
int ihm_ajouter_piece(int ligne, int colonne)
{

	if (ligne  > nb_lignes || colonne > nb_colonnes)
		return 0;
	colonne = (colonne+1)*IHM_PLATEAU_LARGEUR_COLONNE;
	mvwprintw(plateau_jeu, ligne+ IHM_PLATEAU_DECAL_LIGNE, colonne-1+IHM_PLATEAU_DECAL_COLONNE, "*");
	wrefresh(plateau_jeu);
	return 1;
}

//Affiche les nums. de ligne et de colonne du plateau de jeu
void ihm_afficher_coords_plateau(WINDOW *plateau)
{
	int i;
	//Affichage des nums de colonnes
	wmove(plateau, IHM_PLATEAU_DECAL_LIGNE-1, IHM_PLATEAU_DECAL_COLONNE);
	for (i = 0; i < nb_colonnes; i++)
	{
		wprintw(plateau, "%*d", IHM_PLATEAU_LARGEUR_COLONNE, i );
	}
	//Affichage des num de ligne
	for (i = 0; i < nb_lignes; i++)
	{
		mvwprintw(plateau, i+IHM_PLATEAU_DECAL_LIGNE, 1 , "%*d",2,i);
	}
	wrefresh(plateau_jeu);
}

//Met une colonne du plateau de jeu en surbrillance
void ihm_surligner(int colonne, int on) 
{
	int i;
	int couleur; 

	colonne = (colonne+1)*IHM_PLATEAU_LARGEUR_COLONNE;

	//si on est vrai, on surligne. Sinon, on rétablit la couleur normale.
	couleur = on ? IHM_COULEUR_SURLIGNEE : IHM_COLEUR_NORMALE;

	//On doit surligner chaque caractère de la colonne, ligne par ligne
	for (i = 0; i <= IHM_PLATEAU_MAX_LIGNES; i++)
	{
		mvwchgat(plateau_jeu, i+IHM_PLATEAU_DECAL_LIGNE, colonne + IHM_PLATEAU_DECAL_COLONNE-2, 3, 0, couleur, NULL);
	}

	//On montre les changements à l'écran
	wrefresh(plateau_jeu);
}

//Permet de choisir une colonne du plateau de jeu avec les touches flèchées
int ihm_choisir_colonne(void)
{
	char ch;
	int colonne_courante = 0;

	if (!nb_colonnes || nb_colonnes == -1  || nb_lignes == -1)
		return -1;
	
	//On désactive le mode echo: ne pas afficher les lettres saisies au clavier
	noecho(); 
	//On met en surbrillance la colonne 0
	ihm_surligner(colonne_courante, TRUE);

	//Affiche le message d'instructions
	wattron(plateau_jeu, COLOR_PAIR(IHM_COULEUR_MESSAGE));
	mvwprintw(plateau_jeu, 1, 3, "%s", IHM_MESSAGE_SELECTION_COLONNE);
	wattroff(plateau_jeu, COLOR_PAIR(IHM_COULEUR_MESSAGE));

	while ((ch = wgetch(plateau_jeu)) != '\n')
	{
		switch (ch)
		{
		case '\x4': 
		case KEY_LEFT: //On désactive la surbrillance et on change la colonne courante
			ihm_surligner(colonne_courante, FALSE); 
			colonne_courante--; 
			break;
		case '\x5':
		case ' ':
		case KEY_RIGHT: //Idem touche gauche
			ihm_surligner(colonne_courante, FALSE);  
			colonne_courante++;
			break;
		}
		//Rotation de la colonne courante si on est avant la 1ere colonne ou après la dernière
		colonne_courante = colonne_courante < 0 ? nb_colonnes - 1: colonne_courante;
		colonne_courante = colonne_courante >= nb_colonnes ? 0 : colonne_courante;

		//On met la nouvelle colonne courante en surbrillance
		ihm_surligner(colonne_courante, TRUE);
	}

	//On désactive la surbrillance et on rétablit le mode echo.
	ihm_surligner(colonne_courante, FALSE);
	echo();
	//Efface le message d'aide
	mvwprintw(plateau_jeu, 1, 3, "%*c", strlen(IHM_MESSAGE_SELECTION_COLONNE), ' ');

	wrefresh(plateau_jeu);
	return colonne_courante;
}
