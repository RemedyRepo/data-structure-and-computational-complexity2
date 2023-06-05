//
// Created by Jakub on 04.06.2023.
//


#include <iostream>
#include "Dijkstra_implementation.h"
#include "../Graph_tools/Structures/Tablica Dynamiczna/TablicaDynamiczna.h"
#include "../Graph_tools/Structures/Kopiec Binarny/KopiecBinarny.h"

void Dijkstra_implementation::Dijkstra_shortest_path(Matrix *matrix, int starting_vertex) {
    TablicaDynamiczna *parent = new TablicaDynamiczna();
    TablicaDynamiczna *path = new TablicaDynamiczna();
    KopiecBinarny *prior_queue = new KopiecBinarny();
    fill_the_table(parent, -1,matrix);
    fill_the_table(path, 2147483647, matrix);
    path->wsk[starting_vertex] = 0;
    int helper = 0;
    for(int v= 0; v < matrix->vertexes; v++){
//        path->dostanTablice();
//        std::cout << std::endl;
//        parent->dostanTablice();
//        std::cout << std::endl;
        if(starting_vertex == -1){
            //print_result(matrix->starting_vertex,path,parent,matrix->vertexes);
            delete parent;
            delete path;
            delete prior_queue;
            return;
        }
        for(int i = 0 ; i < matrix->vertexes; i++){
            if(path->wsk[i] != 0 && matrix->adjacency_maxtrix[starting_vertex][i] != 0 && path->wsk[i] != -1){
                if(path->wsk[i] > path->wsk[starting_vertex]+matrix->adjacency_maxtrix[starting_vertex][i]){
                    path->wsk[i] = path->wsk[starting_vertex]+matrix->adjacency_maxtrix[starting_vertex][i]; // wrzucenie;
                    parent->wsk[i] = starting_vertex; // ustawienie rodzica

                    prior_queue->dodaj_element(path->wsk[starting_vertex]+matrix->adjacency_maxtrix[starting_vertex][i]); // dodanie do kopca
                }
            }

        }
        starting_vertex = find_min(matrix,starting_vertex,prior_queue, path);// znalezenie najmniejszego elementu i aktualizacja wierzcholka
        //std::cout << "Starting vertex: " << starting_vertex << std::endl;

    }

    //parent->dostanTablice();
    //print_result(matrix->starting_vertex,path,parent,matrix->vertexes);
    delete parent;
    delete path;
    delete prior_queue;
}

int Dijkstra_implementation::find_min(Matrix *matrix, int row, KopiecBinarny *prior_queue, TablicaDynamiczna *path) {
    for(int i = 0; i < matrix->vertexes; i++){
        if(prior_queue->kopiecBinarny->wsk[0] == path->wsk[i] && path->wsk[i] != INT_MAX){
            //prior_queue->kopiecBinarny->dostanTablice();
            //std::cout << std::endl;
            prior_queue->usun_szczyt();
            return i;
        }
    }
    return -1;
}


void Dijkstra_implementation::fill_the_table(TablicaDynamiczna *table_to_fill, int number_to_fill, Matrix *matrix) {
    for(int i = 0; i < matrix->vertexes ; i++){
        table_to_fill->dodaj_dane(0,number_to_fill);
    }

}

void Dijkstra_implementation::print_result(int starting_vertex, TablicaDynamiczna *distance, TablicaDynamiczna *parent, int vertexes) {
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

void Dijkstra_implementation::Dijkstra_shortest_path_list(Matrix *matrix, int starting_vertex) {
    TablicaDynamiczna *parent = new TablicaDynamiczna();
    TablicaDynamiczna *path = new TablicaDynamiczna();
    KopiecBinarny *prior_queue = new KopiecBinarny();
    fill_the_table(parent, -1, matrix);
    fill_the_table(path, 2147483647, matrix);
    path->wsk[starting_vertex] = 0;

    for (int v = 0; v < matrix->vertexes; v++) {
        if (starting_vertex == -1) {
            //print_result(matrix->starting_vertex, path, parent, matrix->vertexes);
            break; // Zamiast return, ponieważ nie ma potrzeby usuwania dynamicznie zaalokowanych tablic przed wyjściem z metody
        }



        List *current_vertex = matrix->adjacency_list[starting_vertex];
        while (current_vertex->next) {
            int destination = current_vertex->value;
            int weight = current_vertex->weight;

            if (path->wsk[destination] > path->wsk[starting_vertex] + weight && path->wsk[starting_vertex] != INT_MAX) {
                path->wsk[destination] = path->wsk[starting_vertex] + weight;
                parent->wsk[destination] = starting_vertex;
                prior_queue->dodaj_element(path->wsk[starting_vertex] + weight);
            }

            current_vertex = current_vertex->next;
        }

        starting_vertex = find_min(matrix, starting_vertex, prior_queue, path);

    }

    //print_result(matrix->starting_vertex, path, parent, matrix->vertexes);

    delete parent;
    delete path;
    delete prior_queue;
}
