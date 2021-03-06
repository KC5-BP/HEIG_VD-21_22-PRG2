/*
 -----------------------------------------------------------------------------------
 Nom du fichier : 3.10-DynamicStack.c
 Auteur(s)      : (\_/)
 Date creation  : <jj.mm.aaaa>

 Description    : 3.10
                    Compléter la partie notée <à compléter> du code ci-dessous de
                    telle sorte que celui-ci affiche
                    (si l’utilisateur entre successivement
                                                les valeurs 1, 2, 3 et 0) :
                    Donnez un entier (0 pour terminer) : 1
                    Donnez un entier (0 pour terminer) : 2
                    Donnez un entier (0 pour terminer) : 3
                    Donnez un entier (0 pour terminer) : 0
                    3
                    2
                    1

 Remarque(s)    : <� compl�ter>

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef int Info;

typedef struct {
    Info info;
    struct Element* next;
} Element;

typedef Element* Pile;

bool empiler(Pile* pile, Info info) {
   Element* tmp = (Element*) malloc(sizeof(Element));
   if (tmp) {
      *tmp = (Element) {info, *pile};
      *pile = tmp;
      return true;
   }
   return false;
}

bool desempiler(Pile* pile, Info* info) {
   if (*pile != NULL) { // Si la pile n'est pas vide
      Element* tmp = *pile;
      *info = tmp->info;
      *pile = tmp->next;
      free(tmp);
      return true;
   }
   return false;
}

bool estVide(Pile p) {
   return p == NULL;
}

int main(void) {
    Pile pile = NULL;
    Info info;

    // Saisie utilisateur
    do {
        printf("Donnez un entier (0 pour terminer) : ");
        scanf("%d", &info);
        if (info != 0)
            empiler(&pile, info);
    } while (info != 0);

    // Affichage dans l'ordre inverse des valeurs saisies par l'utilisateur
    printf("\n");
    while (!estVide(pile)) {
        desempiler(&pile, &info);
        printf("%d\n", info);
    }
    free(pile);
    return EXIT_SUCCESS;
}

