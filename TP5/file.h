#ifndef FILE_H
#define FILE_H

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

/* Libère la mémoire */
void free_file(File *file);

/* Retourne 1 si element est dans la file, 0 sinon */
int contient(element element, File file);
#endif
