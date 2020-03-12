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

void test_min_et_max_file(){
    File f = file_vide();
    f = enfiler(1, f);
    f = enfiler(6, f);
    f = enfiler(7, f);
    f = enfiler(5, f);
    f = enfiler(7, f);
    f = enfiler(1, f);

    Cellule *pmin, *pmax;

    min_et_max_file(f, &pmin, &pmax);

    printf("min : %d max : %d\n", pmin->valeur, pmax->valeur);
}

void test_interclassement(){
    File f1 = file_vide();
    File f2 = file_vide();
    f1 = enfiler(1, f1);
    f1 = enfiler(2, f1);
    f1 = enfiler(4, f1);
    f1 = enfiler(6, f1);
    f1 = enfiler(7, f1);
    f1 = enfiler(8, f1);
    f1 = enfiler(9, f1);

    f2 = enfiler(1, f2);
    f2 = enfiler(3, f2);
    f2 = enfiler(5, f2);
    f2 = enfiler(6, f2);
    
    File result = interclassement(f1, f2);
    
    affiche_file("YOUPI : ", result);

}

int main(int argc, char** args){
    // test_fonctionnement();

    // test_max_file();

    // test_min_et_max_file();
    
    test_interclassement();
    
    return 0;
}