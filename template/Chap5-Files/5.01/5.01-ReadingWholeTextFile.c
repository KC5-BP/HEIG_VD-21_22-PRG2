/*
 -----------------------------------------------------------------------------------
 Nom du fichier : 5.01-ReadingWholeTextFile.c
 Auteur(s)      : (\_/)
 Date creation  : <jj.mm.aaaa>

 Description    : Exo. 5.1
                    En supposant disposer du fichier texte suivant (voir file.txt)

                    Écrire le plus proprement possible un programme C permettant
                    d'afficher à l'écran l'intégralité du contenu du fichier.

 Remarque(s)    : <� compl�ter>

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

#define NOM_FICHIER "file.txt"

int main(void) {
    FILE* f = fopen(NOM_FICHIER, "r");
	return EXIT_SUCCESS;
}
