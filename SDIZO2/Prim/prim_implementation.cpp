//
// Created by Jakub on 20.05.2023.
//

#include <iostream>
#include "prim_implementation.h"
#include "../Graph_tools/Structures/Kopiec Binarny/KopiecBinarny.h"
//TODO: gruntowana poprawa wymagana

// expected time complexity O(ElogV) for binary heap implementation
void prim_implementation::prim_mst(Matrix *matrix, int starting_vertex) {
    int k;
    parent = new TablicaDynamiczna();
    key = new TablicaDynamiczna();
    mst = new TablicaDynamiczna();
    fill_the_visited_table(parent, matrix->vertexes, -1);
    fill_the_visited_table(key, matrix->vertexes, INT_MAX);
    fill_the_visited_table(mst, matrix->vertexes, 0);
    parent->wsk[starting_vertex] = -1;
    key->wsk[starting_vertex] = 0;
        for(int i = 0 ; i < matrix->vertexes; i++) {
            k = find_min(mst, key, matrix->vertexes);
            mst->wsk[k] = 1;
            for (int j = 0; j < matrix->vertexes+1; j++) {
                if (matrix->adjacency_maxtrix[k][j] != 0 && matrix->adjacency_maxtrix[k][j] < key->wsk[j] && mst->wsk[j] == 0) {
                    key->wsk[j] = matrix->adjacency_maxtrix[k][j];
                    parent->wsk[j] = k;

                }
            }
        }
        display_result(parent,matrix,key,matrix->vertexes);

    }

void  prim_implementation::fill_the_visited_table(TablicaDynamiczna *visited_vertexes, int vertexes, int number_to_fill){
    for(int i = 0; i < vertexes; i++){
        visited_vertexes->dodaj_dane(0,number_to_fill);
    }

}

int prim_implementation::find_min(TablicaDynamiczna *mst, TablicaDynamiczna *key, int vertexes){
    int min = INT_MAX;
    int index = 0;
    for(int i = 0; i < vertexes; i++){
        if(key->wsk[i] < min && mst->wsk[i] == 0 && key->wsk[i] != INT_MAX){
            min = key->wsk[i];
           // std::cout << "min: " << min << std::endl;
            index = i;
        }
    }
    return index;
}

void prim_implementation::display_result(TablicaDynamiczna *parent, Matrix *matrix, TablicaDynamiczna *key, int vertexes) {
    int mst_weight = 0;
    std::cout << "Edge " << "  Weight" << std::endl;
    for(int i = 0; i < vertexes; i++){
            mst_weight += key->wsk[i];
            if(parent->wsk[i] == -1){
                std::cout << "(" << matrix->starting_vertex << ", " << i << ")" << " -> " << key->wsk[i] << std::endl;
            }else{
                std::cout << "(" << parent->wsk[i] << ", " << i << ")" << " -> " << key->wsk[i] << std::endl;
            }

    }
    std::cout << "MST: " << mst_weight << std::endl;
//    key->dostanTablice();

}


void prim_implementation::prim_mst_list(Matrix *matrix, int starting_vertex) {
    int k;
    parent = new TablicaDynamiczna();
    key = new TablicaDynamiczna();
    mst = new TablicaDynamiczna();
    fill_the_visited_table(parent, matrix->vertexes, -1);
    fill_the_visited_table(key, matrix->vertexes, INT_MAX);
    fill_the_visited_table(mst, matrix->vertexes, 0);
    parent->wsk[starting_vertex] = -1;
    key->wsk[starting_vertex] = 0;
    for (int i = 0; i < matrix->vertexes; i++) {
        k = find_min(mst, key, matrix->vertexes);
        mst->wsk[k] = 1;

        // Przechodzenie po sąsiadach wierzchołka k
        for (List *neighbor = matrix->adjacency_list[k]; neighbor != nullptr; neighbor = neighbor->next) {
            int j = neighbor->value; // Wierzchołek docelowy
            int weight = neighbor->weight; // Waga krawędzi

            if (weight < key->wsk[j] && mst->wsk[j] == 0) {
                key->wsk[j] = weight;
                parent->wsk[j] = k;
            }
        }
    }
    display_result(parent,matrix,key,matrix->vertexes);
}

prim_implementation::~prim_implementation() {
    delete parent;
    delete key;
    delete mst;
}