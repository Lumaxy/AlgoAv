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

int nombre_feuilles();

int nombre_noeuds();

void parcours_prefixe();

void parcours_suffixe();

void parcours_largeur();