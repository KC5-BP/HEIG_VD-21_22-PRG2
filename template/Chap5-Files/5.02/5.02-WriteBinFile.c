/*
 -----------------------------------------------------------------------------------
 Nom du fichier : 5.02-WriteBinFile.c
 Auteur(s)      : (\_/)
 Date creation  : <jj.mm.aaaa>

 Description    : 5.02
                    Écrire un programme C permettant de stocker dans un fichier
                    binaire nommé personnes.dat des données relatives à des
                    personnes.
                    - Son nom    (20 caract. max)
                    - Son prénom (15 caract. max)
                    - Son âge    (unsigned short)

                    Les données des diverses personnes doivent être saisies par
                    l'utilisateur. On conviendra que la saisie se termine dès lors
                    que l'utilisateur entre un nom de personne vide.

 Remarque(s)    : <� compl�ter>

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NOM_FICHIER "personnes.dat"

void clear_stdin(void);

int main(void) {
    FILE* file = fopen(NOM_FICHIER, "wb");
    // TODO
	return EXIT_SUCCESS;
}

#if CLEAR_STDIN == CLEAR_STDIN_LOOP
void clear_stdin(void) {
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

#elif CLEAR_STDIN == CLEAR_STDIN_FSEEK
void clear_stdin(void) {
    fseek(stdin, 0, SEEK_END);
}

#endif
