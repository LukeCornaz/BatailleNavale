/**
 * Author : Luke Cornaz
 * Date : 08.03.2020
 * Version : 1.0
 */
#include <stdio.h>
#include <windows.h>
#include <stdbool.h>
//Pour avoir des accents, windows.h + SetConsoleOutputCP(65001) dans le int main.
#pragma execution_character_set("utf-8")

//Défini la position des bateaux.
#define NOMBRE_COLONNES 10
#define NOMBRE_LIGNES 10

#define COLONNE_BATEAU5 1
#define LIGNE1_BATEAU5 3
#define LIGNE2_BATEAU5 4
#define LIGNE3_BATEAU5 5
#define LIGNE4_BATEAU5 6
#define LIGNE5_BATEAU5 7

#define COLONNE1_BATEAU4 5
#define COLONNE2_BATEAU4 6
#define COLONNE3_BATEAU4 7
#define COLONNE4_BATEAU4 8
#define LIGNE_BATEAU4 9

#define COLONNE1_BATEAU3A 3
#define COLONNE2_BATEAU3A 4
#define COLONNE3_BATEAU3A 5
#define LIGNE_BATEAU3A 1

#define COLONNE1_BATEAU3B 5
#define COLONNE2_BATEAU3B 6
#define COLONNE3_BATEAU3B 7
#define LIGNE_BATEAU3B 6

#define COLONNE_BATEAU2 5
#define LIGNE1_BATEAU2 3
#define LIGNE2_BATEAU2 4

//Déclaration de variable.
char cibleLigne, carte[NOMBRE_COLONNES][NOMBRE_LIGNES], b;
int choix, cibleColonne, bateau5, bateau4, bateau3a, bateau3b, bateau2, win;

//Prototipe de fonction.
void retour();
void menu();

/**
 * Fonction qui permet de mettre des caractères spéciaux
 */
void carac(){
    //Sers à afficher les caractères spéciaux.
    SetConsoleOutputCP(65001);
}

/**
 * Fontion permetant de mettre pause.
 */
void pause() {
    //Commande servant à mettre pause dans le programme.
    system("Pause");
}

/**
 * Fonction qui va effacer ce qui se situe avant
 */
void clear() {
    //Commande pour effacer.
    system("cls");
}

/**
 * Fonction permettant d'afficher le titre
 */
void titre(){
    //Affiche le titre.
    printf("-----Bataille Navale-----\n\n");
}

/**
 * Fonction permetant de choisir une option
 * @return le choix
 */
int choixMenu() {
    //Servira à choisir une option du menu en fonction du choix qui sera retourné.
    choix;
    //Boucle qui demande de faire un choix jusqu'à avoir une bonne réponse.
    do {
        //printf("Faites votre choix : ");
        //Commande qui sert à empécher de remplir les scanf à la suite.
        fflush(stdin);
        scanf("%d", &choix);
        if ((choix < 1) || (choix > 5)) {
            printf("Ce choix n'est pas valide\n");
        }
    } while ((choix < 1) || (choix > 5));
    //Retourne le choix.
    return choix;
}

/**
 * Fonction servant à donner les informations de la carte
 */
void foncCarte() {
    //Fourni le fonctionnement de la carte.
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            carte[i][j] = ' ';
        }
    }
}

/**
 * Fonction servant à afficher la carte
 */
void afficherCarte() {
    //Affiche les numéros de chaque collones.
    printf("1  2  3  4  5  6  7  8  9  10\n");

    //Affiche les lignes égales au nombre de collones.
    for (int i = 0, b = 'A'; i < 10, b < 'K'; i++, b++) {
        printf("%c", b);
        for (int a = 0; a < 10; a++) {
            printf("[%c]", carte[a][i]);
        }
        printf("\n");
    }
}

/**
 * Fonction servant à demander où l'utilisateur veut tirer
 */
void tirer() {
    //Sers à donner les coordonnées de la colonne.
    printf("Colonne : ");
    //Empêche deux scanf de suite.
    fflush(stdin);
    scanf("%d", &cibleColonne);

    //Affiche les coordonnées de la ligne.
    printf("Ligne : ");
    fflush(stdin);
    scanf("%c", &cibleLigne);
}

/**
 * Fonction servant à convertir les données reçues afin de pouvoir les utilisers dans le tableau (carte)
 */
void transformeTir() {
    //Converti les tir pour donner l'informations au tableau.
    if ((cibleLigne >= 'a') && (cibleLigne <= 'j')) {
        cibleLigne -= 97;
    } else if ((cibleLigne >= 'A') && (cibleLigne <= 'J')) {
        cibleLigne -= 65;
    }
    cibleColonne -= 1;
}

/**
 * Fonction servant à savoir si le tir touche un bateau, le coule ou est dans l'eau
 */
void changerValeurCarte() {

    //Si un des define est égale au choix de l'utilisateurs afficher un X à la place du define.
    if (((cibleColonne == COLONNE_BATEAU5) && ((cibleLigne == LIGNE1_BATEAU5) || (cibleLigne == LIGNE2_BATEAU5)
                                               || (cibleLigne == LIGNE3_BATEAU5) || (cibleLigne == LIGNE4_BATEAU5) ||
                                               (cibleLigne == LIGNE5_BATEAU5)))
        || ((cibleLigne == LIGNE_BATEAU4) && ((cibleColonne == COLONNE1_BATEAU4) || (cibleColonne == COLONNE2_BATEAU4)
                                              || (cibleColonne == COLONNE3_BATEAU4) ||
                                              (cibleColonne == COLONNE4_BATEAU4)))
        ||
        ((cibleLigne == LIGNE_BATEAU3A) && ((cibleColonne == COLONNE1_BATEAU3A) || (cibleColonne == COLONNE2_BATEAU3A)
                                            || (cibleColonne == COLONNE3_BATEAU3A)))
        ||
        ((cibleLigne == LIGNE_BATEAU3B) && ((cibleColonne == COLONNE1_BATEAU3B) || (cibleColonne == COLONNE2_BATEAU3B)
                                            || (cibleColonne == COLONNE3_BATEAU3B)))
        || ((cibleColonne == COLONNE_BATEAU2) && ((cibleLigne == LIGNE1_BATEAU2) || (cibleLigne == LIGNE2_BATEAU2)))) {

        carte[cibleColonne][cibleLigne] = 'X';

        //Si toute les coordonnées du bateau est égale à X.
        if ((carte[COLONNE_BATEAU5][LIGNE1_BATEAU5] == 'X') && (carte[COLONNE_BATEAU5][LIGNE2_BATEAU5] == 'X')
            && (carte[COLONNE_BATEAU5][LIGNE3_BATEAU5] == 'X') && (carte[COLONNE_BATEAU5][LIGNE4_BATEAU5] == 'X')
            && (carte[COLONNE_BATEAU5][LIGNE5_BATEAU5] == 'X')) {

            //Transforme tout les X en C.
            for (int i = 3; i < 8; i++) {
                carte[COLONNE_BATEAU5][i] = 'C';
            }

            //Affiche "coulé" si les X se transforme en C
            printf("Coulé\n\n");
            //Quand un bateau est coulé il est égale à 1 pour remplir les condition de victoires.
            bateau5=1;

            //Même processus pour chaque bateaux.
        } else if ((carte[COLONNE1_BATEAU4][LIGNE_BATEAU4] == 'X') && (carte[COLONNE2_BATEAU4][LIGNE_BATEAU4] == 'X')
                   && (carte[COLONNE3_BATEAU4][LIGNE_BATEAU4] == 'X') &&
                   (carte[COLONNE4_BATEAU4][LIGNE_BATEAU4] == 'X')) {

            for (int i = 5; i < 9; i++) {
                carte[i][LIGNE_BATEAU4] = 'C';
            }

            //Même processus pour chaque bateaux.
            printf("Coulé\n\n");
            //Même condition de victoire.
            bateau4=1;

        } else if ((carte[COLONNE1_BATEAU3A][LIGNE_BATEAU3A] == 'X') &&
                   (carte[COLONNE2_BATEAU3A][LIGNE_BATEAU3A] == 'X')
                   && (carte[COLONNE3_BATEAU3A][LIGNE_BATEAU3A] == 'X')) {

            for (int i = 3; i < 6; i++) {
                carte[i][LIGNE_BATEAU3A] = 'C';
            }

            printf("Coulé\n\n");
            bateau3a=1;

        } else if ((carte[COLONNE1_BATEAU3B][LIGNE_BATEAU3B] == 'X') &&
                   (carte[COLONNE2_BATEAU3B][LIGNE_BATEAU3B] == 'X') &&
                   (carte[COLONNE3_BATEAU3B][LIGNE_BATEAU3B] == 'X')) {

            for (int i = 5; i < 8; i++) {
                carte[i][LIGNE_BATEAU3B] = 'C';
            }

            printf("Coulé\n\n");
            bateau3b=1;

        } else if ((carte[COLONNE_BATEAU2][LIGNE1_BATEAU2] == 'X') && (carte[COLONNE_BATEAU2][LIGNE2_BATEAU2] == 'X')) {

            for (int i = 3; i < 5; i++) {
                carte[COLONNE_BATEAU2][i] = 'C';
            }

            printf("Coulé !\n\n");
            bateau2=1;

        } else {
            //Affiche "touché" tant que le bateau est vivant.
            printf("Touché !\n\n");
        }

        } else {
            //Affiche un "O" si rien n'est touché ou coulé.
            carte[cibleColonne][cibleLigne] = 'O';

            //Et affiche "A l'eau".
            printf("A l'eau !\n\n");
        }
        //Affiche un vide entre les "[]".
        printf("");
}

/**
 * Fonction servant à savoir si un tir est valide
 */
void verfierTir() {
    //Si le choix du joueur est plus petit que 0 ou plus grand que neuf le tir est non valide.
    if ((cibleColonne < 0) || (cibleColonne > 9) || (cibleLigne < 0) || (cibleLigne > 9)) {
        printf("Tir non valide\n\n");
    } else {
        changerValeurCarte();
    }
}

/**
 * Fonction servant à vérifier si les conditions de victoire sont remplies
 */
void conditionsVictoire() {
    if ((bateau5 == 1) && (bateau4 == 1) && (bateau3a == 1) && (bateau3b == 1) && (bateau2 == 1)) {
        win = 1;
    }
}

/**
 * Fonction permetant de répeter toutes les étapes d'un tire.
 */
void jouer() {
    //Fonctionnement de la carte.
    foncCarte();

    do {
        //Efface tout ce qui est sur l'écran.
        clear();

        //Affiche la carte complète.
        afficherCarte();

        //Sers à choisir les coordonnées d'un tir.
        tirer();

        //Converti les données pour les utilisers dans le tableau.
        transformeTir();

        //Si les données d'un tir ne sont pas comprise entre 0 et 9 le tir est non valide.
        verfierTir();

        conditionsVictoire();

        //Met en pause le programme.
        pause();

      //Dés que le win est égale à 1 sort de la boucle.
    } while (win != 1);

    //Et affiche un message de victoire.
    clear();
    printf("Bravo tu as éliminé tout les bateaux ennemis !!!\n\n");
    printf("Ton score est de 500pt\n\n");
    retour();
}

typedef struct{
    //Déclaration des variables.
    char name[32];
    bool authenticated;
} user;

/**
 * Objet pour l'identification
 * @return authenticatingUser
 */
user authenticate(){
    user authenticatingUser;
    //Empêche deux scanf de suite.
    fflush(stdin);
    //Permet de rentrer un pseudo
    scanf("%s",authenticatingUser.name);

    //Retourne le pseudo
    return authenticatingUser;
}

/**
 * Fonction permetant d'enregistrer le pseudo
 */
void pseudo() {
    //Affiche la demande de pseudo.
    printf("Entrez votre pseudo : \n\n");
    user pseudo = {"",false};
    pseudo = authenticate();
    printf("\n\nBievenue %s !\n\n", pseudo.name);
    //Retourne au menu.
    retour();
}

/**
 * Fonction affichant le score
 */
void score(authenticate) {
    //Affiche les scores (non terminé).
    printf("Pseudo 1...............Score 1\n");
    printf("Pseudo 2...............Score 2\n");
    printf("Pseudo 3...............Score 3\n");
    printf("Pseudo 4...............Score 4\n");
    printf("Pseudo 5...............Score 5\n");
    printf("Pseudo 6...............Score 6\n");
    printf("Pseudo 7...............Score 7\n");
    printf("Pseudo 8...............Score 8\n");
    //Retourne au menu
    retour();
}

/**
 * Fonction affichant l'aide du jeu
 */
void aide(){
    //Affiche l'aide du jeu.
    printf("Comment jouer ?\n\n"
           "Choisissez une case allant de A1 à J10,\n"
           "le but étant de couler les 5 bateaux de l'adversaire.\n"
           "Le premier à avoir coulé tout les \n"
           "bateaux de l'adversaire gagne la partie.\n\n"
           "Vos bateaux : B\n"
           "Touché : X\n"
           "A l'eau : O \n"
           "Coulé : C\n\n");
    //Retourne au menu.
    retour();
}

/**
 * Fonction permettant de quitter avec une confirmation de l'utilisateur
 */
void quitter() {
    char quit;
    //Affiche les choix.
    printf("Voulez-vous vraiment quitter? \n\n");
    printf("Oui (Y)     Non (N)\n\n");
    //Empêche deux scanf de suite.
    fflush(stdin);
    scanf("%c", &quit);
    //Si la réponse est égale à Y ou y, fin du programme.
    if(quit == 89 || quit == 121 ) {

    }
    //Sinon si la réponse est égale à N ou n, retourne au menu.
    else if(quit == 78 || quit == 110) {
        //Retourne au menu.
        retour();
    }
}

/**
 * Fonction affichant un menu et se qui se retrouve à l'interieur des option.
 */
void menu() {
    //Affiche le titre.
    titre();
    //Affiche un menu.
    printf("Menu\n\n");
    printf("1-Jouer\n");
    printf("2-Pseudo\n");
    printf("3-Scores\n");
    printf("4-Aide\n");
    printf("5-Quitter\n");

    choixMenu();
    //Le switch vous montre l'option sélectionée.
    switch (choix) {
        case 1:
            //Nettoie l'interface pour que rien ne soit affiché.
            clear();
            //Répète les étapes d'un tir.
            jouer();
            break;
        case 2 :
            clear();
            //Affiche un sorte de titres au programme.
            printf("-----Pseudo-----\n\n");
            //Enregistre un pseudo tout le long de la partie.
            pseudo();
            break;
        case 3:
            clear();
            printf("-----Scores-----\n\n");
            //Affiche le score.
            score();
            break;
        case 4:
            clear();
            printf("-----Aide-----\n\n");
            //Affiche l'aide du jeu.
            aide();
            break;
        case 5:
            clear();
            //Permet de quitter le programme.
            quitter();
            break;
        default:
            clear();
            printf("Choisissez une option existante\n");
            //Réaffiche le menu si le choix est faux.
            retour();
    }
}

/**
 * Fonction servant à effacer et revenir au menu
 */
void retour(){
    //Pause du programme.
    system("Pause");
    //Nettoie l'interface.
    clear();
    //Affiche le menu.
    menu();
}

/**
 * Fonction principal
 */
int main() {
    //Sers à afficher les caractères spéciaux.
    carac();

    // Afficher le menu
    menu();

    return 0;
}
