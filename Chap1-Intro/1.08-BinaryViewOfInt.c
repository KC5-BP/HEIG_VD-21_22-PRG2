// Exo 1.8 : Donnee ;
//                  En utilisant au maximum les operateurs de manip. de bits,
//                  implementez la fn dont le prototype et la semantique
//                  sont definis comme suit :
//                                  void decimalToBinary(int32_t n, int8_t binary[]);
//                  Semantique :
//                                  Convertit en binaire le nbr entier decimal << n >>
//                                  Et place le resultat dans le tableau << binary >>.

#include <stdio.h>
#include <stdlib.h>

#define BIT_SIZE_32_BITS (sizeof(int32_t) * 8)

void decimalToBinary(int32_t n, int8_t binary[]) {
	for (int i = 0; i < BIT_SIZE_32_BITS; ++i)
		// [0, 1, ... , BIT-2, BIT-1] : MSB to LSB
		//binary[i] = (n & (1 << (BIT_SIZE_32_BITS-i-1))) >> (BIT_SIZE_32_BITS-i-1);
		// [0, 1, ... , BIT-2, BIT-1] : LSB to MSB
		binary[i] = n >> i & 1;
}
void printBinary(int8_t binary[]) {
	printf("0b");
	for (int i = 0; i < BIT_SIZE_32_BITS; ++i) {
		if (!(i % 4) && (i != 0))
			printf(" ");
		//printf("%d", binary[i]);
		printf("%d", binary[BIT_SIZE_32_BITS-i-1]);
	}
	printf("\n");
}

int main(void) {
	int8_t binary[BIT_SIZE_32_BITS] = {0};

	for(int32_t n = 0; n < 50; n+=5) {
		printf("n = %2d : ", n);
		decimalToBinary(n, binary);
		printBinary(binary);
	}

	return EXIT_SUCCESS;
}
