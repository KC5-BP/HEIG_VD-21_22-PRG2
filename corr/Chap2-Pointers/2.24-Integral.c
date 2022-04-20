/*
 -----------------------------------------------------------------------------------
 Nom du fichier : 2.24-Integral.c
 Auteur(s)      : (\_/)
 Date creation  : <jj.mm.aaaa>

 Description    : 2.24
                     Tester votre fonction d'intégration en écrivant un petit
                     programme permettant de calculer :
                              INF
                            .--.
                           /        2
                          /      -x            sqrt(PI)
                         /     e        dx  = ----------- = 0.886227
                     '--'                          2
                      0
                     Ainsi que :
                              PI / 2
                            .--.
                           /
                          /    sin( x ) dx  = 1
                         /
                     '--'
                      0

                     (  How's that I'm shitting myself ?!?
                        I dunno what you' talkin' about ?  )

 Remarque(s)    : <� compl�ter>

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/

#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define PI 3.141592654

/* Fonction à intégrer */
double f(double x);
/* Calcul d'une intégrale par la méthode des trapèzes */
double integrale(double (* f)(double), double a, double b, unsigned nbPas);

int main(void) {
    printf("integrale de exp(-x*x) entre 0 et infini = %g\n",
           integrale(f, 0, 20, 1000));

    printf("integrale de sin(x) entre 0 et pi/2 = %g\n",
           integrale(sin, 0, PI / 2, 1000));

    return EXIT_SUCCESS;
}

double f(double x) {
    return exp(-x * x);
}

double integrale(double (* f)(double), double a, double b, unsigned nbPas) {
    assert(f != NULL);
    assert(a < b);
    assert(nbPas > 0);
    const double PAS = (b - a) / nbPas; // pas d'intégration
    double x = a;
    double surface = 0.0;

    for (unsigned i = 0; i < nbPas; ++i, x += PAS)
        surface += 0.5 * PAS * (f(x) + f(x + PAS));

    return surface;
}

// Output :
//integrale de exp(-x*x) entre 0 et infini = 0.886227
//integrale de sin(x) entre 0 et pi/2 = 1
