//
// Created by Jakub on 04.06.2023.
//

#ifndef SDIZO2_DIJKSTRA_IMPLEMENTATION_H
#define SDIZO2_DIJKSTRA_IMPLEMENTATION_H


#include "../Graph_tools/Matrix.h"
#include "../Graph_tools/Structures/Tablica Dynamiczna/TablicaDynamiczna.h"
#include "../Graph_tools/Structures/Kopiec Binarny/KopiecBinarny.h"

class Dijkstra_implementation {
public:
    void Dijkstra_shortest_path(Matrix *matrix, int starting_vertex);
    void fill_the_table(TablicaDynamiczna *table_to_fill, int number_to_fill, Matrix *matrix);
    int find_min(Matrix *matrix, int row,KopiecBinarny *prior_queue, TablicaDynamiczna *path);
    void print_result(int starting_vertex, TablicaDynamiczna *distance, TablicaDynamiczna *parent, int vertexes);
    void Dijkstra_shortest_path_list(Matrix *matrix, int starting_vertex);
};


#endif //SDIZO2_DIJKSTRA_IMPLEMENTATION_H
