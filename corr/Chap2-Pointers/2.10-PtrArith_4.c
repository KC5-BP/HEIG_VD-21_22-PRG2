/*
 -----------------------------------------------------------------------------------
 Nom du fichier : 2.10-PtrArith_4.c
 Auteur(s)      : (\_/)
 Date creation  : <jj.mm.aaaa>

 Description    : 2.10
                     Que va afficher le main ci-dessous ?

 Remarque(s)    : See 2.10-Details.pdf Details for a better view

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    const char* c[] = {"comprendre", "les", "pointeurs", "c\'est", "difficile"};
    const char** cp[] = {c, c + 2, c + 4, c + 1, c + 3};
    const char*** cpp = cp;
    int i;

    for (i = 0; i < 3; i++)
        printf("%c", *(**cpp + i));
                                    // *cpp => c
                                    // **cpp => "comprendre"
                                    // *(**cpp + 0) => 'c'
                                    // *(**cpp + 1) => 'o'
                                    // *(**cpp + 2) => 'm'
    printf("%c", *(*cp[0] + 2));
                                    // *cp[0] => "comprendre"
                                    // *cp[0] + 2 => "mprendre"
                                    // *(*cp[0] + 2) => 'm'
    printf("%s ", *cpp[2] + 8);
                                    // cpp[2] => c + 4
                                    // *cpp[2] => "difficile"
                                    // *cpp[2] + 8 => "e" => "%s " => "e "
    printf("%s ", *++*++cpp);
                                    // a) ++cpp => cp + 1 <=> &cp[1]
                                    // *++cpp => c + 2
                                    // c) ++*++cpp => ++(c + 2) => c + 3
                                    // *(c + 3) => "c\'est"  => "%s " => "c\'est "
                                    //
                                    // ! IMPORTANT !
                                    // During step a), cpp now point on
                                    //                         cp + 1 <=> &cp[1]
                                    // During step c), cp[1] now point on
                                    // c + 3 <=> &c[3]
    for (i = 1; i < 4; i++)
        printf("%c", *(cpp[-1][i % 3] + 2));
                                    // cpp[-1] <=> cp[0] => c
                                    // cpp[-1][i % 3] => c[i % 3] =>
                                    //    i = 1 : "les" => *(... +2)
                                    //                            => 's'
                                    //    i = 2 : "pointeurs" => *(... +2)
                                    //                            => 'i'
                                    //    i = 3 : "comprendre" => *(... +2)
                                    //                            => 'm'
    printf("%c", **--*cpp);
                                    // *cpp => c + 3
                                    // i) --*cpp => (c + 3) => c + 2
                                    // *--*cpp => "pointeurs"
                                    // **--*cpp => 'p'
                                    //
                                    // ! IMPORTANT !
                                    // During step i), cp[1] now point on
                                    // c + 2 <=> &c[2] again
    printf("%s\n", **++cpp + 7);
                                    // l) ++cpp => cp + 2 <=> &cp[2]
                                    // *++cpp => c + 4
                                    // **++cpp => "difficile"
                                    // **++cpp + 7 => "le"
                                    //
                                    // ! IMPORTANT !
                                    // During step l), cpp now point on
                                    //                         cp + 2 <=> &cp[2]
    return EXIT_SUCCESS;
}

// Output :
//comme c'est simple
