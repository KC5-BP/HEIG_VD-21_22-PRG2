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

#define FILL_FROM_MSB_TO_LSB 0
#define FILL_FROM_LSB_TO_MSB 1
#define FILL_METHOD FILL_FROM_LSB_TO_MSB

void decimalToBinary(int32_t n, int8_t binary[]) {
	for (int i = 0; i < BIT_SIZE_32_BITS; ++i)
		#if FILL_METHOD == FILL_FROM_MSB_TO_LSB
		// [0, 1, ... , BIT-2, BIT-1] : MSB to LSB
		binary[i] = (n & (1 << (BIT_SIZE_32_BITS-i-1))) >> (BIT_SIZE_32_BITS-i-1);
		#elif FILL_METHOD == FILL_FROM_LSB_TO_MSB
		// [0, 1, ... , BIT-2, BIT-1] : LSB to MSB
		binary[i] = n >> i & 1;
		#endif
}
void printBinary(int8_t binary[]) {
	printf("0b");
	for (int i = 0; i < BIT_SIZE_32_BITS; ++i) {
		if (!(i % 4) && (i != 0))
			printf(" ");
		#if FILL_METHOD == FILL_FROM_MSB_TO_LSB
		printf("%d", binary[i]);
		#elif FILL_METHOD == FILL_FROM_LSB_TO_MSB
		printf("%d", binary[BIT_SIZE_32_BITS-i-1]);
		#endif
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
