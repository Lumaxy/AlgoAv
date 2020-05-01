typedef struct t_cellule {
	int extremite;
	float valuation;
	struct t_cellule *suivant;
} T_CELLULE;

/* listes d'adjacence */
typedef struct t_ladj {
	int nbsom, nbar;
    int * nombre_predecesseurs;
	T_CELLULE **tab;
} T_LADJ;

T_CELLULE * creer_cellule(int extr, float val, T_CELLULE *suiv);
void affiche_liste(T_CELLULE *p);
T_LADJ init_ladj(int nsom, int nar);
void affiche_graphe(T_LADJ g);
T_LADJ charge_graphe(char *nom_fichier);
T_LADJ inverse(T_LADJ g);

int marquage_topologique(T_LADJ graph);
void free_liste_adjacence(T_LADJ * graph); 
