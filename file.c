/******************************************************************************/
/* Christine PORQUET                 file.c                      Fevrier 2014 */
/******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct cellule {
	element valeur;
	struct cellule *suivant; } Cellule;
						
typedef struct file { 
	Cellule *t, *q; } File;	/* tete queue */


File file_vide(void) { 
  File f = {NULL,NULL};
  return f;
}

int est_vide(File f) { 
  return !f.t; 
  }

element tete(File f)
/* ATTENTION: consulter la tete d'une File vide n'a pas de sens */
{ if (est_vide(f)) {printf("Erreur - file vide\n"); exit(-1); }
  return f.t->valeur;
/* la File n'est pas modifiee */
}

File enfiler(element e,File f)
{ Cellule *pc=(Cellule *)malloc(sizeof(Cellule));
  pc->valeur=e;pc->suivant=NULL;
	
  if (est_vide(f))  f.t=f.q=pc;	/* la cellule creee est a la fois tete et queue */
  else f.q=f.q->suivant=pc;	/* la cellule creee est la nouvelle queue	*/
	return f;
}

File defiler(File f)
/* ATTENTION: supprimer la tete d'une File vide n'a pas de sens */
{ Cellule *pc=f.t;
  if (est_vide(f)) {printf("Erreur - file vide\n"); exit(-1); }

  if (f.t==f.q)	f=file_vide();	/* la File n'avait plus qu'une seule cellule */
  else f.t=f.t->suivant;	    /* la queue ne change pas */
  free(pc);	
  return f;
}

element defiler2(File *f)	/* ATTENTION: la File est modifiee */
/* ATTENTION: supprimer la t�te d'une File vide n'a pas de sens */
{ element e;
  Cellule *pc=f->t;
  
 if (est_vide(*f)) {printf("Erreur - file vide\n"); exit(-1); }
 e=f->t->valeur;
 if (f->t==f->q) *f=file_vide(); /* la File n'avait plus qu'une seule cellule */
 else f->t=f->t->suivant;        /* la queue ne change pas */
 free(pc);	
 return e;
}

void concat(File *f1, File *f2)
{if (f1->t == NULL) *f1 = *f2;
 else if (f2->t != NULL) {f1->q->suivant = f2->t;
                          f1->q = f2->q;
                         };
 *f2=file_vide();			       
}

void affiche_file(char *msg, File f)
{Cellule *p;
 int compteur = 0;
 p = f.t;
 printf("%s\n",msg);
 while (p != NULL) 
       {printf("%6d",p->valeur);
        compteur++;
        if ((compteur % 10) == 0) printf("\n");
        p = p->suivant;
       }
 printf("\n");       
}
