/*
 -----------------------------------------------------------------------------------
 Nom du fichier : 1.08-BinaryViewOfInt.c
 Auteur(s)      : (\_/)
 Date creation  : <jj.mm.aaaa>

 Description    : 1.08
                     Sans if et en utilisant seulement operateurs de manip. de bits,
                     implementez la fn dont le prototype et la semantique sont
                     definis comme suit :
void decimalToBinary(int32_t n, int8_t binary[]);

                     Semantique :
                        Convertit en binaire le nbr entier decimal << n >> et place
                        le resultat dans le tableau << binary >>.

 Remarque(s)    : <� compl�ter>

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define INT32_T_SIZE sizeof(int32_t) * 8

void decimalToBinary(int32_t n, int8_t binary[]);
void display(const int8_t binary[], size_t size);
void test(int32_t n);

int main(void) {
    printf("12345678901234567890123456789012\n");
    printf("--------------------------------\n");
    test(0);
    test(1);
    test(10);
    test(-1);
    test(INT32_MIN);
    test(INT32_MAX);

    return EXIT_SUCCESS;
}

void decimalToBinary(int32_t n, int8_t binary[]) {
    for (int i = INT32_T_SIZE; i > 0; --i) {
        binary[i - 1] = n & 1;
        n >>= 1;
    }
}
// Alternative (from Teacher too) :
/*
void decimalToBinary(int32_t n, int8_t binary[]) {
   for (int i = 0; i < INT32_T_SIZE; ++i)
      binary[INT32_T_SIZE - i - 1] = n >> i & 1;
}
 */

void display(const int8_t binary[], size_t size) {
    for (size_t i = 0; i < size; ++i)
        printf("%d", binary[i]);    // OR printf("%" PRId8, binary[i])
                                    // But replace <stdint.h> with <inttypes.h>
    printf("\n");
}

void test(int32_t n) {
    int8_t binary[INT32_T_SIZE];
    decimalToBinary(n, binary);
    display(binary, INT32_T_SIZE);
}

// Output :
//12345678901234567890123456789012
//--------------------------------
//00000000000000000000000000000000
//00000000000000000000000000000001
//00000000000000000000000000001010
//11111111111111111111111111111111
//10000000000000000000000000000000
//01111111111111111111111111111111
