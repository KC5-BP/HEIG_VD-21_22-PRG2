/*
 -----------------------------------------------------------------------------------
 Nom du fichier : 3.05-StructSize.c
 Auteur(s)      : (\_/)
 Date creation  : <jj.mm.aaaa>

 Description    : 3.05
                    a) Soit la structure S1 suivante : (Voir code ci-dessous)
                        Quelle est la taille en bytes de S1
                            1) en architecture 32 bits ?
                            2) en architecture 64 bits ?

                    b) Soit la structure S2 suivante : (Voir code ci-dessous)
                        Quelle est la taille en bytes de S2
                            1) en architecture 32 bits ?
                            2) en architecture 64 bits ?

 Remarque(s)    : In memory, the largest value can be described as a word :
                  64b processor : 1 word <=> 64bits <=> 8B / 8o
                  32b processor : 1 word <=> 32bits <=> 4B / 4o
                  + Try yourself compiling in 32b with :
                  gcc -m32 path/to/3.05-StructSize.c -o path/to/output/3.05_32b.o

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

struct S1 {
    int* ptr;
    int32_t a;
    int64_t b;
};
// 32b :
/*
 * int* ptr;    32b
 * int32_t a;   32b
 * int64_t b;   64b
 * Total : 128b => 16B
 */

// 64b :
/*
 * int* ptr;    64b
 * int32_t a;   32b
 * int64_t b;   64b with 32b of padding before
 * Total : 192b => 24B
 */

struct S2 {
    int8_t a;
    int16_t b;
    char c;
    double* ptr;
};
// 32b :
/*
 * int8_t a;    8b
 * int16_t b;   16b with 8b of padding before
 * char c;      8b
 * double* ptr; 32b with 24b of padding before
 * Total : 96b => 12B
 */

// 64b :
/*
 * int8_t a;    8b
 * int16_t b;   16b with 8b of padding before
 * char c;      8b
 * double* ptr; 64b with 24b of padding before
 * Total : 128b => 16B
 */

int main(void) {
    printf("Architecture : %zubits\n", sizeof(void*) * 8);
    printf("sizeof(S1)   : %zu Bytes <=> %1$d octets\n", sizeof(struct S1));
    printf("sizeof(S2)   : %zu Bytes <=> %1$d octets\n", sizeof(struct S2));
    return EXIT_SUCCESS;
}

// Ouput :
//Architecture : 32bits
//sizeof(S1)   : 16 Bytes <=> 16 octets
//sizeof(S2)   : 12 Bytes <=> 12 octets
//Architecture : 64bits
//sizeof(S1)   : 24 Bytes <=> 24 octets
//sizeof(S2)   : 16 Bytes <=> 16 octets
