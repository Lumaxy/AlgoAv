#include <stdio.h>
#include <stdlib.h>
#include "ABR_TP.h"
#include "file.h"

typedef NOEUD* element;

int parcours_largeur(NOEUD * noeud){
    int n_noeud = 0;
    File *file = file_vide();
    
    file = enfiler(file, noeud);

    //while(

    return n_noeud;
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
    printf("%d ", noeud->valeur);
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
        n_noeud += parcours_sufixe(noeud->gauche);
    }
    if (noeud->droit != NULL){
        n_noeud += parcours_sufixe(noeud->droit);
    } 
    printf("%d ", noeud->valeur);

    return n_noeud; 
} 

NOEUD *arbre_vide() {return NULL; }

NOEUD *insere(NOEUD *p, element x) {
    if (p == NULL) {
        p = (NOEUD *) malloc(sizeof(NOEUD));
        p->valeur = x;
	p->gauche = NULL;
	p->droit = NULL;
    } else if (x == p->valeur) {
    	printf("%d est deja dans l'arbre\n", x);
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
        affiche_arbre(p->droit,col+1);
        for (i=0;i<col;i++) printf("   ");
        printf("%d\n",p->valeur);
        affiche_arbre(p->gauche,col+1);
    }  	
}
/*
int main_prof() {
    NOEUD *a[3];  //on peut travailler sur 3 arbres
    char c;
    int i, j;
    element x;
    char nom_fich[20];
    FILE *fich;

    do { 
        printf("Commande ? "); c = getchar();
        switch(c) {
            case 'v' : scanf("%d",&i); a[i] = arbre_vide(); break;     
            case 'i' : scanf("%d %d",&x,&i); a[i] = insere(a[i],x); break;    
            case 'a' : scanf("%d",&i); affiche_arbre(a[i],1); break;           
            case 'q' : exit(0); 
        }
        printf("\n"); c = getchar();
    }
    while (1);
    }

 */
