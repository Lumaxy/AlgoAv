#include "file.h"
typedef struct t_cellule {
	int extremite;
	struct t_cellule *suivant;
} T_CELLULE;

/* listes d'adjacence */
typedef struct t_ladj {
	int nbsom, nbar;
    int * nombre_predecesseurs;
	T_CELLULE **tab;
} T_LADJ;

T_CELLULE * creer_cellule(int extr, T_CELLULE *suiv);
void affiche_liste(T_CELLULE *p);
T_LADJ init_ladj(int nsom, int nar);
void affiche_graphe(T_LADJ g);
T_LADJ lire_fichier(char *nom_fichier, char *** liste_nom_taches, int ** durees_taches);
T_LADJ inverse(T_LADJ g);

int marquage_topologique(T_LADJ graph, File * marquage_topologique_l);
void free_liste_adjacence(T_LADJ * graph);
