#include <stdio.h>
#include <stdlib.h>
#include "L_ADJ.h"
#include "file.h"


T_CELLULE * creer_cellule(int extr, float val, T_CELLULE *suiv) {
	T_CELLULE *p;

	p = (T_CELLULE *) malloc(sizeof(T_CELLULE));
	if (p == NULL){
		exit(EXIT_FAILURE);
	}
	p->extremite = extr;
	p->valuation = val;
	p->suivant = suiv;
	return p;
}

void affiche_liste(T_CELLULE *p) {
	while (p) {
		printf("<%5d - %5.1f>\t", p->extremite, p->valuation);
		p = p->suivant;
	}
	printf("\n");
}

/* allocation dynamique et initialisation */
T_LADJ init_ladj(int nsom, int nar) {
	T_LADJ g;

	g.nbsom = nsom;
	g.nbar = nar;
	g.tab = (T_CELLULE **) calloc(nsom, sizeof(T_CELLULE *));
	if (g.tab == NULL) {
		exit(EXIT_FAILURE);
	}
	g.nombre_predecesseurs = (int *) calloc(nsom, sizeof(int));
	if (g.nombre_predecesseurs == NULL) {
		exit(EXIT_FAILURE);
	}
	return g;
}

void affiche_graphe(T_LADJ g) {
	int i;

	for (i = 0; i < g.nbsom; i++){
		if (g.tab[i]) {
			printf("%d prédécesseurs. Successeurs de %d : ", g.nombre_predecesseurs[i], i);
			affiche_liste(g.tab[i]);
		} else {
			printf("%d prédécesseurs. Successeurs de %d : Aucun\n", g.nombre_predecesseurs[i], i);
		}
	}
	printf("\n");
}

T_LADJ charge_graphe(char *nom_fichier){
	T_LADJ g;
	int nsom, nar;
	FILE *fp;
	int i, ori, ext;
	float val;
	T_CELLULE *p;

	fp = fopen(nom_fichier, "rt");
	if (fp == NULL) {
		exit(EXIT_FAILURE);
	}
	fscanf(fp, "%d %d\n", &nsom, &nar);
	g = init_ladj(nsom, nar);
	for (i = 0; i < nar; i++) {
		fscanf(fp, "%d %d %f\n", &ori, &ext, &val);
		p = creer_cellule(ext, val, g.tab[ori]);
		g.tab[ori] = p;
		g.nombre_predecesseurs[ext]++;
	}
	fclose(fp);
	return g;
}

T_LADJ inverse(T_LADJ g) {
	T_LADJ g_inverse;
	int i;
	T_CELLULE *p, *q;

	g_inverse = init_ladj(g.nbsom, g.nbar);
	for (i = 0; i < g.nbsom; i++) {
		p = g.tab[i];
		while (p) {
			q = creer_cellule(i, p->valuation, g_inverse.tab[p->extremite]);
			g_inverse.tab[p->extremite] = q; /* on empile */
			g_inverse.nombre_predecesseurs[i]++;

			p = p->suivant;
		}
	}
	return g_inverse;
}

int marquage_topologique(T_LADJ graph){
	File sans_predecesseurs;
	int i;
	int encore;
	T_CELLULE *pointeur;
	Cellule * pointeur_file;
	int position;
	int nombre_sommet_supprimes = 0;
	sans_predecesseurs = file_vide();

	do {
		encore = 0;
		for (i = 0; i < graph.nbsom; i++){
			if (graph.nombre_predecesseurs[i] <= 0 && !contient(i, sans_predecesseurs)){
				sans_predecesseurs = enfiler(i, sans_predecesseurs);

				// Supression virtuel du sommet
				pointeur = graph.tab[i];
				while (pointeur != NULL){
					graph.nombre_predecesseurs[pointeur->extremite]--;
					pointeur = pointeur->suivant;
				}
				nombre_sommet_supprimes++;
				encore = 1;
			}
		}
	} while (encore == 1);

	pointeur_file = sans_predecesseurs.t;

	position = 1;
	while (pointeur_file != NULL){
		printf("%d:%d ", position++, pointeur_file->valeur);
		pointeur_file = pointeur_file->suivant;
	}
	printf("\n");

	free_file(&sans_predecesseurs);
	return graph.nbsom == nombre_sommet_supprimes;
}
void free_liste_adjacence(T_LADJ * graph){
	int i;
	T_CELLULE *pointeur, *tmp;
	free(graph->nombre_predecesseurs);

	for(i = 0; i < graph->nbsom; i++){
		pointeur = graph->tab[i];
		while (pointeur != NULL) {
			tmp = pointeur->suivant;
			free(pointeur);
			pointeur = tmp;
		}
	}
	free(graph->tab);
}

int main(int argc, char **argv) {
	T_LADJ g, g_inverse;
	int possible;

	if (argc != 2){
		exit(EXIT_FAILURE);
	}

	g = charge_graphe(argv[1]);
	printf("Graph : \n");
	affiche_graphe(g);

	g_inverse = inverse(g);
	printf("Graph inversé : \n");
	affiche_graphe(g_inverse);

	printf("Marquage topologique : \n");
	possible = marquage_topologique(g);
	if (possible == 0){
		printf("Marquage topologique impossible.\n");
	}else{
		printf("Marquage topologique possible.\n");
	}

	free_liste_adjacence(&g);
	free_liste_adjacence(&g_inverse);
	return 0;
}
