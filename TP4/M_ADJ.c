/**
* Par MORIN Maxence et SECHI Bahia
*/
#include "M_ADJ.h"

void afficher_matrice(Matrice matrice, int nombre_sommets){
    int i, j;
    for(i = 0; i < nombre_sommets; i++){
        for(j = 0; j < nombre_sommets; j++){
            printf("%d ", matrice[i][j]);
        }
        printf("\n");
    }
}

Matrice creer_matrice(int nombre_sommets, int valeur_initiale){
    Matrice matrice = (Matrice) malloc(nombre_sommets * sizeof(Ligne));
    int i, j;

    for(i = 0; i < nombre_sommets; i++){
        matrice[i] = (Ligne) malloc(nombre_sommets * sizeof(int));
    }

    for(i = 0; i < nombre_sommets; i++){
        for(j = 0; j < nombre_sommets; j++){
            matrice[i][j] = valeur_initiale;
        }
    }
    return matrice;
}

void free_matrice(Matrice matrice, int nombre_sommets){
    int indice_ligne;

    for (indice_ligne = 0; indice_ligne < nombre_sommets; indice_ligne++){
        free(matrice[indice_ligne]);
    }
    free(matrice);
}


Matrice lire_graph(char * nom_fichier, int * nombre_sommets){
    FILE * fichier = fopen(nom_fichier, "r");
    int nombre_aretes;
    int sommet_a, sommet_b;
    int i;

    if (!fichier){
        printf("Erreur durant l'ouverture du fichier\n");
        exit(EXIT_FAILURE);
    }

    fscanf(fichier, "%d %d\n", nombre_sommets, &nombre_aretes);
    Matrice matrice = creer_matrice(*nombre_sommets, 0);

    // Lecture du fichier et initialisation de la matrice
    for(i = 0; i < nombre_aretes; i++){
        fscanf(fichier, "%d %d\n", &sommet_a, &sommet_b);
        matrice[sommet_a][sommet_b] = 1;
        matrice[sommet_b][sommet_a] = 1;
    }

    fclose(fichier);
    return matrice;
}

int parcours_largeur(Matrice adjacence, int nombre_sommets){
    int * marques = (int *) malloc(sizeof(int) * nombre_sommets);
    File a_explorer = file_vide();
    int i;
    int somme = 0;
    int connexe = -1;

    for(i = 0; i < nombre_sommets; i++){
        marques[i] = 0;
    }

    while (somme < nombre_sommets) {
        connexe++;
        int sommet_debut = 0;
        while (marques[sommet_debut] == 1) {
            sommet_debut++;
        }
        printf("Composante : \n");
        a_explorer = enfiler(sommet_debut, a_explorer);
        while (!est_vide(a_explorer)){
            int pointeur = defiler2(&a_explorer);
            while (marques[pointeur] > 0 && !est_vide(a_explorer)){
                pointeur = defiler2(&a_explorer);
            }
            marques[pointeur] = 1;
            printf("%d ", pointeur);
            for (i = 0; i < nombre_sommets; i++){
                int arc = adjacence[pointeur][i];
                if (arc == 1 && marques[i] == 0 && !contient(i, a_explorer)){
                    a_explorer = enfiler(i, a_explorer);
                }
            }
        }
        int delta = somme;
        somme = 0;
        for (i = 0; i < nombre_sommets; i++){
            somme += marques[i];
        }
        printf("\n%d éléments.\n", somme - delta);
    }
    free(marques);
    return connexe;
}


void profondeur_prefixe(Matrice adjacence, int * marques, int sommet, int nombre_sommets){
    printf("%d ", sommet);
    marques[sommet] = 1;
    int potentiel_sommet;
    for (potentiel_sommet = 0; potentiel_sommet < nombre_sommets; potentiel_sommet++){
        if (potentiel_sommet != sommet && adjacence[sommet][potentiel_sommet] == 1 && marques[potentiel_sommet] == 0){
            profondeur_prefixe(adjacence, marques, potentiel_sommet, nombre_sommets);
        }
    }
}

void profondeur_suffixe(Matrice adjacence, int * marques, int sommet, int nombre_sommets){
    int potentiel_sommet;
    marques[sommet] = 1;
    for (potentiel_sommet = 0; potentiel_sommet < nombre_sommets; potentiel_sommet++){
        int sommet_possible = adjacence[sommet][potentiel_sommet];
        if (potentiel_sommet != sommet && sommet_possible == 1 && marques[potentiel_sommet] == 0){
            profondeur_suffixe(adjacence, marques, potentiel_sommet, nombre_sommets);
        }
    }
    printf("%d ", sommet);
}
/* Retourne 0 si le graph est connexe, un nombre positif sinon */
int afficher(void (* methode)(Matrice, int *, int, int), Matrice adjacence, int nombre_sommets){
    int * marques = (int*) malloc(sizeof(int) * nombre_sommets);
    int i;
    int connexe = -1;
    for(i = 0; i < nombre_sommets; i++){
        marques[i] = 0;
    }

    int somme = 0;
    while (somme < nombre_sommets) {
        connexe++;
        int sommet_debut = 0;
        while (marques[sommet_debut] == 1) {
            sommet_debut++;
        }
        printf("Composante : \n");
        methode(adjacence, marques, sommet_debut, nombre_sommets);
        int delta = somme;
        somme = 0;
        for (i = 0; i < nombre_sommets; i++){
            somme += marques[i];
        }
        printf("\n%d éléments.\n", somme - delta);
    }

    free(marques);
    return connexe;
}

int main(){
    Matrice adjacence;
    int nombre_sommets;
    int connexe;
    char filename[] = "graphe_alea.txt";
    adjacence = lire_graph(filename, &nombre_sommets);
    afficher_matrice(adjacence, nombre_sommets);

    printf("Nombre de sommet dans le graph : %d\n", nombre_sommets);

    printf("Préfixe : \n");
    connexe = afficher(profondeur_prefixe, adjacence, nombre_sommets);
    if (connexe == 0){
        printf("Le graph est connexe.\n");
    }else{
        printf("Le graph n'est pas connexe.\n");
    }

    printf("Suffixe : \n");
    connexe = afficher(profondeur_suffixe, adjacence, nombre_sommets);
    if (connexe == 0){
        printf("Le graph est connexe.\n");
    }else{
        printf("Le graph n'est pas connexe.\n");
    }

    printf("Parcours en largeur : \n");
    connexe = parcours_largeur(adjacence, nombre_sommets);
    if (connexe == 0){
        printf("Le graph est connexe.\n");
    }else{
        printf("Le graph n'est pas connexe.\n");
    }

    printf("Analyse de la complexité spatiale\n");
    printf("Taille en octets utilisé par la matrice d'adjacence : %ldu\n", (long int) (sizeof(int) * nombre_sommets) * sizeof(int) * nombre_sommets);

    free_matrice(adjacence, nombre_sommets);
    return 0;
}
