graph_2: TP5/L_ADJ.c TP5/L_ADJ.h TP5/file.h TP5/file.c
	gcc -o run TP5/L_ADJ.c TP5/L_ADJ.h TP5/file.h TP5/file.c -Wextra -Wall -pedantic -g

graph: TP4/M_ADJ.c TP4/M_ADJ.h TP4/file.h TP4/file.c
	gcc -o run TP4/M_ADJ.c TP4/M_ADJ.h TP4/file.h TP4/file.c -Wextra -Wall -pedantic -g

naire: TP3/main_naire.c TP3/ABR_TP.c TP3/ABR_TP.h TP3/file.h TP3/file.c dico/dico.fr
	gcc -o run TP3/main_naire.c TP3/ABR_TP.c TP3/ABR_TP.h TP3/file.h TP3/file.c -Wextra -Wall -pedantic -g

arbre: TP2/main_arbre.c TP2/ABR_TP.c TP2/ABR_TP.h TP2/file.h TP2/file.c
	gcc -o run TP2/main_arbre.c TP2/ABR_TP.h TP2/ABR_TP.c TP2/file.c -Wextra -Wall -pedantic -g

file: TP1/main_file.c TP1/file.h TP1/file.c
	gcc -o run TP1/main_file.c TP1/file.h TP1/file.c -Wextra -Wall -pedantic -g
