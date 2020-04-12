#include <string.h>
#include "ABR_TP.h"

NOEUD * insere_mot(NOEUD * noeud, char * word, int index){
    if(noeud){
        // Il existe au moins une lettre sur ce niveau
        if (noeud->valeur == word[index]){
            // La lettre que l'on veut et celle de notre neud
            printf("Lettre trouvée    %c (%d ieme)\n", word[index], index);
            noeud->gauche = insere_mot(noeud->gauche, word, index + 1);
        } else {
            // On vérifie que notre lettre n'ai pas sa place avant la prochaine
            if (noeud->droit){
                if (noeud->droit->valeur > word[index]){
                    // Notre lettre viens après le noeud courant
                    NOEUD * noeud_tmp = noeud->droit;
                    noeud->droit = malloc(sizeof(NOEUD));
                    noeud->droit->valeur = word[index];
                    noeud->droit->droit = noeud_tmp;
                    noeud->droit->gauche = insere_mot(noeud->droit->gauche, word, index + 1);
                } else {
                    printf("Changement sur le prochain frère\n");
                    noeud->droit = insere_mot(noeud->droit, word, index);
                }
            } else {
                printf("Changement sur le prochain frère\n");
                noeud->droit = insere_mot(noeud->droit, word, index);
            }
        }
    }else{
        //Rien sur ce noeud, on ajoute la lettre
        printf("Ajout du caratère %c (%d ieme)\n", word[index], index);
        noeud = malloc(sizeof(NOEUD));
        noeud->valeur = word[index];
        // + 1 car il y a le \0
        if(index < (int) strlen(word)){
            noeud->gauche = insere_mot(noeud->gauche, word, index + 1);
        }
        return noeud;
    }
    return noeud;
}

int main(){
    NOEUD * arbre = arbre_vide();
    arbre = insere_mot(arbre, "ca", 0);
    arbre = insere_mot(arbre, "ce", 0);

    arbre = insere_mot(arbre, "de", 0);
    arbre = insere_mot(arbre, "du", 0);
    arbre = insere_mot(arbre, "ceci", 0);
    arbre = insere_mot(arbre, "cela", 0);

    affiche_arbre(arbre, 2);

    parcours_prefixe(arbre);
    printf("\n");
    // arbre = insere_mot(arbre, "de");
    // arbre = insere_mot(arbre, "ce");
    // affiche_arbre(arbre, 2);
    return 0;
}
