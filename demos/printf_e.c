#include <stdio.h>

int main(void) {
   double d1 = 1e-1;
   double d2 = 1e1;
   double d3 = 1e+01;
   double d4 = 1e99;
   double d5 = 1e100;
   printf("d1 = %e\n", d1);
   printf("d2 = %e\n", d2);
   printf("d3 = %e\n", d3);
   printf("d4 = %e\n", d4);
   printf("d5 = %e\n", d5);
}

// d1 = 1.000000e-01
// d2 = 1.000000e+01
// d3 = 1.000000e+01
// d4 = 1.000000e+99
// d5 = 1.000000e+100
