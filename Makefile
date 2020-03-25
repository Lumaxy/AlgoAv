arbre: TP2/main_arbre.c TP2/ABR_TP.c TP2/ABR_TP.h TP2/file.h TP2/file.c
	gcc -o run TP2/main_arbre.c TP2/ABR_TP.h TP2/ABR_TP.c TP2/file.c -Wextra -Wall -pedantic -g

file: TP1/main_file.c TP1/file.h TP1/file.c
	gcc -o run TP1/main_file.c TP1/file.h TP1/file.c -Wextra -Wall -pedantic -g
