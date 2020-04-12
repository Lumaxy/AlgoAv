#ifndef ABR_H
#define ABR_H
#include <stdio.h>
#include <stdlib.h>

typedef char element_arbre;

// Gauche = Fils
// Droit = frere
typedef struct noeud {
	element_arbre valeur;
	struct noeud *gauche, *droit;
} NOEUD, *ABR;

NOEUD *arbre_vide();

NOEUD *insere(NOEUD *p, element_arbre x);

void affiche_arbre(NOEUD *p, int col);

/* Retourne le nombre de feuille de l'arbre */
int nombre_feuilles(NOEUD * arbre);

/* Fait un parcours prefixe : Noeud, Gauche, Droite */
int parcours_prefixe(NOEUD * arbre);

/* Fait un parcours suffixe : Gauche, Droite, Noeud  */
int parcours_suffixe(NOEUD * arbre);

/* Effectue un parcours en largeur */
void parcours_largeur(NOEUD * arbre);
#endif
