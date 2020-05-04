#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "L_ADJ.h"
#include "file.h"

T_CELLULE * creer_cellule(int extr, T_CELLULE *suiv) {
	T_CELLULE *p;

	p = (T_CELLULE *) malloc(sizeof(T_CELLULE));
	if (p == NULL){
		exit(EXIT_FAILURE);
	}
	p->extremite = extr;
	p->suivant = suiv;
	return p;
}

void affiche_liste(T_CELLULE *p) {
	while (p) {
		printf("<%d>\t", p->extremite);
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

T_LADJ lire_fichier(char * nom_fichier, char *** liste_nom_taches, int ** durees_taches){
	T_LADJ g;
	int nombre_sommet, nombre_arete;
	FILE *fp;
	int i, origine, ext, sommet;
	T_CELLULE *p;

	fp = fopen(nom_fichier, "rt");
	if (fp == NULL) {
		printf("Erreur lors de la lecture du fichier.\n");
		exit(EXIT_FAILURE);
	}
	fscanf(fp, "%d %d\n", &nombre_sommet, &nombre_arete);

	*liste_nom_taches = (char **) calloc(nombre_sommet, sizeof(char*));
	*durees_taches = (int *) calloc(nombre_sommet, sizeof(int));

	if (*liste_nom_taches == NULL || *durees_taches == NULL){
		exit(EXIT_FAILURE);
	}

	g = init_ladj(nombre_sommet, nombre_arete);
	for (i = 0; i < nombre_arete; i++) {
		fscanf(fp, "%d %d\n", &origine, &ext);
		p = creer_cellule(ext, g.tab[origine]);
		g.tab[origine] = p;
		g.nombre_predecesseurs[ext]++;
	}

	for (i = 0; i < nombre_sommet; i++){
		char tmp[50];
		int duree_tmp;
		fscanf(fp, "%d %d %s\n", &sommet, &duree_tmp, tmp);
		(*liste_nom_taches)[sommet] = (char*) malloc(sizeof(char) * strlen(tmp) + 1);
		memcpy((*liste_nom_taches)[sommet], tmp, strlen(tmp) + 1);
		(*durees_taches)[sommet] = duree_tmp;
	}

	int tache_alpha = 0, tache_omega = 0;

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
			q = creer_cellule(i, g_inverse.tab[p->extremite]);
			g_inverse.tab[p->extremite] = q; /* on empile */
			g_inverse.nombre_predecesseurs[i]++;

			p = p->suivant;
		}
	}
	return g_inverse;
}

int marquage_topologique(T_LADJ graph, File * marquage_topologique_l){
	int i;
	int encore;
	T_CELLULE *pointeur;
	Cellule * pointeur_file;
	int position;
	int nombre_sommet_supprimes = 0;

	do {
		encore = 0;
		for (i = 0; i < graph.nbsom; i++){
			if (graph.nombre_predecesseurs[i] <= 0 && !contient(i, *marquage_topologique_l)){
				enfiler2(i, marquage_topologique_l);

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

	pointeur_file = marquage_topologique_l->t;

	position = 1;
	while (pointeur_file != NULL){
		printf("%d:%d ", position++, pointeur_file->valeur);
		pointeur_file = pointeur_file->suivant;
	}
	printf("\n");

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
