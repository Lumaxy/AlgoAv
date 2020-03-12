cmake_minimum_required(VERSION 3.14)
project(TPAlgo C)

set(CMAKE_C_STANDARD 11)

add_executable(TPAlgo
        ABR_TP.c
        fawori.c
        file.c
        genere_graphe_0.c
        genere_graphe_1.c
        L_ADJ.c
        LL_ADJ.c)
