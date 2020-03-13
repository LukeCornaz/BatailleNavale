/**
 * Author : Luke Cornaz
 * Date : 08.03.2020
 * Version : 0.1
 */
#include <stdio.h>
#include <windows.h>
//Pour avoir des accents, windows.h + SetConsoleOutputCP(65001) dans le int main.
#pragma execution_character_set("utf-8")

int choix;
int grille[10][10] = {
        {}
};

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

void jouer() {
    printf("1  2  3  4  5  6  7  8  9  10");
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



int main() {
    //Sers à afficher les caractères spéciaux.
    carac();

    // Afficher titre
    titre();

    // Afficher le menu
    menu();

    return 0;
}
