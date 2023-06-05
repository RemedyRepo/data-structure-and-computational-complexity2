//
// Created by Jakub on 05.06.2023.
//

#ifndef SDIZO2_TIME_COUNTER_GRAPH_GEN_H
#define SDIZO2_TIME_COUNTER_GRAPH_GEN_H


#include <string>
#include "../File_handling/Writer.h"

class Time_counter_graph_gen {
public:
    void generateConnectedGraph(const std::string& filename, int numVertices, int startVertex, int endVertex, double density);
    void test_prim_matrix(int number, std::string filename, int numVertices, int startVertex, int endVertex, double denisty);
    void test_prim_list(int number, std::string filename, int numVertices, int startVertex, int endVertex, double denisty);
    void test_kruskal_matrix(int number, std::string filename, int numVertices, int startVertex, int endVertex, double denisty);
    void test_krusal_list(int number, std::string filename, int numVertices, int startVertex, int endVertex, double denisty);
    void test_Dijkstra_matrix(int number, std::string filename, int numVertices, int startVertex, int endVertex, double denisty);
    void test_Dijkstra_list(int number, std::string filename, int numVertices, int startVertex, int endVertex, double denisty);
    void test_BellmanFord_matrix(int number, std::string filename, int numVertices, int startVertex, int endVertex, double denisty);
    void test_BellmanFord_list(int number, std::string filename, int numVertices, int startVertex, int endVertex, double denisty);
    Writer *writer;
};


#endif //SDIZO2_TIME_COUNTER_GRAPH_GEN_H
