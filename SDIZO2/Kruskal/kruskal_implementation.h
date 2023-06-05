//
// Created by Jakub on 01.06.2023.
//

#ifndef SDIZO2_KRUSKAL_IMPLEMENTATION_H
#define SDIZO2_KRUSKAL_IMPLEMENTATION_H


#include "../Graph_tools/Matrix.h"
#include "../Graph_tools/Structures/Tablica Dynamiczna/TablicaDynamiczna.h"
#include "set.h"

class kruskal_implementation {
public:
    void kruskal_mst(Matrix *matrix, int starting_vertex);
    void kruskal_first_smallest_and_check_cycle(Matrix *matrix,TablicaDynamiczna *visited_vertexes);
    void kruskal_mst_matrix(Matrix *matrix);
    void fill_the_visited_table(TablicaDynamiczna *visited_vertexes, int vertexes, int number_to_fill);
    int find_set(int v);
    void union_set(List *edge);
    void create_sort_edge_table(Matrix *matrix);
    void bubbleSort(List **sorted_egde_table, int n);
    void make_set(Matrix *matrix);
    List **sorted_egde_table;
    List **mst;
    set *sets;

    int partition(List **sorted_edge_table, int low, int high);

    void quickSort(List **sorted_edge_table, int low, int high);

    void sortEdges(List **sorted_edge_table, int n);
};


#endif //SDIZO2_KRUSKAL_IMPLEMENTATION_H
