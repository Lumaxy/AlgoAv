#ifndef M_ADJ_H
#define M_ADJ_H
#include <stdio.h>
#include <stdlib.h>
#include "file.h"

typedef int ** Matrice;
typedef int * Ligne;

Matrice lire_graph(char * nom_fichier, int * nombre_sommets);

Matrice creer_matrice(int nombre_sommets, int valeur_initiale);
void afficher_matrice(Matrice, int nombre_sommets);

int afficher(void (*methode)(Matrice, int *, int, int), Matrice adjacence, int nombre_sommets);

void profondeur_prefixe(Matrice adjacence, int * marques, int sommet, int nombre_sommets);
void profondeur_suffixe(Matrice adjacence, int * marques, int sommet, int nombre_sommets);

int parcours_largeur(Matrice adjacence, int nombre_sommets);
void free_matrice(Matrice matrice, int nombre_sommets);
#endif
