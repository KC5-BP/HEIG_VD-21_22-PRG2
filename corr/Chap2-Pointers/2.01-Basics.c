/*
 -----------------------------------------------------------------------------------
 Nom du fichier : 2.01-Basics.c
 Auteur(s)      : (\_/)
 Date creation  : <jj.mm.aaaa>

 Description    : 2.01
                     Ecrire un programme C qui :
                        1) Declare une variable n de type int et l'initialise a 1
                        2) Declare un pointeur ptr pointant sur n
                        3) Affiche a l'ecran la valeur de l'objet pointe par ptr
                        4) Affiche a l'ecran l'adresse contenue dans ptr
                        5) Affiche l'adresse de ptr

 Remarque(s)    : French comment are from the teacher's correction.

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

#define PRINT_ADDRESS(ADR) printf("0x%" PRIxPTR "\n", (intptr_t) (ADR))

int main() {
    int n = 1;
    int *ptr = &n;

    // TEACHER'S SOLUTION ----------------------------------------------------------
    printf("%d\n", *ptr);
    PRINT_ADDRESS(ptr); // PRINT_ADDRESS(&n);
    PRINT_ADDRESS(&ptr);

    // Autres variantes (avec %p)
    printf("%d\n", *ptr);
    printf("%p\n", (void *) ptr);   // ou printf("%p", ptr);
                                    // ou printf("%p", &n);
    printf("%p\n", (void *) &ptr);  // ou printf("%p", &ptr);

    // COMPLEMENT TO CONFIRM ADDRESSES BETWEEN PTR CONTENT AND N -------------------
    printf("3) Valeur pointee  : %d\n", *ptr);
    printf("4) Address pointee (with ptr) : %p\n", (void *) ptr);
    printf("   Validation      (with  n ) : %p\n", (void *) &n);
    printf("5) Address pointer            : %p\n", (void *) &ptr);

    return EXIT_SUCCESS;
}
