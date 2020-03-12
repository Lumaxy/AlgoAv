/*****************************************************************************/
/* C.PORQUET                        fawori.c                   Novembre 2003 */
/*             FAWORI : une representation des graphes orientes values       */
/* Attention: les sommets du graphe sont numérotés à partir de 1             */
/*****************************************************************************/
#include <stdio.h>
#include <stdlib.h>

typedef struct {	
  	   int extrem;
           float valuation;	
	} arc;
	
typedef struct {
	   int nbsom;
           int nbarc;
	   int *tab_som;
	   arc *tab_arc; 
	} graphe;

void alloue_graphe(int nbs, int nba, graphe *g)  
{ g->nbsom = nbs; g->nbarc = nba;
  g->tab_som = (int *)calloc(g->nbsom+2,sizeof(int));
  g->tab_arc = (arc *)calloc(g->nbarc+0,sizeof(arc));
}
	                   
void affiche_arc(arc a)
{ printf("(%4d - %7.2f)",a.extrem, a.valuation); }

void affiche_graphe(graphe g)
{ int i;
  printf("nombre de sommets = %d",g.nbsom);
  printf(" nombre d'arcs = %d\n",g.nbarc);
  printf("tableau des sommets = ");
  for (i=1;i<=g.nbsom+1;i++) printf("%4d\t",g.tab_som[i]); printf("\n");
  printf("tableau des arcs = ");
  for (i=0;i<g.nbarc;i++) affiche_arc(g.tab_arc[i]); printf("\n");  
}

void affiche_successeurs(int i,graphe g) 
/* affichage des successeurs du sommet i */
{ int j;
  printf("successeurs de %d = ",i);
  for (j=g.tab_som[i];j<g.tab_som[i+1];j++) affiche_arc(g.tab_arc[j]); 
  printf("\n");
}

void charge_graphe(char *nom_fich, graphe *g)
{FILE *fich;
 int nbs, nba, i, iarc, ori, ori_av;
  
 fich=fopen(nom_fich,"rt");
 fscanf(fich,"%d %d",&nbs,&nba);	
 
 /* les sommets du graphe sont numerotes a partir de 1 */
 /* on fait donc demarrer tab_som a l'indice 1         */
 /* en revanche tab_arc peut demarrer a l'indice 0     */
 alloue_graphe(nbs,nba,g);

 ori_av=0;   
 for (iarc = 0; iarc < g->nbarc ; iarc++)
     {fscanf(fich,"%d %d %f",&ori,&(g->tab_arc[iarc].extrem),
                                  &(g->tab_arc[iarc].valuation));
      if (ori != ori_av) {for (i = ori_av+1; i<= ori; i++) 
                               g->tab_som[i] = iarc;
                          ori_av = ori;
			 }
     }
 for (i= ori+1; i<= g->nbsom+1; i++) g->tab_som[i] = g->nbarc; 
 fclose(fich);
}

/************************************************************************/ 
int main()
{ graphe g;

 charge_graphe("pcc.txt",&g);

 affiche_graphe(g); 
	
 affiche_successeurs(1,g); 
 affiche_successeurs(4,g); 
 affiche_successeurs(5,g); 
 affiche_successeurs(6,g);  
}
/************************************************************************* 	

Le fichier pcc.txt - sur la premiere ligne, nbsom nbarc puis les arcs
ranges par ordre de numeros de sommet croissants
6 10
1 2 7
1 3 1
2 4 4
2 6 1
3 2 5
3 5 2
3 6 7
5 2 2
5 4 5
6 5 3

Trace d'execution
nombre de sommets = 6 nombre d'arcs = 10
tableau des sommets =    0         2       4       7       7       9      10
tableau des arcs = (  2 -   7.00)(  3 -   1.00)(  4 -   4.00)
(  6 -   1.00)(  2 -   5.00)(  5 -   2.00)(  6 -   7.00)(  2 -   2.00)
(  4 -   5.00)(  5 -   3.00)
successeurs de 1 = (   2 -    7.00)(   3 -    1.00)
successeurs de 4 = 
successeurs de 5 = (   2 -    2.00)(   4 -    5.00)
successeurs de 6 = (   5 -    3.00)

*************************************************************************/  
