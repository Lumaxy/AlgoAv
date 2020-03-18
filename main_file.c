#include <stdio.h>
#include <stdlib.h>
#include "file.h"

void test_nb_occ() {
    File f = file_vide();
    
    int compte = 1;

    f = enfiler(1, f);
    f = enfiler(6, f);
    f = enfiler(7, f);
    f = enfiler(5, f);
    f = enfiler(7, f);
    f = enfiler(1, f);

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
    /**
     * TP 1 : Files d'attente
     */ 

    // test_fonctionnement();

    // test_max_file();

    // test_min_et_max_file();
    
    //test_interclassement();
    //test_max_file();

    //test_nb_occ();

    /**
     * TP 2 : ABR
     */

    return 0;
}
