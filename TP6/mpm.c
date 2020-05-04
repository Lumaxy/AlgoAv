#include <stdio.h>
#include "file.h"
#include "L_ADJ.h"

void calcul_date_plus_tot(T_LADJ graph, T_LADJ predecesseurs, int **date_plus_tot, int * durees_taches){
    File marquage_topologique_l;
    Cellule *cellule_sommet;
    T_CELLULE *cell_predecesseur;
    int sommet;

    marquage_topologique_l = file_vide();
    marquage_topologique(graph, &marquage_topologique_l);
    cellule_sommet = marquage_topologique_l.t;
    while (cellule_sommet != NULL){
        sommet = cellule_sommet->valeur;
        if (predecesseurs.tab[sommet] != NULL){
            cell_predecesseur = predecesseurs.tab[sommet];
            int maximum = durees_taches[cell_predecesseur->extremite];
            while (cell_predecesseur != NULL){
                int valuation = durees_taches[cell_predecesseur->extremite] + (*date_plus_tot)[cell_predecesseur->extremite];
                if (valuation > maximum){
                    maximum = valuation;
                }
                cell_predecesseur = cell_predecesseur->suivant;
            }
            (*date_plus_tot)[sommet] = maximum;
        }else{
            // Sommet Alpha
            (*date_plus_tot)[sommet] = 0;
        }
        cellule_sommet = cellule_sommet->suivant;
    }
    free_file(&marquage_topologique_l);
}

void calcul_date_plus_tard(T_LADJ graph, T_LADJ predecesseurs, int **date_plus_tard, int duree_travaux, int * durees_taches){
    File marquage_topologique_l;
    Cellule *cellule_sommet;
    T_CELLULE *cell_predecesseur;
    int sommet;

    marquage_topologique_l = file_vide();
    marquage_topologique(predecesseurs, &marquage_topologique_l);

    cellule_sommet = marquage_topologique_l.t;
    while (cellule_sommet != NULL){
        sommet = cellule_sommet->valeur;

        if (graph.tab[sommet] == NULL){
            // Sommet oméga
            (*date_plus_tard)[sommet] = duree_travaux;
        }else{
            cell_predecesseur = graph.tab[sommet];
            int minimum = (*date_plus_tard)[cell_predecesseur->extremite] - durees_taches[sommet];
            while (cell_predecesseur != NULL){
                int valuation = (*date_plus_tard)[cell_predecesseur->extremite] - durees_taches[sommet];
                if (valuation < minimum){
                    minimum = valuation;
                }
                cell_predecesseur = cell_predecesseur->suivant;
            }
            (*date_plus_tard)[sommet] = minimum;
        }


        cellule_sommet = cellule_sommet->suivant;
    }
    free_file(&marquage_topologique_l);
}

int main() {
    T_LADJ graph, predecesseurs;
    char filename[] = "TP6/exemple1.txt";
    char ** liste_nom_taches = NULL;
    int * durees_taches;
    int *date_plus_tot, *date_plus_tard;
    int i;

    graph = lire_fichier(filename, &liste_nom_taches, &durees_taches);
    predecesseurs = inverse(graph);

    date_plus_tot = (int*) calloc(graph.nbsom, sizeof(int));
    date_plus_tard = (int*) calloc(graph.nbsom, sizeof(int));

    printf("Graph : \n");
    affiche_graphe(graph);

    calcul_date_plus_tot(graph, predecesseurs, &date_plus_tot, durees_taches);
    calcul_date_plus_tard(graph, predecesseurs, &date_plus_tard, date_plus_tot[graph.nbsom - 1], durees_taches);

    printf("\nTâche\t\tau plus tôt\tau plus tard\n");
    for(i = 0; i < graph.nbsom; i++){
        printf("%s\t\t%d\t\t%d\t\t%s\n",
               liste_nom_taches[i],
               date_plus_tot[i],
               date_plus_tard[i],
               date_plus_tot[i] == date_plus_tard[i] ? "Critique !" : "");
    }

    /* FREE */
    free(date_plus_tot);
    free(date_plus_tard);
    for(i = 0; i < graph.nbsom; i++){
        free(liste_nom_taches[i]);
    }
    free(durees_taches);
    free(liste_nom_taches);
    free_liste_adjacence(&graph);
    free_liste_adjacence(&predecesseurs);
    return 0;
}
