/*
 -----------------------------------------------------------------------------------
 Nom du fichier : 4.03-strncpy.c
 Auteur(s)      : (\_/)
 Date creation  : <jj.mm.aaaa>

 Description    : 4.03
                    Proposez une implémentation de la fonction strncpy dont le
                    prototype et la sémantique sont donnés ci-dessous :
char* strncpy(char* to, const char* from, size_t size);

                    Semantique :
                        Recopie les size premiers caractères de la chaîne from dans
                        la chaîne to et retourne un pointeur sur to. De manière plus
                        précise :
                            • Si size <= strlen(from), size caractères sont copiés
                            dans to.
                            Attention : Aucune marque de fin de chaîne ('\0')
                            n'est copiée dans to
                            • Si size > strlen(from), strlen(from) caractères
                            ainsi que size - strlen(from) '\0' sont copiés dans to.

                    Ecrire aussi un petit programme permettant de tester votre
                    fonction.

 Remarque(s)    : <� compl�ter>

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

char* strncpy(char* to, const char* from, size_t size);

int main(void) {
	// <code>
	return EXIT_SUCCESS;
}

char* strncpy(char* to, const char* from, size_t size) {

}
