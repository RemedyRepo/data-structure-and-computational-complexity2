//
// Created by Jakub on 04.06.2023.
//

#include <iostream>
#include "BelmanFord_implementation.h"

void BelmanFord_implementation::find_paths_check_cycles(Matrix *matrix, int starting_vertex) {
    TablicaDynamiczna *path = new TablicaDynamiczna();
    TablicaDynamiczna *parent = new TablicaDynamiczna();
    fill_the_table(path, INT_MAX, matrix);
    fill_the_table(parent, -1,matrix);
    path->wsk[starting_vertex] = 0;
    bool changed;
    for(int k = 0 ; k < matrix->vertexes-1; k++) {
        changed = true;
        for (int v = 0; v < matrix->vertexes; v++) {
//            path->dostanTablice();
//            std::cout << std::endl;
//            parent->dostanTablice();
//            std::cout << std::endl;
            for (int i = 0; i < matrix->vertexes; i++) {
                if (matrix->adjacency_maxtrix[v][i] != 0) {
                    if (path->wsk[i] > path->wsk[v] + matrix->adjacency_maxtrix[v][i] && path->wsk[v] != INT_MAX) {
                        path->wsk[i] = path->wsk[v] + matrix->adjacency_maxtrix[v][i]; // wrzucenie;
                        parent->wsk[i] = v; // ustawienie rodzica
                        changed = false;
                    }
                }

            }
        }
        if(changed){
            //print_result(matrix->starting_vertex,path,parent,matrix->vertexes);
            return;
        }
    }
    for (int v = 0; v < matrix->vertexes; v++) {
//        path->dostanTablice();
//        std::cout << std::endl;
//        parent->dostanTablice();
        std::cout << std::endl;
        for (int i = 0; i < matrix->vertexes; i++) {
            if (matrix->adjacency_maxtrix[v][i] != 0) {
                if (path->wsk[i] > path->wsk[v] + matrix->adjacency_maxtrix[v][i]) {
                    //std::cout << "Negaitve cycle occured" << std::endl;
                    return;
                }
            }

        }
    }
    //path->dostanTablice();
}





void BelmanFord_implementation::fill_the_table(TablicaDynamiczna *table_to_fill, int number_to_fill, Matrix *matrix) {
    for(int i = 0; i < matrix->vertexes ; i++){
        table_to_fill->dodaj_dane(0,number_to_fill);
    }

}

void BelmanFord_implementation::print_result(int starting_vertex, TablicaDynamiczna *distance, TablicaDynamiczna *parent, int vertexes) {
    std::cout << "End Dist Path" << std::endl;
    for (int i = 0; i < vertexes; i++) {
        std::cout << i << " | " << distance->wsk[i] << " | ";

        // Tworzenie ścieżki na podstawie tablicy rodziców
        int current = i;
        while (current != starting_vertex) {
            std::cout << current << " ";
            current = parent->wsk[current];
        }

        std::cout << starting_vertex << std::endl;
    }
}

void BelmanFord_implementation::find_paths_check_cycles_list(Matrix *matrix, int starting_vertex) {
        TablicaDynamiczna *path = new TablicaDynamiczna();
        TablicaDynamiczna *parent = new TablicaDynamiczna();
        fill_the_table(path, INT_MAX, matrix);
        fill_the_table(parent, -1, matrix);
        path->wsk[starting_vertex] = 0;
        bool changed;

        for (int k = 0; k < matrix->vertexes - 1; k++) {
            changed = true;

            for (int v = 0; v < matrix->vertexes; v++) {
                List *current_vertex = matrix->adjacency_list[v];

                while (current_vertex) {
                    int destination = current_vertex->value;
                    int weight = current_vertex->weight;

                    if (path->wsk[destination] > path->wsk[v] + weight && path->wsk[v] != INT_MAX) {
                        path->wsk[destination] = path->wsk[v] + weight;
                        parent->wsk[destination] = v;
                        changed = false;
                    }

                    current_vertex = current_vertex->next;
                }
            }

            if (changed) {
                //print_result(matrix->starting_vertex, path, parent, matrix->vertexes);
                return;
            }
        }

        for (int v = 0; v < matrix->vertexes; v++) {
            List *current_vertex = matrix->adjacency_list[v];

            while (current_vertex) {
                int destination = current_vertex->value;
                int weight = current_vertex->weight;

                if (path->wsk[destination] > path->wsk[v] + weight) {
                    //std::cout << "Negative cycle occurred" << std::endl;
                    return;
                }

                current_vertex = current_vertex->next;
            }
        }

        //path->dostanTablice();
    }

