/********************************************************************/
/*					Fichier     :	Examen de mi-session 2			*/
/*					Créateur	:	Jérôme WILLIG					*/
/*																	*/
/*																	*/
/*																	*/
/*																	*/
/********************************************************************/
#define _CRT_SECURE_NO_WARNINGS

/********************************************************************/
/*					 	 	  LIBRAIRIES						    */
/********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/********************************************************************/
/*					 	 	  CONSTANTES						    */
/********************************************************************/


#define TAILLE_GRILLE 3


/********************************************************************/
/*				  	  FONCTIONS	PROTOTYPE						    */
/********************************************************************/


void afficher_tic_tac_toe(char** tab);
int verifier_victoire(char** tab, char car);
int num_valid();

/********************************************************************/
/*				  	  MAIN										    */
/********************************************************************/

int main(void) {

	int i, j, l;
	int cpt;
	int ligne, colonne;

	/* Allocation de NBLIG pointeurs (int *)  */
	char** tab = (char**)malloc(TAILLE_GRILLE * sizeof(char*));

	for (l = 0; l < TAILLE_GRILLE; l++) {
		tab[l] = calloc(3, sizeof(char));
	}

	/*
	tab[0][0] = 'O';
	tab[0][1] = 'X';
	tab[0][TAILLE_GRILLE-1] = 'X';

	tab[1][0] = 'X';
	tab[1][1] = 'O';
	tab[1][TAILLE_GRILLE-1] = 'X';

	tab[TAILLE_GRILLE-1][0] = 'X';
	tab[TAILLE_GRILLE - 1][1] = 'O';
	tab[TAILLE_GRILLE - 1][TAILLE_GRILLE-1] = 'O';
	*/

	printf("Bienvenu dans le TicTacGed, Amusez-vous Bien !\n");
	printf("Les lignes et colonnes vont de 0 a 2 !\n");
	printf("Appuyez sur une touche pour commencer :)");
	_getch();
	system("cls");


	for (i = 0; i < TAILLE_GRILLE; i++)
	{
		for (j = 0; j < TAILLE_GRILLE; j++)
		{
			tab[i][j] = ' ';
		}
	}
	cpt = 0;

	while (cpt != TAILLE_GRILLE * TAILLE_GRILLE)
	{
		do 
		{
		printf("Joueur O entrez la ligne ou mettre votre charactere\n");
		ligne = num_valide();
		printf("Joueur O entrez la colonne ou mettre votre charactere\n");
		colonne = num_valide();
		system("cls");
		afficher_tic_tac_toe(tab);
		} while (tab[ligne][colonne] == 'O' || tab[ligne][colonne] == 'X');

	tab[ligne][colonne] = 'O';
	cpt++;

	if (verifier_victoire(tab, 'O') || verifier_victoire(tab, 'X')) 
		break;
	system("cls");
	afficher_tic_tac_toe(tab);

	do
	{
		printf("Joueur X entrez la ligne ou mettre votre charactere\n");
		ligne = num_valide();
		printf("Joueur X entrez la colonne ou mettre votre charactere\n");
		colonne = num_valide();
		system("cls");
		afficher_tic_tac_toe(tab);
	} while (tab[ligne][colonne] == 'O' || tab[ligne][colonne] == 'X');

	tab[ligne][colonne] = 'X';
	cpt++;
	if (verifier_victoire(tab, 'O') || verifier_victoire(tab, 'X'))
		break;
	system("cls");
	afficher_tic_tac_toe(tab);
	}
	system("cls");
	afficher_tic_tac_toe(tab);

	
	if (verifier_victoire(tab, 'O'))
		printf("\nLe joueur O gagne, Bravo !\n");
	if (verifier_victoire(tab, 'X'))
		printf("\nLe joueur X gagne, Bravo !\n");
	else if (cpt == TAILLE_GRILLE * TAILLE_GRILLE && (verifier_victoire(tab, 'O') || verifier_victoire(tab, 'X')))
		printf("\nMatch nul ! Bien joue a vous deux \n");

	/* Pour chaque ligne, on doit libérer la mémoire allouée */
	for (i = 0; i < TAILLE_GRILLE; i++)
		free(tab[i]);

	free(tab);    //libérer mémoire allouée par le premier malloc

	return EXIT_SUCCESS;
}

/********************************************************************/
/*				  	  FONCTIONS									    */
/********************************************************************/

void afficher_tic_tac_toe(char** tab) {

	int i, j;

	for (i = 0; i < TAILLE_GRILLE; i++) {
		for (j = 0; j < TAILLE_GRILLE; j++)
		{
			printf("%c  ", tab[i][j]);
		}
		printf("\n");
	}
}

int verifier_victoire(char** tab, char car) {
	int i, j, cpt;
	cpt = 0;

	for (i = 0; i < TAILLE_GRILLE; i++) {
		if (cpt == TAILLE_GRILLE)
			return 1;
		cpt = 0;
		for (j = 0; j < TAILLE_GRILLE; j++)
		{
			if (tab[i][j] == car)
				cpt++;
		}

	}

	for (j = 0; j < TAILLE_GRILLE; j++) {
		if (cpt == TAILLE_GRILLE)
			return 1;
		cpt = 0;
		for (i = 0; i < TAILLE_GRILLE; i++)
		{
			if (tab[i][j] == car)
				cpt++;
		}

	}

	if (tab[0][0] == car)
		if (tab[1][1] == car)
			if (tab[TAILLE_GRILLE - 1][TAILLE_GRILLE - 1] == car)
				return 1;

	if (tab[2][0] == car)
		if (tab[1][1] == car)
			if (tab[TAILLE_GRILLE - 1][TAILLE_GRILLE - 1] == car)
				return 1;

	return 0;

}

int num_valide() 
{
	int n;
	do
	{
		scanf("%d", &n);
	} while (n < 0 || n > TAILLE_GRILLE);

	return n;
}