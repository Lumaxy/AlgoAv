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

void test_max_file(){
    File f = file_vide();
    f = enfiler(1, f);
    f = enfiler(6, f);
    f = enfiler(7, f);
    f = enfiler(5, f);
    f = enfiler(7, f);
    f = enfiler(1, f);
    
    Cellule *max_cell = max_file(f);

    printf("max_value %d\n", max_cell->valeur);
}

int main(int argc, char** args) {

    test_max_file();

    test_nb_occ();

    return 0;
}