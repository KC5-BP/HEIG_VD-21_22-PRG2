/*
 -----------------------------------------------------------------------------------
 Nom du fichier : 4.05-strncat.c
 Auteur(s)      : (\_/)
 Date creation  : <jj.mm.aaaa>

 Description    : 4.05
                    Proposez une implémentation de la fonction strncat dont le
                    prototype et la sémantique sont donnés ci-dessous :
char* strncat(char* to, const char* from, size_t size);

                    Semantique :
                        Concatène la chaîne from à la suite de la chaîne to et
                        retourne un pointeur sur to... mais au plus size
                        caractères de la chaîne from sont copiés. Ici,
                        contrairement à strncpy (voir exercice 4.3),
                        un caractère '\0' est toujours ajouté à la fin de la
                        chaîne (quel que soit le critère qui arrête la
                        concaténation).

                    Ecrire aussi un petit programme permettant de tester votre
                    fonction.

 Remarque(s)    : <� compl�ter>

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

char* strncat(char* to, const char* from, size_t size);

int main(void) {
	// <code>
	return EXIT_SUCCESS;
}

char* strncat(char* to, const char* from, size_t size) {

}
