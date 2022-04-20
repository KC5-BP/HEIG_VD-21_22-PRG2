/*
 -----------------------------------------------------------------------------------
 Nom du fichier : 2.06-PtrAffect.c
 Auteur(s)      : (\_/)
 Date creation  : <jj.mm.aaaa>

 Description    : 2.06
                     Soient les déclarations suivantes :
                        ...
                     Quel sera dans un programme l'effet
                     des instructions suivantes :
                        ...

 Remarque(s)    : <� compl�ter>

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    // Var. dec. : ----------------------------------------------------------------->
    int i = 1, j = 2;

    int* pi1 = &i;
    int* pi2 = &j;

    double x = 3.0;
    double* pd = &x;

    void* pv;

    // Code : ---------------------------------------------------------------------->
    // 1) OK
    pi1 = pi2;
    //    pi1 points on the same integer as pi2

    // 2) WARNING : Assignment from incompatible pointer type (int* to double*)
    pd = pi1;
    //    But could write : pd = (double*) pi1;

    // 3) WARNING : Assignment from incompatible pointer type (double* to int*)
    pi1 = pd;
    //    But could write : pi1 = (int*) pd;
    //    Be aware that pt2 & 3 can lead to unexpected results when dereferencing.
    //    Ex. : printf("%d\n", *pi1); will not display 3.

    // 4) OK
    pv = pi1;
    //    pv contains now the address contained by pi1.
    //    But be careful : this address can't be used like so.
    //    For instance, after the assignation you write
    //      printf("%d\n", *pv); it will lead to a compilation error.
    //    But we could write : printf("%d\n", *((int*)pv));

    // 5) OK
    pv = &i;
    //    Same thoughts as 4)

    // 6) OK
    pv = pi1;
    pi2 = pv;
    //    In C (but not in C++), a void pointer can't be implicitly
    //    converted into another type.

    // 7) OK
    if (pi1 = pi2);
    //    Make pi1 points on the same address as pi2.
    //    Condition true if pi2 is not equal to NULL.

    return EXIT_SUCCESS;
}
