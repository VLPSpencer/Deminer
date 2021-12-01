#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <math.h>
#include <string.h>
#include "tp10.h"

/**
 * \file main.c
 * \brief Ensemble des fonctions apellées dans le main.c
 * \author Antonin Soulier
 * \version 1
 * \date 2 Octobre 2020
 * \param argc 2 arguments en entrée
 * \param argv aucune
 * \return 0 si tout s'est bien passé
*/

int main(int argc, char** argv){
int int_lignes;
int int_colonnes;
int int_mines;
int int_retour1;
int int_retour2;
int int_retour3;
int int_res;
int int_compte;
int_compte=0;
Reponse info;
Demineur** grille;

printf("\033[1;31m");
printf("      ---DEMINEUR--- \n");
printf("\033[0;m");
printf("\n");
printf("Combien de lignes souhaitez-vous? \n");
int_retour1 = scanf("%d", &int_lignes);
printf("Combien de colonnes souhaitez-vous? \n");
int_retour2 = scanf("%d", &int_colonnes);
if ((int_retour1 == 1) && (int_retour2 == 1))
    {
        grille = Create(int_lignes,int_colonnes);
        Display(grille, int_lignes, int_colonnes);
        printf("Combien de mines souhaitez vous ? \n");
        int_retour3 = scanf("%d", &int_mines);
        if (int_retour3 == 1)
        {
            PlaceMine(grille, int_mines, int_lignes, int_colonnes);
            Display(grille, int_lignes, int_colonnes);
            while (int_res!=1)
            {
                info = Position();
                int_res=Win(grille, info, int_lignes, int_colonnes, int_mines, int_compte);
                Display(grille, int_lignes, int_colonnes);
            }

        }else{
            printf("Nombre de mines incorrecte! \n");
        }
    }else{
        printf("Votre entrée est incorrecte! \n");
    }
}