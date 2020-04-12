#include <stdio.h>
#include <stdlib.h>
#include "ABR_TP.h"
#include "file.h"

void parcours_largeur(NOEUD * noeud){
    // int n_noeud = 0;
    File file = file_vide();
    NOEUD *p;

    file = enfiler(noeud, file);

    while (!est_vide(file)) {
        p = defiler2(&file);
        printf("%c ", p->valeur);
        if (p->droit)
        {
            file = enfiler(p->droit, file);
        }

        if (p->gauche)
        {
            file = enfiler(p->gauche, file);
        }
    }
    printf("\n");
}

int nombre_feuilles(NOEUD * noeud){
    if(noeud->gauche == NULL && noeud->droit == NULL){
        return 1;
    }
    int n_feuilles = 0;
    if (noeud->gauche != NULL){
        n_feuilles += nombre_feuilles(noeud->gauche);
    }
    if (noeud->droit != NULL){
        n_feuilles += nombre_feuilles(noeud->droit);
    }
    return n_feuilles;
}


int parcours_prefixe(NOEUD * noeud){
    int n_noeud = 1;
    if (noeud->valeur == '\0'){
        printf("\\0 ");
    } else {
        printf("%c ", noeud->valeur);
    }
    if (noeud->gauche != NULL){
        n_noeud += parcours_prefixe(noeud->gauche);
    }
    if (noeud->droit != NULL){
        n_noeud += parcours_prefixe(noeud->droit);
    }

    return n_noeud;
}

int parcours_suffixe(NOEUD * noeud){
    int n_noeud = 1;
    if (noeud->gauche != NULL){
        n_noeud += parcours_suffixe(noeud->gauche);
    }
    if (noeud->droit != NULL){
        n_noeud += parcours_suffixe(noeud->droit);
    }
    printf("%c ", noeud->valeur);

    return n_noeud;
}

NOEUD *arbre_vide() {return NULL; }

NOEUD *insere(NOEUD *p, element_arbre x) {
    if (p == NULL) {
        p = (NOEUD *) malloc(sizeof(NOEUD));
        p->valeur = x;
        p->gauche = NULL;
        p->droit = NULL;
    } else if (x == p->valeur) {
        printf("%c est deja dans l'arbre\n", x);
    } else if (x < p->valeur) {
        p->gauche = insere(p->gauche,x);
    } else {
        p->droit  = insere(p->droit,x);
    }
    return(p);
}

void affiche_arbre(NOEUD *p, int col) {
    int i;
    if (p) {
        affiche_arbre(p->droit, col + 1);
        for (i = 0; i < col; i++){
            printf("   ");
        }
        if (p->valeur == '\0'){
            printf("\\0\n");
        } else {
            printf("%c\n", p->valeur);
        }
        affiche_arbre(p->gauche, col + 1);
    }
}
