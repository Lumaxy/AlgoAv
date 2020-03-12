#include <stdio.h>
#include <stdlib.h>
#include "file.h"

void test_nb_occ() {

    File f = file_vide();
    int compte = 3;

    f = enfiler(2, f);
    f = enfiler(1, f);
    f = enfiler(2, f);
    f = enfiler(3, f);
    f = enfiler(2, f);
    f = enfiler(3, f);
    f = enfiler(5, f);

    affiche_file("File :", f);

    printf("\nNombre d'occurences de %d : %d\n", compte, nb_occ(f, compte));
}

int main(int argc, char** args){

    test_nb_occ();

    return 0;
}