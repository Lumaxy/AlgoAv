#ifndef FILE_H
#define FILE_H

#include <stdio.h>
#include <stdlib.h>
#include "ABR_TP.h"

typedef NOEUD* element;

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

/* Libère la mémoire */
void free_file(File *file);
#endif
