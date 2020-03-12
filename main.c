#include <stdio.h>
#include <stdlib.h>
#include "file.h"

void test_fonctionnement(){
    File f = file_vide();
    if( est_vide(f)){
        printf("file vide\n");
    }

    f = enfiler(1, f);

    defiler2(&f);

    affiche_file("file : ", f);
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

int main(int argc, char** args){
    //test_fonctionnement();

    test_max_file();

    return 0;
}