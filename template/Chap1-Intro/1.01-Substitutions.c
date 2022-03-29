// Exo 1.1 : Donnee ;
//                   Indiquer ce que va afficher le code suivant ..
#include <stdio.h>
#include <stdlib.h>

#define A 1
#define B 2
#define AB 3
#define F(X,Y) X##Y

int main(void) {
   int n = AB;

   //printf("%<?>\n", n);
   printf("%d\n", n);

   //printf("%<?>\n", "AB");
   printf("%s\n", "AB");

   //printf("%<?>\n", F(A, B));
   printf("%d\n", F(A, B));

   return EXIT_SUCCESS;
}
