// Exo 1.12 : Donnee ;
//                  Le code suivant est pleins d'erreurs et
//                  maladresses, corrigez les.
/*
#include <cstdio.h>
#include <cstdlib.h>
using namespace std;
int main() {
    int n, char c;
    printf("Donnez un nombre entier et un caractere : ");
    scanf("%d%c", n, c);
    printf("n = %d, c = %c\n", n, c);
    return EXIT_SUCCESS;
}
 */
#include <stdio.h>
#include <stdlib.h>

int main() {
	int n;
	char c;

	printf("Donnez un nombre entier et un caractere : ");
	scanf("%d%c", &n, &c);

	printf("n = %d, c = %c\n", n, c);

	return EXIT_SUCCESS;
}
