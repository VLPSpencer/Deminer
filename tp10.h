/**
 * \file tp10.h
 * \brief Ce programme effectue l'ensemble des algos du TP10
 * \author Antonin Soulier
 * \version 1
 * \date 2 Octobre 2020
 * \param argc 2 arguments en entrée
 * \param argv aucune
 * \return 0 si tout s'est bien passé
*/


typedef struct Demineur Demineur; //Pour éviter de devoir remettre struct devant le type démineur

/*! \struct Demineur
 * Structure pour la manipulation des valeurs des cases de notre grille du démineur
 */
struct Demineur
{
    char caractere;
    int valeur;
    int decouvert;
    int voisin;
    int mine;
    int drapeau;
};

typedef struct Reponse Reponse; //Pour éviter de devoir remettre struct devant le type Reponse

/*! \struct Demineur
 * Structure pour le retour de la saisi du user concernant la position et le découvrement ou drapeau
 */
struct Reponse
{
    int x;
    int y;
    char choix;
};

/**
 * @fn Demineur** Create(int int_lignes,int int_colonnes)
 * @author Soulier Antonin <soulierant@eisti.eu>
 * @version 1
 * @date 17 Octobre 2020 - 12:45:25 2020
 * @brief la fonction crée et intialise la grille de jeu en fonction du nombre de lignes et de colonnes demandées par le user.
 * @param prend deux entier en entrée
 * @return retourne la grille initialisée
 */
extern Demineur** Create(int int_lignes,int int_colonnes);

/**
 * @proc void Display(Demineur** grille, int int_lignes, int int_colonnes)
 * @author Soulier Antonin <soulierant@eisti.eu>
 * @version 1
 * @date 17 Octobre 2020 - 12:45:25 2020
 * @brief la procédure affiche la grille
 * @param prend deux entier et une grlle en entrée
 * @return void
 */
extern void Display(Demineur** grille, int int_lignes, int int_colonnes);

/**
 * @proc void PlaceMine(Demineur** grille, int int_mines, int int_lignes, int int_colonnes)
 * @author Soulier Antonin <soulierant@eisti.eu>
 * @version 1
 * @date 17 Octobre 2020 - 12:45:25 2020
 * @brief la procédure place le nombre de mines entrée par le user aléatoirement sur la grille
 * @param prend trois entier et une grlle en entrée
 * @return void
 */
extern void PlaceMine(Demineur** grille, int int_mines, int int_lignes, int int_colonnes);

/**
 * @fn int VoisinOuest(Demineur** grille, int int_lignes, int int_colonnes, int int_x, int int_y)
 * @author Soulier Antonin <soulierant@eisti.eu>
 * @version 1
 * @date 17 Octobre 2020 - 12:45:25 2020
 * @brief la fonction regarde si il y a une mine à l'ouest de la position
 * @param prend une grille et quatre entiers en entrée
 * @return retourne un entier
 */
extern int VoisinOuest(Demineur** grille, int int_lignes, int int_colonnes, int int_x, int int_y);

/**
 * @fn int VoisinEst(Demineur** grille, int int_lignes, int int_colonnes, int int_x, int int_y);
 * @author Soulier Antonin <soulierant@eisti.eu>
 * @version 1
 * @date 17 Octobre 2020 - 12:45:25 2020
 * @brief la fonction regarde si il y a une mine à l'est de la position
 * @param prend une grille et quatre entiers en entrée
 * @return retourne un entier
 */
extern int VoisinEst(Demineur** grille, int int_lignes, int int_colonnes, int int_x, int int_y);

/**
 * @fn int VoisinNord(Demineur** grille, int int_lignes, int int_colonnes, int int_x, int int_y)
 * @author Soulier Antonin <soulierant@eisti.eu>
 * @version 1
 * @date 17 Octobre 2020 - 12:45:25 2020
 * @brief la fonction regarde si il y a une mine au nord de la position
 * @param prend une grille et quatre entiers en entrée
 * @return retourne un entier
 */
extern int VoisinNord(Demineur** grille, int int_lignes, int int_colonnes, int int_x, int int_y);

/**
 * @fnint VoisinSud(Demineur** grille, int int_lignes, int int_colonnes, int int_x, int int_y)
 * @author Soulier Antonin <soulierant@eisti.eu>
 * @version 1
 * @date 17 Octobre 2020 - 12:45:25 2020
 * @brief la fonction regarde si il y a une mine au sud de la position
 * @param prend une grille et quatre entiers en entrée
 * @return retourne un entier
 */
extern int VoisinSud(Demineur** grille, int int_lignes, int int_colonnes, int int_x, int int_y);

/**
 * @fn int VoisinNordOuest(Demineur** grille, int int_lignes, int int_colonnes, int int_x, int int_y)
 * @author Soulier Antonin <soulierant@eisti.eu>
 * @version 1
 * @date 17 Octobre 2020 - 12:45:25 2020
 * @brief la fonction regarde si il y a une mine au nord ouest de la position
 * @param prend une grille et quatre entiers en entrée
 * @return retourne un entier
 */
extern int VoisinNordOuest(Demineur** grille, int int_lignes, int int_colonnes, int int_x, int int_y);

/**
 * @fn int VoisinNordEst(Demineur** grille, int int_lignes, int int_colonnes, int int_x, int int_y)
 * @author Soulier Antonin <soulierant@eisti.eu>
 * @version 1
 * @date 17 Octobre 2020 - 12:45:25 2020
 * @brief la fonction regarde si il y a une mine au nord est de la position
 * @param prend une grille et quatre entiers en entrée
 * @return retourne un entier
 */
extern int VoisinNordEst(Demineur** grille, int int_lignes, int int_colonnes, int int_x, int int_y);

/**
 * @fn int VoisinSudOuest(Demineur** grille, int int_lignes, int int_colonnes, int int_x, int int_y)
 * @author Soulier Antonin <soulierant@eisti.eu>
 * @version 1
 * @date 17 Octobre 2020 - 12:45:25 2020
 * @brief la fonction regarde si il y a une mine au sud ouest de la position
 * @param prend une grille et quatre entiers en entrée
 * @return retourne un entier
 */
extern int VoisinSudOuest(Demineur** grille, int int_lignes, int int_colonnes, int int_x, int int_y);

/**
 * @fn int VoisinSudEst(Demineur** grille, int int_lignes, int int_colonnes, int int_x, int int_y)
 * @author Soulier Antonin <soulierant@eisti.eu>
 * @version 1
 * @date 17 Octobre 2020 - 12:45:25 2020
 * @brief la fonction regarde si il y a une mine au sud est de la position
 * @param prend une grille et quatre entiers en entrée
 * @return retourne un entier
 */
extern int VoisinSudEst(Demineur** grille, int int_lignes, int int_colonnes, int int_x, int int_y);

/**
 * @fn int CountMine(Demineur** grille, int int_lignes, int int_colonnes, int int_x, int int_y)
 * @author Soulier Antonin <soulierant@eisti.eu>
 * @version 1
 * @date 17 Octobre 2020 - 12:45:25 2020
 * @brief la fonction compte le nombre de mines totale autour de la position entrée par le user
 * @param prend une grille et quatre entiers en entrée
 * @return retourne un entier
 */
extern int CountMine(Demineur** grille, int int_lignes, int int_colonnes, int int_x, int int_y);

/**
 * @fn Reponse Position()
 * @author Soulier Antonin <soulierant@eisti.eu>
 * @version 1
 * @date 17 Octobre 2020 - 12:45:25 2020
 * @brief la fonction demande au user la case qu'il veut découvrir et ce qu'il veut en faire
 * @param void
 * @return retourne la structure avec les entrées du user
 */
extern Reponse Position();

/**
 * @fn int Win(Demineur** grille, Reponse question, int int_lignes, int int_colonnes, int int_mines, int int_compte)
 * @author Soulier Antonin <soulierant@eisti.eu>
 * @version 1
 * @date 17 Octobre 2020 - 12:45:25 2020
 * @brief la fonction verifie si la partie est terminée et modifie la grille en fonction de la ou le joueur joue. Retourne 1 si oui 0 sinon.
 * @param prend deux structures et quatre entiers en paramètre
 * @return retourne un entier
 */
extern int Win(Demineur** grille, Reponse question, int int_lignes, int int_colonnes, int int_mines, int int_compte);

/**
 * @proc void Unveil(Demineur** grille, int int_lignes, int int_colonnes, int int_x, int int_y)
 * @author Soulier Antonin <soulierant@eisti.eu>
 * @version 1
 * @date 17 Octobre 2020 - 12:45:25 2020
 * @brief la procédure apelle toutes les fonctions Unveil et dévoile les cases nécessaires
 * @param prend quatre entier et une grille en entrée
 * @return void
 */
extern void Unveil(Demineur** grille, int int_lignes, int int_colonnes, int int_x, int int_y);

/**
 * @proc void UnveilNord(Demineur** grille, int int_lignes, int int_colonnes, int int_x, int int_y)
 * @author Soulier Antonin <soulierant@eisti.eu>
 * @version 1
 * @date 17 Octobre 2020 - 12:45:25 2020
 * @brief la procédure dévoile les cases au nord jusqu'à ce qu'elle tombe sur une mine ou sur la fin du tableau
 * @param prend quatre entier et une grille en entrée
 * @return void
 */
extern void UnveilNord(Demineur** grille, int int_lignes, int int_colonnes, int int_x, int int_y);

/**
 * @proc void UnveilSud(Demineur** grille, int int_lignes, int int_colonnes, int int_x, int int_y)
 * @author Soulier Antonin <soulierant@eisti.eu>
 * @version 1
 * @date 17 Octobre 2020 - 12:45:25 2020
 * @brief la procédure dévoile les cases au sud jusqu'à ce qu'elle tombe sur une mine ou sur la fin du tableau
 * @param prend quatre entier et une grille en entrée
 * @return void
 */
extern void UnveilSud(Demineur** grille, int int_lignes, int int_colonnes, int int_x, int int_y);

/**
 * @proc void UnveilEst(Demineur** grille, int int_lignes, int int_colonnes, int int_x, int int_y)
 * @author Soulier Antonin <soulierant@eisti.eu>
 * @version 1
 * @date 17 Octobre 2020 - 12:45:25 2020
 * @brief la procédure dévoile les cases à l'est jusqu'à ce qu'elle tombe sur une mine ou sur la fin du tableau
 * @param prend quatre entier et une grille en entrée
 * @return void
 */
extern void UnveilEst(Demineur** grille, int int_lignes, int int_colonnes, int int_x, int int_y);

/**
 * @proc void UnveilOuest(Demineur** grille, int int_lignes, int int_colonnes, int int_x, int int_y)
 * @author Soulier Antonin <soulierant@eisti.eu>
 * @version 1
 * @date 17 Octobre 2020 - 12:45:25 2020
 * @brief la procédure dévoile les cases à l'ouest jusqu'à ce qu'elle tombe sur une mine ou sur la fin tu tableau
 * @param prend quatre entier et une grille en entrée
 * @return void
 */
extern void UnveilOuest(Demineur** grille, int int_lignes, int int_colonnes, int int_x, int int_y);

/**
 * @proc void UnveilNordOuest(Demineur** grille, int int_lignes, int int_colonnes, int int_x, int int_y)
 * @author Soulier Antonin <soulierant@eisti.eu>
 * @version 1
 * @date 17 Octobre 2020 - 12:45:25 2020
 * @brief la procédure dévoile les cases au nord ouest jusqu'à ce qu'elle tombe sur une mine ou sur la fin du tableau
 * @param prend quatre entier et une grille en entrée
 * @return void
 */
extern void UnveilNordOuest(Demineur** grille, int int_lignes, int int_colonnes, int int_x, int int_y);

/**
 * @proc void UnveilNordEst(Demineur** grille, int int_lignes, int int_colonnes, int int_x, int int_y)
 * @author Soulier Antonin <soulierant@eisti.eu>
 * @version 1
 * @date 17 Octobre 2020 - 12:45:25 2020
 * @brief la procédure dévoile les cases au nord est jusqu'à ce qu'elle tombe sur une mine ou sur la fin du tableau
 * @param prend quatre entier et une grille en entrée
 * @return void
 */
extern void UnveilNordEst(Demineur** grille, int int_lignes, int int_colonnes, int int_x, int int_y);

/**
 * @proc void UnveilSudOuest(Demineur** grille, int int_lignes, int int_colonnes, int int_x, int int_y)
 * @author Soulier Antonin <soulierant@eisti.eu>
 * @version 1
 * @date 17 Octobre 2020 - 12:45:25 2020
 * @brief la procédure dévoile les cases au sud ouest jusqu'à ce qu'elle tombe sur une mine ou sur la fin du tableau
 * @param prend quatre entier et une grille en entrée
 * @return void
 */
extern void UnveilSudOuest(Demineur** grille, int int_lignes, int int_colonnes, int int_x, int int_y);

/**
 * @proc void UnveilSudOuest(Demineur** grille, int int_lignes, int int_colonnes, int int_x, int int_y)
 * @author Soulier Antonin <soulierant@eisti.eu>
 * @version 1
 * @date 17 Octobre 2020 - 12:45:25 2020
 * @brief la procédure dévoile les cases au sud est jusqu'à ce qu'elle tombe sur une mine ou sur la fin du tableau
 * @param prend quatre entier et une grille en entrée
 * @return void
 */
extern void UnveilSudEst(Demineur** grille, int int_lignes, int int_colonnes, int int_x, int int_y);

/**
 * @proc void Discover(Demineur** grille, int int_lignes, int int_colonnes, int int_x, int int_y)
 * @author Soulier Antonin <soulierant@eisti.eu>
 * @version 1
 * @date 17 Octobre 2020 - 12:45:25 2020
 * @brief la procédure dévoile les cases jusqu'à ce qu'elle tombe sur une mine ou sur la fin du tableau
 * @param prend quatre entier et une grille en entrée
 * @return void
 */
extern void Discover(Demineur** grille, int int_lignes, int int_colonnes, int int_x, int int_y);