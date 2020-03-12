#include <stdio.h>
#include <stdlib.h>
#include "file.h"

int main(int argc, char** args){
    File f = file_vide();
    if( est_vide(f)){
        printf("file vide\n");
    }

    f = enfiler(1, f);

    affiche_file("", f);

    

    return 0;
}