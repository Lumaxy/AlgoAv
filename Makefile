main: main.c file.h file.c
	gcc -o main main.c file.h file.c -Wextra -Wall -pedantic -g