/*****************************************************************************/
/*   C. PORQUET                     ABR_TP.c                   Novembre 2012 */
/*                      Arbres binaires de recherche                         */
/*****************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct noeud {
	element valeur;
	struct noeud *gauche, *droit;
	} NOEUD, *ABR;

NOEUD *arbre_vide();

NOEUD *insere(NOEUD *p, element x);

void affiche_arbre(NOEUD *p, int col);

/* Retourne le nombre de feuille de l'arbre */
int nombre_feuilles(NOEUD * arbre);

/* Retourne le nombre de noeud */
int parcours_prefixe(NOEUD * arbre);

/* retourne le nombre de noeud */
int parcours_suffixe(NOEUD * arbre);

/* Renvoie le nombre de noeud */
int parcours_largeur(NOEUD * arbre);
