#include <string.h>
// Pour la gestion de UTF-8
#include <locale.h>
#include "ABR_TP.h"

NOEUD * insere_mot(NOEUD * noeud, char * word, int index){
    if(noeud){
        // Il existe au moins une lettre sur ce niveau
        if (noeud->valeur == word[index]){
            // La lettre que l'on veut et celle de notre neud
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
                    noeud->droit = insere_mot(noeud->droit, word, index);
                }
            } else {
                noeud->droit = insere_mot(noeud->droit, word, index);
            }
        }
    }else{
        //Rien sur ce noeud, on ajoute la lettre
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

/**
 * @return 1 if found, 0 otherwise.
 */
int rechercher_mot(NOEUD * noeud, char * word, int index){
    if (noeud){
        if (index == (int) strlen(word) && noeud->valeur == '\0'){
            return 1;
        } else if (word[index] == noeud->valeur){
            return rechercher_mot(noeud->gauche, word, index + 1);
        } else {
            return rechercher_mot(noeud->droit, word, index);
        }
    } else {
        return 0;
    }
}

void test_insertion_arbre(){
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
}

void test_recherche_arbre(){
    NOEUD * arbre = arbre_vide();
    arbre = insere_mot(arbre, "ca", 0);
    arbre = insere_mot(arbre, "ce", 0);

    arbre = insere_mot(arbre, "de", 0);
    arbre = insere_mot(arbre, "du", 0);
    arbre = insere_mot(arbre, "ceci", 0);
    arbre = insere_mot(arbre, "cela", 0);

    printf("%d (1=Oui, 0=Non)\n", rechercher_mot(arbre, "ceci", 0));
}

void test_dictionnaire(){
    FILE * dico = fopen("dico/acronym.ang", "r");
    if (!dico){
        printf("Erreur durant l'ouverture du dictionnaire\n");
        exit(EXIT_FAILURE);
    }
    NOEUD * arbre_dico = arbre_vide();
    char * line = NULL;
    size_t len = 0;
    ssize_t read;
    while ((read = getline(&line, &len, dico)) != -1) {
        // Suppression du caractère \n
        char * word = malloc(sizeof(line) - sizeof(char));
        memcpy(word, line, sizeof(line) - sizeof(char));
        word[sizeof(word)/sizeof(char)] = '\0';
        arbre_dico = insere_mot(arbre_dico, word, 0);
    }
    int nombre_de_noeud = parcours_prefixe(arbre_dico);
    printf("\nMémoire utilisée = %ld\n", sizeof(NOEUD) * nombre_de_noeud);
    fclose(dico);
}

int main(){
    // Gestion de l'UTF-8
    setlocale(LC_ALL, "");

    // test_insertion_arbre();
    // test_recherche_arbre();
    // test_dictionnaire();

    return 0;
}
