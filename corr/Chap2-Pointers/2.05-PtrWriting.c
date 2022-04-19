/*
 -----------------------------------------------------------------------------------
 Nom du fichier : 2.05-PtrWriting.c
 Auteur(s)      : (\_/)
 Date creation  : <jj.mm.aaaa>

 Description    : 2.05
                     Ecrire les declarations C correspondant aux enonces suivantes :
                        1) t est un tableau de 10 pointeurs pointant chacun sur un
                           int constant.
                        2) t est un tableau de 10 pointeurs constants pointant
                           chacun sur un int.
                        3) p est un pointeur sur une fonction prenant en
                           paramètre un pointeur sur une fonction (prenant en
                           paramètre un double et livrant un double) et renvoyant
                           un pointeur sur int.
                        4) p est un pointeur constant sur un tableau de 10
                           pointeurs sur double.
                        5) t est un tableau de 10 pointeurs pointant chacun sur
                           une fonction prenant un double comme paramètre et
                           renvoyant un pointeur sur char.
                        6) f est une fonction prenant en paramètre un pointeur
                           constant sur char et renvoyant un pointeur constant
                           contenant l’adresse d’un pointeur sur char.
                        7) f est une fonction sans paramètre renvoyant un
                           pointeur sur un tableau de 10 pointeurs
                           constants sur char.

 Remarque(s)    : °  In brackets to create block and avoid getting problem about
                     declaring multiple times the same variable name.
                  °  Still, I got a declaration conflict between 7 with the so
                     saying f in 6.

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

/*
 * 1) Pointer     / Pointeurs
 * 2) Array       / Tableau
 * 3) Function    / Fonction
 */
int main(void) {
    {
        // 1) t est un tableau de 10 pointeurs pointant chacun sur un int constant.
        const int* t[10];
        // Dev. :
        //      t[10]
        //      const int *t[10]
    }
    {
        // 2) t est un tableau de 10 pointeurs constants pointant chacun sur un int.
        int const* t[10] /*= <initialisation>*/;
        // Dev. :
        //      t[10]
        //      int const *t[10]
    }
    {
        // 3) p est un pointeur sur une fonction prenant en paramètre un pointeur
        //    sur une fonction (prenant en paramètre un double et livrant un
        //    double) et renvoyant un pointeur sur int.
        int* (* p)(double (*)(double));
        // Dev. :
        //      *p          : p est un pointeur
        //      (*p)()      :  un pointeur sur fonction
        //      (*p)(double (*)(double))    :   un pointeur sur fonction prenant en
        //                                      paramètre un pointeur sur
        //                                      une fonction (prenant en paramètre
        //                                      un double et livrant un double)
        //      int* (*p)(double (*)(double))   : un pointeur sur fonction prenant
        //                                        en paramètre un pointeur sur une
        //                                        fonction (prenant en paramètre un
        //                                        double et livrant un double) et
        //                                        livrant un pointeur sur int.
    }
    {
        // 4) p est un pointeur constant sur un tableau de 10 pointeurs sur double
        double* (* const p)[10] /* = <initialisation> */; // 'Cause of the const p.
        // Dev. :
        //      (* const p) :   un pointeur constant
        //      double* (* const p)[10] : un pointeur constant sur un tableau de 10
        //                                pointeurs sur double.
    }
    {
        // 5) t est un tableau de 10 pointeurs pointant chacun sur une fonction
        //    prenant un double comme paramètre et renvoyant un pointeur sur char
        char* (* t[10])(double);
        // Dev. :
        //      *t[10] : un tableau de 10 pointeurs
        //      char* (*t[10]) (double) : un tableau de 10 pointeurs pointant
        //                                chacun sur une fonction prenant un double
        //                                en paramètre et retournant un pointeur sur
        //                                char.
    }
    {
        // 6) f est une fonction prenant en paramètre un pointeur constant sur char
        //    et renvoyant un pointeur constant contenant l’adresse d’un pointeur
        //    sur char
        char** const f(char* const);
        // Dev. :
        //      f(char* const)  :   une fonction prenant en paramètre un pointeur
        //                          constant sur char
        //      char** const f(char * const) : une fonction prenant en paramètre
        //                                     un pointeur constant sur char et
        //                                     retournant un pointeur constant
        //                                     contenant l’adresse d’un pointeur
        //                                     sur char.

    }
    {
        // 7) f est une fonction sans paramètre renvoyant un pointeur sur un tableau
        //    de 10 pointeurs constants sur char
        //char * const (* f(void))[10];
        char* const (* i(void))[10];
        // Dev. :
        //      * i(void)       :   une fonction sans paramètre et renvoyant un
        //                          pointeur
        //      (* i(void))[10] :   une fonction sans paramètre et renvoyant un
        //                          pointeur sur un tableau de 10 elements
        //      char * const (* i(void))[10]    :   une fonction sans paramètre et
        //                                          renvoyant un pointeur sur un
        //                                          tableau de 10 pointeurs
        //                                          constants sur char.
    }
    return EXIT_SUCCESS;
}
