/*
 -----------------------------------------------------------------------------------
 Nom du fichier : 1.11-printf3.c
 Auteur(s)      : (\_/)
 Date creation  : <jj.mm.aaaa>

 Description    : 1.11
                     Completer le code de telle maniere, qu'il affiche :
                        i = 1
                        j = 4294967295

 Remarque(s)    : French comment are from the teacher's correction.

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

#define PRINT_VAR(VAR)  printf(#VAR " = %" PRIu64 "\n", (uint64_t) VAR)

int main(void) {
    size_t i = 1;
    uint32_t j = UINT32_MAX;

    // Si gcc 32 bits
    //printf("i = %u\n", i);
    //printf("i = %" PRIu32 "\n", i);
    //printf("i = %" PRIu64 "\n", (uint64_t) i);
    //printf("i = %" PRIuMAX "\n", (uintmax_t) i);

    // Si gcc 64 bits
    //printf("i = %" PRIu64 "\n", i);
    //printf("i = %" PRIuMAX "\n", i);
    //printf("i = %" PRIu64 "\n", (uint64_t) i);     // <-- IN COMMON WITH J
    //printf("i = %" PRIuMAX "\n", (uint64_t) i);

    //printf("j = %u\n", j);
    //printf("j = %d\n", j);  // pas interdit mais ...
    //printf("j = %" PRIu8 "\n", j);
    //printf("j = %" PRIu16 "\n", j);
    //printf("j = %" PRIu32 "\n", j);  // mais pas PRIu64, ni PRIuMAX (warning!)
    //printf("j = %" PRIu64 "\n", (uintmax_t) j);    // <-- IN COMMON WITH I
    //printf("j = %" PRIuMAX "\n", (uint64_t) j);

    // Using a macros having the good format for both value
    PRINT_VAR(i);
    PRINT_VAR(j);

    return EXIT_SUCCESS;
}

// Output :
//i = 1
//j = 4294967295
