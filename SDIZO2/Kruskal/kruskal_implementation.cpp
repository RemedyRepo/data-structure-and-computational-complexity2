//
// Created by Jakub on 01.06.2023.
//

#include <iostream>
#include "kruskal_implementation.h"
#include "../Graph_tools/Structures/Tablica Dynamiczna/TablicaDynamiczna.h"
#include "set.h"


void kruskal_implementation::kruskal_mst(Matrix *matrix, int starting_vertex) {
    int mst_weight =0;
    sorted_egde_table = new List *[matrix->edges];
    mst = new List *[matrix->vertexes-1];
    sets = new set[matrix->vertexes];
    TablicaDynamiczna *parent = new TablicaDynamiczna();
    fill_the_visited_table(parent, matrix->vertexes, 0);
    create_sort_edge_table(matrix);
    make_set(matrix);
    int index = 0;
    for (int i = 0; i < matrix->edges; i++) {
        List *temp = sorted_egde_table[i];
        if(find_set(temp->parent) == find_set(temp->value)){
            continue;
        }else {
            mst[index] = temp;
            union_set(temp);
            index++;
        }
    }
    std::cout << "Edge " << "  Weight" << std::endl;
    for (int j = 0; j < index; j++) {
        mst_weight += mst[j]->weight;
        std::cout <<"(" << mst[j]->parent << ", " << mst[j]->value << ")"<< " -> " << mst[j]->weight << std::endl;
    }
    std::cout << "MST: " << mst_weight << std::endl;
}

void kruskal_implementation::make_set(Matrix *matrix){
    for(int i = 0; i < matrix->vertexes; i++){
        sets[i].up = i;
        sets[i].rank = 0;

    }

}

int kruskal_implementation::find_set(int v){
    if( sets[ v ].up != v )  sets[ v ].up = find_set( sets[ v ].up );
    return sets[ v ].up;
}


void kruskal_implementation::union_set(List *edge) {
    int ru, rv;
    ru = find_set( edge->parent );   // Wyznaczamy korzeń drzewa z węzłem u
    rv = find_set( edge->value );   // Wyznaczamy korzeń drzewa z węzłem v
    if( ru != rv )           // Korzenie muszą być różne
    {
        if( sets[ ru ].rank > sets[ rv ].rank ) // Porównujemy rangi drzew
            sets[ rv ].up = ru;    // ru większe, dołączamy rv
        else
        {
            sets[ ru ].up = rv;    // równe lub rv większe, dołączamy ru
            if( sets[ ru ].rank == sets[ rv ].rank ) sets[ rv ].rank++;
        }
    }
}


void kruskal_implementation::fill_the_visited_table(TablicaDynamiczna *visited_vertexes, int vertexes, int number_to_fill) {
    for (int i = 0; i < vertexes; i++) {
        visited_vertexes->dodaj_dane(0, (vertexes - 1) - i);
    }
}

void kruskal_implementation::create_sort_edge_table(Matrix *matrix) {
    int index = 0;
    for (int i = 0; i < matrix->vertexes; i++) {
        List *temp = matrix->adjacency_list[i];
        while (temp->next) {
            if (temp->next->duplicate == false) {
                sorted_egde_table[index] = temp->next;
                index++;
            }
            temp = temp->next;
        }
    }
    sortEdges(sorted_egde_table, matrix->edges);
//    bubbleSort(sorted_egde_table, matrix->edges - 2);
//    std::cout << "index: " << index << std::endl;
//    for (int j = 0; j < index; j++) {
//        std::cout << sorted_egde_table[j]->parent << "-" << sorted_egde_table[j]->value << ": " << sorted_egde_table[j]->weight << std::endl;
//    }
}


void kruskal_implementation::bubbleSort(List **sorted_egde_table, int n) {
    int i, j;
    bool swapped;
    for (i = 0; i < n + 1; i++) {
        swapped = false;
        for (j = 0; j < n + 1 - i; j++) {
            if (sorted_egde_table[j]->weight > sorted_egde_table[j + 1]->weight) {
                std::swap(sorted_egde_table[j], sorted_egde_table[j + 1]);
                swapped = true;
            }
        }
        // If no two elements were swapped by inner loop,
        // then break
        if (swapped == false)
            break;
    }
}

int kruskal_implementation::partition(List **sorted_edge_table, int low, int high) {
    int pivot = sorted_edge_table[high]->weight;
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (sorted_edge_table[j]->weight < pivot) {
            i++;
            std::swap(sorted_edge_table[i], sorted_edge_table[j]);
        }
    }
    std::swap(sorted_edge_table[i + 1], sorted_edge_table[high]);
    return (i + 1);
}

void kruskal_implementation::quickSort(List **sorted_edge_table, int low, int high) {
    if (low < high) {
        int pi = partition(sorted_edge_table, low, high);

        quickSort(sorted_edge_table, low, pi - 1);
        quickSort(sorted_edge_table, pi + 1, high);
    }
}

void kruskal_implementation::sortEdges(List **sorted_edge_table, int n) {
    quickSort(sorted_edge_table, 0, n - 1);
}








void kruskal_implementation::kruskal_mst_matrix(Matrix *matrix) {
    sorted_egde_table = new List *[matrix->edges];
    mst = new List *[matrix->vertexes - 1];
    sets = new set[matrix->vertexes];
    TablicaDynamiczna *parent = new TablicaDynamiczna();
    fill_the_visited_table(parent, matrix->vertexes, 0);
    create_sort_edge_table(matrix);
    make_set(matrix);
    int index = 0;
    int mst_weight = 0;

    for (int i = 0; i < matrix->edges; i++) {
        List *temp = sorted_egde_table[i];
        if (find_set(temp->parent) == find_set(temp->value)) {
            continue;
        } else {
            mst[index] = temp;
            union_set(temp);
            index++;
        }
    }
    std::cout << "Edge " << "  Weight" << std::endl;
    for (int j = 0; j < index; j++) {
        mst_weight += mst[j]->weight;
        std::cout <<"(" << mst[j]->parent << ", " << mst[j]->value << ")"<< " -> " << mst[j]->weight << std::endl;
    }
    std::cout << "MST: " << mst_weight << std::endl;
}


