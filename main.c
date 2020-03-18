/**
 * Author : Luke Cornaz
 * Date : 08.03.2020
 * Version : 0.1
 */
#include <stdio.h>
#include <windows.h>
//Pour avoir des accents, windows.h + SetConsoleOutputCP(65001) dans le int main.
#pragma execution_character_set("utf-8")

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


char carte[NOMBRE_COLONNES][NOMBRE_LIGNES], cibleLigne, b;
int choix, cibleColonne;


/**
 * Fonction qui permet de mettre des caractères spéciaux
 */
void carac(){
    //Sers à afficher les caractères spéciaux.
    SetConsoleOutputCP(65001);
}

/**
 * Fonction qui va effacer ce qui se situe avant
 */
void clear() {
    //Commande pour effacer.
    system("cls");
}

void retour(){
    system("Pause");
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
void faireCarte() {

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
    printf("    1  2  3  4  5  6  7  8  9  10\n");

    for (int i = 0, b = 'A'; i < 10, b < 'K'; i++, b++) {
        printf(" %c ", b);
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
    printf("Colonne : ");
    fflush(stdin);
    scanf("%d", &cibleColonne);

    printf("Ligne : ");
    fflush(stdin);
    scanf("%c", &cibleLigne);
}

/**
 * Fonction servant à convertir les donnés reçues afin de pouvoir les utiliser dans le tableau (carte)
 */
void transformeTir() {

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

        if ((carte[COLONNE_BATEAU5][LIGNE1_BATEAU5] == 'X') && (carte[COLONNE_BATEAU5][LIGNE2_BATEAU5] == 'X')
            && (carte[COLONNE_BATEAU5][LIGNE3_BATEAU5] == 'X') && (carte[COLONNE_BATEAU5][LIGNE4_BATEAU5] == 'X')
            && (carte[COLONNE_BATEAU5][LIGNE5_BATEAU5] == 'X')) {

            for (int i = 3; i < 8; i++) {
                carte[COLONNE_BATEAU5][i] = 'C';
            }

            printf("Coulé\n\n");

        } else if ((carte[COLONNE1_BATEAU4][LIGNE_BATEAU4] == 'X') && (carte[COLONNE2_BATEAU4][LIGNE_BATEAU4] == 'X')
                   && (carte[COLONNE3_BATEAU4][LIGNE_BATEAU4] == 'X') &&
                   (carte[COLONNE4_BATEAU4][LIGNE_BATEAU4] == 'X')) {

            for (int i = 5; i < 9; i++) {
                carte[i][LIGNE_BATEAU4] = 'C';
            }

            printf("Coulé\n\n");

        } else if ((carte[COLONNE1_BATEAU3A][LIGNE_BATEAU3A] == 'X') &&
                   (carte[COLONNE2_BATEAU3A][LIGNE_BATEAU3A] == 'X')
                   && (carte[COLONNE3_BATEAU3A][LIGNE_BATEAU3A] == 'X')) {

            for (int i = 3; i < 6; i++) {
                carte[i][LIGNE_BATEAU3A] = 'C';
            }

            printf("Coulé\n\n");

        } else if ((carte[COLONNE1_BATEAU3B][LIGNE_BATEAU3B] == 'X') &&
                   (carte[COLONNE2_BATEAU3B][LIGNE_BATEAU3B] == 'X') &&
                   (carte[COLONNE3_BATEAU3B][LIGNE_BATEAU3B] == 'X')) {

            for (int i = 5; i < 8; i++) {
                carte[i][LIGNE_BATEAU3B] = 'C';
            }

            printf("Coulé\n\n");

        } else if ((carte[COLONNE_BATEAU2][LIGNE1_BATEAU2] == 'X') && (carte[COLONNE_BATEAU2][LIGNE2_BATEAU2] == 'X')) {

            for (int i = 3; i < 5; i++) {
                carte[COLONNE_BATEAU2][i] = 'C';
            }

            printf("Coulé !\n\n");

        } else {
            printf("Touché !\n\n");
        }

    } else {
        carte[cibleColonne][cibleLigne] = 'O';

        printf("A l'eau !\n\n");
    }
    printf("");
}

/**
 * Fonction servant à savoir si un tir est valide
 */
void verfierTir() {
    if ((cibleColonne < 0) || (cibleColonne > 9) || (cibleLigne < 0) || (cibleLigne > 9)) {
        printf("Tir non valide\n\n");
    } else {
        changerValeurCarte();
    }
}

void jouer() {
    faireCarte();

    do {

        clear();

        afficherCarte();

        tirer();

        transformeTir();

        verfierTir();

        retour();

    } while (choix != 5000);
}

void aide() {
    printf("\nComment jouer ?\n\n"
           "Choisissez une case allant de A1 à J10,\n"
           "le but étant de couler les 5 bateaux de l'adversaire.\n"
           "Le premier à avoir coulé tout les \n"
           "bateaux de l'adversaire gagne la partie.\n\n"
           "Vos bateaux : B\n"
           "Touché : X\n"
           "A l'eau : O \n"
           "Coulé : C\n\n");
    retour();
}

/**
 * Fonction affichant un menu
 */
void menu() {
    //Affiche un menu.
    printf("menu: \n");
    printf("1-Jouer\n");
    printf("2-Pseudo\n");
    printf("3-Scores\n");
    printf("4-Aide\n");
    printf("5-Quitter\n");

    choixMenu();
    //Le switch vous montre l'option sélectionée.
    switch (choix) {
        case 1:
            clear();
            printf("Vous avez choisi de lancer une partie\n");
            retour();
            jouer();
            break;
        case 2 :
            printf("Vous avez choisi les pseudos\n");
            break;
        case 3:
            printf("Vous avez choisi les scores\n");
            break;
        case 4:
            clear();
            printf("Vous avez choisi l'aide\n");
            aide();
            break;
        case 5:
            printf("Vous avez choisi de quitter\n");
            break;
        default:
            printf("Choisissez une option existante\n");
    }
}

/**
 * Fonction principal
 */
int main() {
    //Sers à afficher les caractères spéciaux.
    carac();

    // Afficher titre
    titre();

    // Afficher le menu
    menu();

    return 0;
}
