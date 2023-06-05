//
// Created by Jakub on 04.06.2023.
//

#ifndef SDIZO2_BELMANFORD_IMPLEMENTATION_H
#define SDIZO2_BELMANFORD_IMPLEMENTATION_H


#include "../Graph_tools/Matrix.h"
#include "../Graph_tools/Structures/Tablica Dynamiczna/TablicaDynamiczna.h"

class BelmanFord_implementation {
public:
    void find_paths_check_cycles(Matrix *matrix, int starting_vertex);
    void fill_the_table(TablicaDynamiczna *table_to_fill, int number_to_fill, Matrix *matrix);
    void print_result(int starting_vertex, TablicaDynamiczna *distance, TablicaDynamiczna *parent, int vertexes);
    void find_paths_check_cycles_list(Matrix *matrix, int starting_vertex);
};


#endif //SDIZO2_BELMANFORD_IMPLEMENTATION_H
