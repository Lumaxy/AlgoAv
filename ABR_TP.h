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

/* Fait un parcours prefixe : Noeud, Gauche, Droite */
int parcours_prefixe(NOEUD * arbre);

/* Fait un parcours suffixe : Gauche, Droite, Noeud  */
int parcours_suffixe(NOEUD * arbre);

/* Effectue un parcours en largeur */
void parcours_largeur(NOEUD * arbre);
