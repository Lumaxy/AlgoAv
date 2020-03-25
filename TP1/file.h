#include <stdio.h>
#include <stdlib.h>
typedef int element;

typedef struct cellule {
	element	valeur;
	struct cellule *suivant;
} Cellule;

typedef struct file {
	Cellule *t, *q;
} File;

File file_vide(void);

int est_vide(File f);

element tete(File f);

File enfiler(element e,File f);

File defiler(File f);

element defiler2(File *f);

void concat(File *f1, File *f2);

void affiche_file(char *msg, File f);

/**
 * @param f la file a analyser
 * @param x l'element a chercher dans la file
 *
 * @return le nombre d'occurences de x dans la file
 * @return 0 si file vide
 */
int nb_occ(File f, int x);

/*
 * Renvoie la dernière occurence du max de la file. NULL si la file est vide
 */
Cellule * max_file(File f);

/**
 * Renvoie les dernière occurence du min et du max.
 * Ne change pas pmin et pmpax si la file est vide.
 */
void min_et_max_file(File f, Cellule **pmin, Cellule **pmax);

/**
 * Une  fonction  d’interclassementde  deux  files f1etf2triées
 * en  ordre  croissant  avec suppression des doublons.
 * Par exemple, si f1contient 1 2 4 6 7 8 9 et f2contient
 * 1 3 5 6, le résultat sera 1 2 3 4 5 6 7 8 9.
 * Votre fonction doit marcher quel que soit l’état
 * (vide / non vide) des deux files.
 * Ces dernières ne doivent pas être modifiées.
 */
File interclassement(File f1, File f2);
