/******************************************************************************/
/* Christine PORQUET                 file.c                      F�vrier 2014 */
/******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct cellule {
	element	valeur;
	struct cellule *suivant; 
} Cellule;
						
typedef struct file { 
	Cellule *t, *q; 
} File;	/* tete queue */


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