//
// Created by Jakub on 04.06.2023.
//


#include <iostream>
#include <vector>
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
            print_result(matrix->starting_vertex,path,parent,matrix->vertexes);
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
    print_result(matrix->starting_vertex,path,parent,matrix->vertexes);
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
    std::cout << "end\t\t\tdist\t\t\t\tpath" << std::endl;
    for (int i = 0; i < vertexes; i++) {
        std::cout << i << "\t\t\t" << distance->wsk[i] << "\t\t\t\t";

        // Tworzenie ścieżki na podstawie tablicy rodziców
        int current = i;
        std::vector<int> path;
        while (current != starting_vertex) {
            path.push_back(current);
            current = parent->wsk[current];
        }
        path.push_back(starting_vertex);

        // Wyświetlanie ścieżki w odwróconej kolejności
        for (int j = path.size() - 1; j >= 0; j--) {
            std::cout << path[j];
            if (j > 0) {
                std::cout << " -> ";
            }
        }

        std::cout << std::endl;
    }
    }


void Dijkstra_implementation::Dijkstra_shortest_path_list(Matrix *matrix, int starting_vertex) {
    TablicaDynamiczna *parent = new TablicaDynamiczna();
    TablicaDynamiczna *path = new TablicaDynamiczna();
    KopiecBinarny *prior_queue = new KopiecBinarny();
    TablicaDynamiczna *distances = new TablicaDynamiczna(); // Nowa tablica dystansów
    fill_the_table(parent, -1, matrix);
    fill_the_table(path, 2147483647, matrix);
    fill_the_table(distances, 2147483647, matrix); // Wypełnienie tablicy dystansów wartościami początkowymi
    path->wsk[starting_vertex] = 0;
    distances->wsk[starting_vertex] = 0; // Ustawienie dystansu początkowego na 0

    while (true) {
        int min_vertex = -1;
        int min_distance = INT_MAX;

        // Znalezienie wierzchołka o najmniejszej odległości
        for (int i = 0; i < matrix->vertexes; i++) {
            if (path->wsk[i] < min_distance && path->wsk[i] != -1) {
                min_vertex = i;
                min_distance = path->wsk[i];
            }
        }

        if (min_vertex == -1) {
            print_result(matrix->starting_vertex, distances, parent, matrix->vertexes); // Wyświetlenie wyników z tablicy distances
            break;
        }

        List *current_vertex = matrix->adjacency_list[min_vertex];
        while (current_vertex != nullptr) {
            int destination = current_vertex->value;
            int weight = current_vertex->weight;

            if (path->wsk[destination] > path->wsk[min_vertex] + weight && path->wsk[min_vertex] != INT_MAX) {
                path->wsk[destination] = path->wsk[min_vertex] + weight;
                parent->wsk[destination] = min_vertex;
                prior_queue->dodaj_element(path->wsk[min_vertex] + weight);
                distances->wsk[destination] = path->wsk[destination]; // Aktualizacja dystansu w tablicy distances
            }

            current_vertex = current_vertex->next;
        }

        path->wsk[min_vertex] = -1; // Oznaczenie odwiedzonego wierzchołka
    }

    delete parent;
    delete path;
    delete prior_queue;
    delete distances; // Zwolnienie pamięci po tablicy distances
}

