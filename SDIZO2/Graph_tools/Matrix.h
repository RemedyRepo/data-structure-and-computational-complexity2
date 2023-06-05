//
// Created by Jakub on 14.05.2023.
//

#ifndef SDIZO2_MATRIX_H
#define SDIZO2_MATRIX_H


#include "List.h"

class Matrix {
public:

    void create_adjacency_matrix(int edges);
    void destroy_adjacency_matrix(int vertexes);
    void create_adjacency_list(int vertexes);
    void display_adjacency_matrix();
    void adjust_adjacency_matrix(int beg_vert, int end_vert, int weight);
    void display_adjacecny_list();
    void adjust_adjacency_list(int beg_vert,int end_vert, int weight, int parent, bool duplicate);
    void sort_adjacency_list();
    int vertexes;
    int edges;
    int starting_vertex;
    int end_vertex;
    int ** adjacency_maxtrix;
    ~Matrix();
    List ** adjacency_list;
};


#endif //SDIZO2_MATRIX_H
