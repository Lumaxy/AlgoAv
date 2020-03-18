#include <stdio.h>
#include "ABR_TP.h"
#include <stdlib.h>
#include <time.h>
/**
 * @return a random tree with n_nodes number of node
 */
NOEUD * random_tree(int n_nodes){
    srand(time(NULL));
    NOEUD * result = NULL;
    int i;
    for(i = 0; i < n_nodes;i++){
	result = insere(result, rand() % 20); 
    }
    return result;
}

int main(){
    NOEUD * arbre = random_tree(10);

    affiche_arbre(arbre, 6);

    printf("--\n");

    printf("  [%d] noeud parcourus (prefixe).\n", parcours_prefixe(arbre)); 

    printf("--\n");

    printf("  [%d] noeud parcourus (sufixe).\n", parcours_sufixe(arbre)); 
    
    printf("--\n");

    printf("[%d] Nombre de feuilles\n", nombre_feuilles(arbre)); 

    return 0;
}
