#include <stdio.h>
#include <stdlib.h>
#include "file.h"


File file_vide(void){
    File f = {NULL,NULL};
    return f;
}

int est_vide(File f) {
    return !f.t;
}
element tete(File f) {
    if (est_vide(f)) {
        printf("Erreur - file vide\n");
        exit(-1);
    }
    return f.t->valeur;
}

File enfiler(element e, File f){
    Cellule *pc = (Cellule *) malloc(sizeof(Cellule));
    pc->valeur = e;
    pc->suivant = NULL;

    if (est_vide(f)){
        f.t = f.q = pc;
    } else {
        f.q = f.q->suivant = pc;
    }
    return f;
}

File defiler(File f){
    Cellule *pc = f.t;
    if (est_vide(f)) {
        printf("Erreur - file vide\n");
        exit(-1);
    }

    if (f.t == f.q) {
        f = file_vide();
    } else {
        f.t = f.t->suivant;
    }
    free(pc);
    return f;
}

element defiler2(File *f) {
    element e;
    Cellule *pc=f->t;

    if (est_vide(*f)) {
        printf("Erreur - file vide\n");
        exit(-1);
    }
    e = f->t->valeur;
    if (f->t == f->q) {
        *f = file_vide();
    } else {
        f->t = f->t->suivant;
    }
    free(pc);
    return e;
}

void concat(File *f1, File *f2){
    if (f1->t == NULL) {
        *f1 = *f2;
    } else if (f2->t != NULL) {
        f1->q->suivant = f2->t;
        f1->q = f2->q;
    }
    *f2 = file_vide();
}

void affiche_file(char *msg, File f) {
    Cellule *p;
    int compteur = 0;
    p = f.t;
    printf("%s\n",msg);
    while (p != NULL){
        printf("%6d", p->valeur);
        compteur++;
        if ((compteur % 10) == 0) {
            printf("\n");
        }
        p = p->suivant;
    }
    printf("\n");
}

int contient(element element, File file){
    Cellule *pointeur;

    pointeur = file.t;

    while (pointeur != NULL){
        if (pointeur->valeur == element){
            return 1;
        }
        pointeur = pointeur->suivant;
    }
    return 0;
}

void free_file(File *file){
    while(!est_vide(*file)){
        defiler2(file);
    }
}
