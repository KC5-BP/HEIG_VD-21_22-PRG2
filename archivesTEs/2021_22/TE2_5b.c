
// Under : Run > Edit Configurations ... > CMake Applications
//         > myprog > program arguments
// add the following : test.dat -opt1=10 src 10 -O2 20

#include <stdio.h>

#define VARIANTE 1

int main(int argc, char* argv[]) {
    printf("argc = %d\n", argc);

#if VARIANTE == 1
    for (int i = 0; i < argc; ++i)
#elif VARIANTE == 2
    for (int i = 0; argv[i] != NULL; ++i)
#endif
        printf("argv[%d] : %s\n", i, argv[i]);
    printf("\n");
}
