#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <math.h>
#include <string.h>
#include "tp10.h"

Demineur** Create(int int_lignes,int int_colonnes){
Demineur** grille;
int int_i;
int int_j;
//Allocation de la mémoire requise
grille = malloc(int_lignes*sizeof(Demineur*));
for (int_i = 0; int_i < int_lignes; int_i++)
    {
        grille[int_i] = malloc(int_colonnes*sizeof(Demineur));
    }       
for (int_i = 0; int_i < int_lignes; int_i++)
    { 
        for (int_j = 0; int_j < int_colonnes; int_j++)
            {
                grille[int_i][int_j].caractere = 'O';
                grille[int_i][int_j].valeur = 0;
                grille[int_i][int_j].mine = 0;
                grille[int_i][int_j].decouvert = 0;
            }  
    }
    return(grille);
}

void Display(Demineur** grille, int int_lignes, int int_colonnes){
int int_i;
int int_j;
for (int_i = 0; int_i < int_lignes; int_i++)
    { 
        printf("|");
        for (int_j = 0; int_j < int_colonnes; int_j++)
            {
                if (grille[int_i][int_j].decouvert==1)
                {
                    if (grille[int_i][int_j].valeur!=0)
                    {
                        printf("%d|", grille[int_i][int_j].valeur);
                    }else{
                        printf("%c|", grille[int_i][int_j].caractere);
                    }
                }else{
                    printf("%c|", grille[int_i][int_j].caractere);
                }
         
            }
     printf("\n");  
    }
}

void PlaceMine(Demineur** grille, int int_mines, int int_lignes, int int_colonnes){
int int_i;
int int_posx;
int int_posy;
srand(time(NULL));

for (int_i = 0; int_i < int_mines; int_i++)
    {
        int_posx = (rand()%int_lignes);
        int_posy = (rand()%int_colonnes);
        while(grille[int_posx][int_posy].caractere == '+'){
            int_posx = (rand()%int_lignes);
            int_posy = (rand()%int_colonnes);
        } 
        //grille[int_posx][int_posy].caractere='+';
        grille[int_posx][int_posy].mine=1;
        grille[int_posx][int_posy].decouvert=0;
    }
} 

int VoisinOuest(Demineur** grille, int int_lignes, int int_colonnes, int int_x, int int_y){
    int int_res;
    if (int_y==0)
    {
        int_res=0;
    }else{
        int_res=grille[int_x][int_y-1].mine;
    }
    return(int_res);
}

int VoisinEst(Demineur** grille, int int_lignes, int int_colonnes, int int_x, int int_y){
    int int_res;
    if (int_y==int_colonnes-1)
    {
        int_res=0;
    }else{
        int_res=grille[int_x][int_y+1].mine;
    }
    return(int_res);
}

int VoisinNord(Demineur** grille, int int_lignes, int int_colonnes, int int_x, int int_y){
    int int_res;
    if (int_x==0)
    {
        int_res=0;
    }else{
        int_res=grille[int_x-1][int_y].mine;
    }
    return(int_res);
}

int VoisinSud(Demineur** grille, int int_lignes, int int_colonnes, int int_x, int int_y){
    int int_res;
    if (int_x==int_lignes-1)
    {
        int_res=0;
    }else{
        int_res=grille[int_x+1][int_y].mine;
    }
    return(int_res);
}

int VoisinNordOuest(Demineur** grille, int int_lignes, int int_colonnes, int int_x, int int_y){
    int int_res;
    if ((int_x==0) || (int_y==0))
    {
        int_res=0;
    }else{
        int_res=grille[int_x-1][int_y-1].mine;
    }
    return(int_res);
}

int VoisinNordEst(Demineur** grille, int int_lignes, int int_colonnes, int int_x, int int_y){
    int int_res;
    if ((int_x==0) || (int_y==int_colonnes-1))
    {
        int_res=0;
    }else{
        int_res=grille[int_x-1][int_y+1].mine;
    }
    return(int_res);
}

int VoisinSudOuest(Demineur** grille, int int_lignes, int int_colonnes, int int_x, int int_y){
    int int_res;
    if ((int_x==int_lignes-1) || (int_y==0))
    {
        int_res=0;
    }else{
        int_res=grille[int_x+1][int_y-1].mine;
    }
    return(int_res);
}

int VoisinSudEst(Demineur** grille, int int_lignes, int int_colonnes, int int_x, int int_y){
    int int_res;
    if ((int_x==int_lignes-1) || (int_y==int_colonnes-1))
    {
        int_res=0;
    }else{
        int_res=grille[int_x+1][int_y+1].mine;
    }
    return(int_res);
}

int CountMine(Demineur** grille, int int_lignes, int int_colonnes, int int_x, int int_y){
    int int_somme;
    int_somme=VoisinNord(grille, int_lignes, int_colonnes, int_x, int_y)+VoisinSud(grille, int_lignes, int_colonnes, int_x, int_y)+VoisinEst(grille, int_lignes, int_colonnes, int_x, int_y)+VoisinOuest(grille, int_lignes, int_colonnes, int_x, int_y)+VoisinNordOuest(grille, int_lignes, int_colonnes, int_x, int_y)+VoisinNordEst(grille, int_lignes, int_colonnes, int_x, int_y)+VoisinSudOuest(grille, int_lignes, int_colonnes, int_x, int_y)+VoisinSudEst(grille, int_lignes, int_colonnes, int_x, int_y);
    return(int_somme);
}

void UnveilNord(Demineur** grille, int int_lignes, int int_colonnes, int int_x, int int_y){

    int int_nbm;
    int_nbm = CountMine(grille, int_lignes, int_colonnes, int_x, int_y);

    if (int_x==int_lignes-1 && int_nbm!=0)
    {
        grille[int_x][int_y].valeur=int_nbm;
        grille[int_x][int_y].decouvert=1;
        grille[int_x][int_y].caractere=' ';
    }else if (int_nbm!=0)
    {
         grille[int_x][int_y].valeur=int_nbm;
         grille[int_x][int_y].decouvert=1;
         grille[int_x][int_y].caractere=' ';
    }else{
        while (int_x>=0 && int_nbm==0)
        {       
            UnveilSud(grille,int_lignes,int_colonnes,int_x,int_y);
            UnveilEst(grille,int_lignes,int_colonnes,int_x,int_y);
            UnveilOuest(grille,int_lignes,int_colonnes,int_x,int_y);
            UnveilNordOuest(grille,int_lignes,int_colonnes,int_x,int_y);
            UnveilNordEst(grille,int_lignes,int_colonnes,int_x,int_y); 
            UnveilSudOuest(grille,int_lignes,int_colonnes,int_x,int_y);
            UnveilSudEst(grille,int_lignes,int_colonnes,int_x,int_y);
            
            int_nbm = CountMine(grille, int_lignes, int_colonnes, int_x, int_y);
            grille[int_x][int_y].decouvert=1;
            grille[int_x][int_y].caractere=' '; 
            int_x--;
            if (int_nbm != 0)
            {
                grille[int_x+1][int_y].valeur=int_nbm;
            }  
        }
    }
}

void UnveilSud(Demineur** grille, int int_lignes, int int_colonnes, int int_x, int int_y){
    int int_nbm;
    int_nbm = CountMine(grille, int_lignes, int_colonnes, int_x, int_y);

    if (int_x==0 && int_nbm!=0)
    {
        grille[int_x][int_y].valeur=int_nbm;
        grille[int_x][int_y].decouvert=1;
        grille[int_x][int_y].caractere=' ';
    }else if (int_nbm!=0)
    {
        grille[int_x][int_y].valeur=int_nbm;
        grille[int_x][int_y].decouvert=1;
        grille[int_x][int_y].caractere=' ';
    }else{
        while (int_x<=int_lignes-1 && int_nbm==0)
        {
            int_nbm = CountMine(grille, int_lignes, int_colonnes, int_x, int_y);
            grille[int_x][int_y].decouvert=1;
            grille[int_x][int_y].caractere=' '; 
            int_x++;
            if (int_nbm != 0)
            {
                grille[int_x-1][int_y].valeur=int_nbm;

            }  
        }
    }
}

void UnveilEst(Demineur** grille, int int_lignes, int int_colonnes, int int_x, int int_y){
    int int_nbm;
    int_nbm = CountMine(grille, int_lignes, int_colonnes, int_x, int_y);

    if (int_y==0 && int_nbm!=0)
    {
        grille[int_x][int_y].valeur=int_nbm;
        grille[int_x][int_y].decouvert=1;
        grille[int_x][int_y].caractere=' '; 
    }else if (int_nbm!=0)
    {
        grille[int_x][int_y].valeur=int_nbm;
        grille[int_x][int_y].decouvert=1;
        grille[int_x][int_y].caractere=' '; 
    }else{
        while (int_y<=int_colonnes-1 && int_nbm==0)
        {
            int_nbm = CountMine(grille, int_lignes, int_colonnes, int_x, int_y);
            grille[int_x][int_y].decouvert=1;
            grille[int_x][int_y].caractere=' '; 
            int_y++;
            if (int_nbm != 0)
            {
                grille[int_x][int_y-1].valeur=int_nbm;

            }  
        }
    }
}

void UnveilOuest(Demineur** grille, int int_lignes, int int_colonnes, int int_x, int int_y){
    int int_nbm;
    int_nbm = CountMine(grille, int_lignes, int_colonnes, int_x, int_y);

    if (int_y==int_colonnes-1 && int_nbm!=0)
    {
        grille[int_x][int_y].valeur=int_nbm;
        grille[int_x][int_y].decouvert=1;
        grille[int_x][int_y].caractere=' ';  
    }else if (int_nbm!=0)
    {
        grille[int_x][int_y].valeur=int_nbm;
        grille[int_x][int_y].decouvert=1;
        grille[int_x][int_y].caractere=' '; 
    }else{
        while (int_y>=0 && int_nbm==0)
        {
            int_nbm = CountMine(grille, int_lignes, int_colonnes, int_x, int_y);
            grille[int_x][int_y].decouvert=1;
            grille[int_x][int_y].caractere=' '; 
            int_y--;
            if (int_nbm != 0)
            {
                grille[int_x][int_y+1].valeur=int_nbm;

            }  
        }
    }
}

void UnveilNordOuest(Demineur** grille, int int_lignes, int int_colonnes, int int_x, int int_y){
    int int_nbm;
    int_nbm = CountMine(grille, int_lignes, int_colonnes, int_x, int_y);
    if (int_nbm!=0)
    {
        grille[int_x][int_y].valeur=int_nbm;
        grille[int_x][int_y].decouvert=1;
        grille[int_x][int_y].caractere=' '; 
    }else{
    
    while (int_y>=0 && int_x>=0 && int_nbm==0)
        {
            int_nbm = CountMine(grille, int_lignes, int_colonnes, int_x, int_y);
            grille[int_x][int_y].decouvert=1;
            grille[int_x][int_y].caractere=' '; 
            int_y--;
            int_x--;
            if (int_nbm != 0)
            {
                grille[int_x+1][int_y+1].valeur=int_nbm;

            }  
        }
    }
}

void UnveilNordEst(Demineur** grille, int int_lignes, int int_colonnes, int int_x, int int_y){
    int int_nbm;
    int_nbm = CountMine(grille, int_lignes, int_colonnes, int_x, int_y);
    if (int_nbm!=0)
    {
        grille[int_x][int_y].valeur=int_nbm;
        grille[int_x][int_y].decouvert=1;
        grille[int_x][int_y].caractere=' '; 
    }else{
    
    while (int_y<=int_colonnes-1 && int_x>=0 && int_nbm==0)
        {
            int_nbm = CountMine(grille, int_lignes, int_colonnes, int_x, int_y);
            grille[int_x][int_y].decouvert=1;
            grille[int_x][int_y].caractere=' '; 
            int_y++;
            int_x--;
            if (int_nbm != 0)
            {
                grille[int_x+1][int_y-1].valeur=int_nbm;

            }  
        }
    }
}

void UnveilSudOuest(Demineur** grille, int int_lignes, int int_colonnes, int int_x, int int_y){
    int int_nbm;
    int_nbm = CountMine(grille, int_lignes, int_colonnes, int_x, int_y);
    if (int_nbm!=0)
    {
        grille[int_x][int_y].valeur=int_nbm;
        grille[int_x][int_y].decouvert=1;
        grille[int_x][int_y].caractere=' '; 
    }else{
    
    while (int_x<=int_lignes-1 && int_y>=0 && int_nbm==0)
        {
            int_nbm = CountMine(grille, int_lignes, int_colonnes, int_x, int_y);
            grille[int_x][int_y].decouvert=1;
            grille[int_x][int_y].caractere=' '; 
            int_y--;
            int_x++;
            if (int_nbm != 0)
            {
                grille[int_x-1][int_y+1].valeur=int_nbm;
            }  
        }
    }
}

void UnveilSudEst(Demineur** grille, int int_lignes, int int_colonnes, int int_x, int int_y){
    int int_nbm;
    int_nbm = CountMine(grille, int_lignes, int_colonnes, int_x, int_y);
    if (int_nbm!=0)
    {
        grille[int_x][int_y].valeur=int_nbm;
        grille[int_x][int_y].decouvert=1;
        grille[int_x][int_y].caractere=' '; 
    }else{
    
    while (int_x<=int_lignes-1 && int_y<=int_colonnes-1 && int_nbm==0)
        {
            int_nbm = CountMine(grille, int_lignes, int_colonnes, int_x, int_y);
            grille[int_x][int_y].decouvert=1;
            grille[int_x][int_y].caractere=' '; 
            int_y++;
            int_x++;
            if (int_nbm != 0)
            {
                grille[int_x-1][int_y-1].valeur=int_nbm;
            }  
        }
    }
}

void Unveil(Demineur** grille, int int_lignes, int int_colonnes, int int_x, int int_y){ 
    
    UnveilNord(grille,int_lignes,int_colonnes,int_x,int_y);
    UnveilSud(grille,int_lignes,int_colonnes,int_x,int_y);
    UnveilEst(grille,int_lignes,int_colonnes,int_x,int_y);
    UnveilOuest(grille,int_lignes,int_colonnes,int_x,int_y);
    UnveilNordEst(grille,int_lignes,int_colonnes,int_x,int_y);
    UnveilNordOuest(grille,int_lignes,int_colonnes,int_x,int_y);
    UnveilSudEst(grille,int_lignes,int_colonnes,int_x,int_y);
    UnveilSudOuest(grille,int_lignes,int_colonnes,int_x,int_y); 
}

void Discover(Demineur** grille, int int_lignes, int int_colonnes, int int_x, int int_y){
    int int_i;
    int int_j;
    int int_icase;
    int int_jcase;
    int int_nbvoisin;
    if (grille[int_x][int_y].mine == 0)
    {
        grille[int_x][int_y].valeur=CountMine(grille, int_lignes, int_colonnes, int_x, int_y);
        int_nbvoisin = grille[int_x][int_y].valeur;
        grille[int_x][int_y].decouvert=1;
        grille[int_x][int_y].caractere=' ';
        
        if (int_nbvoisin==0)
        {
            for (int_i = -1; int_i <= 1; int_i++)
            {
                for (int_j = -1; int_j <= 1; int_j++)
                {
                    int_icase = int_x+int_i;
                    int_jcase = int_y+int_j;
                    if (((int_i!=0) || (int_j!=0)) && (int_icase >= 0) && (int_icase < int_lignes) && (int_jcase >= 0) && (int_jcase < int_colonnes))
                    {
                        if (grille[int_icase][int_jcase].decouvert==0)
                        {
                            Discover(grille,int_lignes,int_colonnes,int_icase,int_jcase);
                        }       
                    }        
                }        
            }      
        }   
    }  
}

Reponse Position(){
    int int_x;
    int int_y;
    char char_choix;
    Reponse question;
    printf("Position en x: \n");
    scanf("%d", &int_x);
    question.x=int_x;
    printf("Position en y: \n");
    scanf("%d", &int_y);
    question.y=int_y;
    getchar();
    printf("Voulez-vous découvrir ou marquer la case (d pour découvrir, m pour marquer)? \n");
    scanf("%c", &char_choix);
    question.choix=char_choix;
    return(question);
}

int Win(Demineur** grille, Reponse question, int int_lignes, int int_colonnes, int int_mines, int int_compte){
int int_res=0;
int int_i;
int int_j;
int int_count;
int int_taille;
int_taille = (int_lignes*int_colonnes)-int_mines;
int_count=0;

    if ((question.x<0 || question.x > int_lignes-1) || (question.y<0 || question.y>int_colonnes-1))
        {
        printf("\033[1;31m");
        printf("Vos coordonnées sont eronnées \n");
        printf("\033[0;m");
        }else{
        if (question.choix=='m')
        {
            if (grille[question.x][question.y].decouvert!=1)
            {
                grille[question.x][question.y].drapeau=1;
                grille[question.x][question.y].decouvert=1;
                grille[question.x][question.y].caractere = '>';
            }else{
                printf("\033[1;33m");
                printf("Ne gaspillez pas un désamorceur sur une zone déjà découverte! \n");
                printf("\033[0;m");
            }
            
        }else if(question.choix=='d'){

            if (grille[question.x][question.y].mine==1 && grille[question.x][question.y].drapeau==0) // ICI
            {
                printf("\033[1;31m");
                printf("*SPLODED* \n");
                printf("\033[0;m");
                int_res=1;
            }else{
                Discover(grille,int_lignes,int_colonnes, question.x, question.y);      
                //Unveil(grille,int_lignes,int_colonnes, int_x, int_y);     
            }
        }
    }

    for (int_i = 0; int_i < int_lignes; int_i++)
    {
        for (int_j = 0; int_j < int_colonnes; int_j++)
        {
            if (grille[int_i][int_j].mine==1 && grille[int_i][int_j].drapeau==1)
            {
                int_compte=int_compte+1;
            }else if(grille[int_i][int_j].decouvert==1){
                int_count+=1;
            }
            
            if (grille[int_i][int_j].drapeau==1 && grille[int_i][int_j].mine==1 && int_compte==int_mines)
            {
                printf("\033[1;33m");
                printf("Vous avez gagné! \n");
                printf("\033[0;m");
                int_res=1;
            }
        } 
    }

    if(int_count==int_taille){
        printf("\033[1;33m");
        printf("Vous avez gagné! \n");
        printf("\033[0;m");
        int_res=1;
    }  
    
    return(int_res);
}
