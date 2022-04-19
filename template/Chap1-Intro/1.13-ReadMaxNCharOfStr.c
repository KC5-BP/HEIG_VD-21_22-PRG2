/*
 -----------------------------------------------------------------------------------
 Nom du fichier : 1.13-ReadMaxNCharOfStr.c
 Auteur(s)      : (\_/)
 Date creation  : <jj.mm.aaaa>

 Description    : 1.13
                     1) Le code suivant, pourtant simple, comporte 3 erreurs majeurs
                        Lesquels ?
                     2) Reecrire le code en corrigeant les dites erreurs.

 Remarque(s)    : <� compl�ter>

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

#define TAILLE_NOM 20

int main(void) {
    char nom[TAILLE_NOM + 1];

    printf("Entrez votre nom (%d caract. max) : ", TAILLE_NOM);
    scanf("%20s", nom);
    printf("Votre nom est \"%s\"\n", nom);

    system(PAUSE);
    return EXIT_SUCCESS;
}
