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
#define FILL_METHOD FILL_FROM_MSB_TO_LSB

void decimalToBinary(int32_t n, int8_t binary[]) {
	#if FILL_METHOD == FILL_FROM_MSB_TO_LSB
	for (int i = BIT_SIZE_32_BITS-1; i >= 0; --i)	// [0, 1, ... , BIT-2, BIT-1] :
		binary[i] = n >> i & 1;								// MSB to LSB
	#elif FILL_METHOD == FILL_FROM_LSB_TO_MSB
	for (int i = 0; i < BIT_SIZE_32_BITS; ++i)	// [0, 1, ... , BIT-2, BIT-1] :
		binary[i] = n >> i & 1;							// LSB to MSB
	#endif
}
void printBinary(int8_t binary[]) {
	printf("0b");
	for (int i = BIT_SIZE_32_BITS-1; i >= 0 ; --i) {
		printf("%d", binary[i]);
		if ( !(i % 4) )	printf(" ");
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
