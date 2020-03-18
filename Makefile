arbre: main_arbre.c ABR_TP.c ABR_TP.h file.h file.c
	gcc -o run main_arbre.c ABR_TP.h ABR_TP.c file.c -Wextra -Wall -pedantic -g 

file: main_file.c file.h file.c
	gcc -o run main_file.c file.h file.c -Wextra -Wall -pedantic -g
