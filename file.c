#include <stdio.h>
#include <stdlib.h>
#include "file.h"


File file_vide(void)
{ File f={NULL,NULL};
  return f;
}

int est_vide(File f) {
  return !f.t; 
}
element tete(File f)
/* ATTENTION: consulter la t�te d'une File vide n'a pas de sens */
{ if (est_vide(f)) {printf("Erreur - file vide\n"); exit(-1); }
  return f.t->valeur;
/* la File n'est pas modifi�e */
}

File enfiler(element e,File f)
{ Cellule *pc=(Cellule *)malloc(sizeof(Cellule));
  pc->valeur=e;pc->suivant=NULL;
	
  if (est_vide(f))  f.t=f.q=pc;	/* la cellule cr��e est � la fois t�te et queue */
  else f.q=f.q->suivant=pc;	/* la cellule cr��e est la nouvelle queue	*/
	return f;
}

File defiler(File f)
/* ATTENTION: supprimer la t�te d'une File vide n'a pas de sens */
{ Cellule *pc=f.t;
  if (est_vide(f)) {printf("Erreur - file vide\n"); exit(-1); }

  if (f.t==f.q)	f=file_vide();	/* la File n'avait plus qu'une seule cellule */
  else f.t=f.t->suivant;	    /* la queue ne change pas */
  free(pc);	
  return f;
}

element defiler2(File *f)	/* ATTENTION: la File est modifi�e */
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

Cellule * max_file(File f){
  if(est_vide(f)){
    return 0;
  }

  Cellule * max_cell = f.t;
  Cellule * current_cell = f.t;
  while (current_cell != f.q){
    if (current_cell->valeur >= max_cell->valeur){
      max_cell = current_cell;
    }
    current_cell = current_cell->suivant;
  }
  
  return max_cell;
}

void min_et_max_file(File f, Cellule **pmin, Cellule **pmax){
  if(est_vide(f)){
    return;
  }
  *pmin = f.t;
  *pmax = f.t;
  Cellule *current = f.t;
  while (current != f.q){
    if (current->valeur >= (*pmax)->valeur){
      *pmax = current;
    }
    if (current->valeur <= (*pmin)->valeur){
      *pmin = current;
    }
    current = current->suivant;
  }
}

File interclassement(File f1, File f2){
  File f = file_vide();

  Cellule *c_f1 = f1.t, *c_f2 = f2.t;

  while(c_f1 != NULL || c_f2 != NULL){
    if(c_f1 == NULL) {
      f = enfiler(c_f2->valeur, f);
      c_f2 = c_f2->suivant;
    } else if (c_f2 == NULL){
      f = enfiler(c_f1->valeur, f);
      c_f1 = c_f1->suivant;
    } else {
      if(c_f1->valeur == c_f2->valeur){
        f = enfiler(c_f1->valeur, f);
        c_f1 = c_f1->suivant;
        c_f2 = c_f2->suivant;
      } else if(c_f1->valeur < c_f2->valeur){
        f = enfiler(c_f1->valeur, f);
        c_f1 = c_f1->suivant;
      } else if(c_f2->valeur < c_f1->valeur){
        f = enfiler(c_f2->valeur, f);
        c_f2 = c_f2->suivant;
      }
    }
  }
  return f;
}