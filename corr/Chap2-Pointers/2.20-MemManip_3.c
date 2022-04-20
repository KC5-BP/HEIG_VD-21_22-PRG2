/*
 -----------------------------------------------------------------------------------
 Nom du fichier : 2.20-MemManip_3.c
 Auteur(s)      : (\_/)
 Date creation  : <jj.mm.aaaa>

 Description    : 2.20
                     Que va afficher à l'exécution le programme C suivant ?

 Remarque(s)    : <� compl�ter>

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char str[] = "memmove est tres utile......";
    memmove(str + 17, str + 12, 10);
    printf("%s\n", str);
    return EXIT_SUCCESS;
}

// Output :
//memmove est tres tres utile.
