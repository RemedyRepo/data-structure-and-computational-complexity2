//
// Created by Jakub on 20.05.2023.
//

#ifndef SDIZO2_PRIM_IMPLEMENTATION_H
#define SDIZO2_PRIM_IMPLEMENTATION_H


#include "../Graph_tools/Matrix.h"
#include "../Graph_tools/Structures/Kopiec Binarny/KopiecBinarny.h"

class prim_implementation {
public:
    ~prim_implementation();
    void prim_mst(Matrix *matrix, int starting_vertex);
    void prim_mst_list(Matrix *matrix, int starting_vertex);
    void add_incident_edges(Matrix *matrix, int starting_vertex,  KopiecBinarny *prior_queue, TablicaDynamiczna *visited_vertexes);
    void fill_the_visited_table(TablicaDynamiczna *visited_vertexes, int vertexes, int number_to_fill);
    void fill_the_heap(KopiecBinarny *prior_queue, TablicaDynamiczna *key, int vertexes);
    void clear_the_heap(KopiecBinarny *prior_queue, int vertexes);
    int find_min(TablicaDynamiczna*mst, TablicaDynamiczna *key , int vertexes);
    void display_result(TablicaDynamiczna *parent, Matrix *matrix, TablicaDynamiczna *key, int vertexes);
    TablicaDynamiczna *parent;
    TablicaDynamiczna *key ;
    TablicaDynamiczna *mst ;
    Matrix *result_matrix;
};


#endif //SDIZO2_PRIM_IMPLEMENTATION_H
