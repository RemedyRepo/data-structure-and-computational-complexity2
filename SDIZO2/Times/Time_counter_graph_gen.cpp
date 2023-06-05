//
// Created by Jakub on 05.06.2023.
//

#include "Time_counter_graph_gen.h"
#include "../Graph_tools/Matrix.h"

#include "../Prim/prim_implementation.h"
#include "../File_handling/Reader.h"
#include "../Kruskal/kruskal_implementation.h"
#include "../Dijkstra/Dijkstra_implementation.h"
#include "../Bellman-Ford/BelmanFord_implementation.h"
#include <iostream>
#include <fstream>
#include <random>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <queue>
#include <chrono>


void Time_counter_graph_gen::generateConnectedGraph(const std::string &filename, int numVertices, int startVertex,
                                                    int endVertex, double density) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cout << "Nie można otworzyć pliku " << filename << std::endl;
        return;
    }
    int maxNumEdges = (numVertices * (numVertices - 1));
    int numEdges = density * maxNumEdges;

    file << numEdges << " " << numVertices << " " << startVertex << " " << endVertex << std::endl;


    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> weightDist(1, 10);

    // Tworzenie grafu jako macierzy sąsiedztwa
    std::vector<std::vector<int>> adjacencyMatrix(numVertices, std::vector<int>(numVertices, 0));

    // Obliczanie liczby krawędzi na podstawie gęstości


    // Dodawanie krawędzi
    std::vector<int> vertices(numVertices);
    for (int i = 0; i < numVertices; i++) {
        vertices[i] = i;
    }

    std::shuffle(vertices.begin(), vertices.end(), gen);

    for (int i = 0; i < numVertices - 1; i++) {
        int weight = weightDist(gen);
        adjacencyMatrix[vertices[i]][vertices[i + 1]] = weight;

        if (density == 1.0) {
            adjacencyMatrix[vertices[i + 1]][vertices[i]] = weight; // Dodaj drugą krawędź dla grafu nieskierowanego
        }

        file << vertices[i] << " " << vertices[i + 1] << " " << weight << std::endl;
        numEdges--;
    }

    // Dodawanie pozostałych krawędzi
    while (numEdges > 0) {
        int from = gen() % numVertices;
        int to = gen() % numVertices;

        if (from != to && adjacencyMatrix[from][to] == 0) {
            int weight = weightDist(gen);
            adjacencyMatrix[from][to] = weight;

            if (density == 1.0) {
                adjacencyMatrix[to][from] = weight; // Dodaj drugą krawędź dla grafu nieskierowanego
            }

            file << from << " " << to << " " << weight << std::endl;
            numEdges--;
        }
    }

    file.close();

    std::cout << "Wygenerowano graf i zapisano do pliku: " << filename << std::endl;
}

void Time_counter_graph_gen::test_prim_matrix(int number, std::string filename, int numVertices, int startVertex,
                                              int endVertex, double denisty) {
    Writer *writer1 = new Writer();
    prim_implementation *prim = new prim_implementation();
    Matrix *matrix = new Matrix();
    Reader *reader = new Reader();
    long long int result = 0;
    std::chrono::high_resolution_clock::time_point start;
    std::chrono::high_resolution_clock::time_point stop;
    generateConnectedGraph(filename, numVertices, startVertex, endVertex, denisty);
    reader->Read_from_file_for_testing(matrix, false, "graph");
    for (int i = 0; i < number; i++) {
        start = std::chrono::high_resolution_clock::now();
        prim->prim_mst(matrix, matrix->starting_vertex);
        stop = std::chrono::high_resolution_clock::now();
        result += std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
    }
    std::cout << " Prim matrix "<< "Vertexes: " << numVertices << " Denisty: " << denisty << " result: " << result << std::endl;
    writer1->save(std::to_string(result / 100.0f));
    delete matrix;
}

void Time_counter_graph_gen::test_prim_list(int number, std::string filename, int numVertices, int startVertex,
                                            int endVertex, double denisty) {
    Writer *writer1 = new Writer();
    prim_implementation *prim = new prim_implementation();
    Matrix *matrix = new Matrix();
    Reader *reader = new Reader();
    long long int result = 0;
    std::chrono::high_resolution_clock::time_point start;
    std::chrono::high_resolution_clock::time_point stop;
    generateConnectedGraph(filename, numVertices, startVertex, endVertex, denisty);
    reader->Read_from_file_for_testing(matrix, false, "graph");
    for (int i = 0; i < number; i++) {
        start = std::chrono::high_resolution_clock::now();
        prim->prim_mst_list(matrix, matrix->starting_vertex);
        stop = std::chrono::high_resolution_clock::now();
        result += std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
    }
    std::cout << " Prim list "<< "Vertexes: " << numVertices << " Denisty: " << denisty << " result: " << result << std::endl;
    writer1->save(std::to_string(result / 100.0f));
    delete matrix;
}

void Time_counter_graph_gen::test_kruskal_matrix(int number, std::string filename, int numVertices, int startVertex,int endVertex, double denisty) {
    Writer *writer1 = new Writer();
    kruskal_implementation *kruskal = new kruskal_implementation();
    Matrix *matrix = new Matrix();
    Reader *reader = new Reader();
    long long int result = 0;
    std::chrono::high_resolution_clock::time_point start;
    std::chrono::high_resolution_clock::time_point stop;
    generateConnectedGraph(filename, numVertices, startVertex, endVertex, denisty);
    reader->Read_from_file_for_testing(matrix, false, "graph");
    for (int i = 0; i < number; i++) {
        start = std::chrono::high_resolution_clock::now();
        kruskal->kruskal_mst_matrix(matrix);
        stop = std::chrono::high_resolution_clock::now();
        result += std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
    }
    std::cout << " Kruskal matrix "<< "Vertexes: " << numVertices << " Denisty: " << denisty << " result: " << result << std::endl;
    writer1->save(std::to_string(result / 100.0f));
    delete matrix;
}

void Time_counter_graph_gen::test_krusal_list(int number, std::string filename, int numVertices, int startVertex,int endVertex, double denisty) {
    Writer *writer1 = new Writer();
    kruskal_implementation *kruskal = new kruskal_implementation();
    Matrix *matrix = new Matrix();
    Reader *reader = new Reader();
    long long int result = 0;
    std::chrono::high_resolution_clock::time_point start;
    std::chrono::high_resolution_clock::time_point stop;
    generateConnectedGraph(filename, numVertices, startVertex, endVertex, denisty);
    reader->Read_from_file_for_testing(matrix, false, "graph");
    for (int i = 0; i < number; i++) {
        start = std::chrono::high_resolution_clock::now();
        kruskal->kruskal_mst(matrix,matrix->starting_vertex);
        stop = std::chrono::high_resolution_clock::now();
        result += std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
    }
    std::cout << " Kruskal list "<< "Vertexes: " << numVertices << " Denisty: " << denisty << " result: " << result << std::endl;
    writer1->save(std::to_string(result / 100.0f));
    delete matrix;
}

void Time_counter_graph_gen::test_Dijkstra_matrix(int number, std::string filename, int numVertices, int startVertex,int endVertex, double denisty) {
    Writer *writer1 = new Writer();
    Dijkstra_implementation *dijkstra = new Dijkstra_implementation();
    Matrix *matrix = new Matrix();
    Reader *reader = new Reader();
    long long int result = 0;
    std::chrono::high_resolution_clock::time_point start;
    std::chrono::high_resolution_clock::time_point stop;
    generateConnectedGraph(filename, numVertices, startVertex, endVertex, denisty);
    reader->Read_from_file_for_testing(matrix, true, "graph");
    for (int i = 0; i < number; i++) {
        start = std::chrono::high_resolution_clock::now();
        dijkstra->Dijkstra_shortest_path(matrix,matrix->starting_vertex);
        stop = std::chrono::high_resolution_clock::now();
        result += std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
    }
    std::cout << " Dijkstra matrix "<< "Vertexes: " << numVertices << " Denisty: " << denisty << " result: " << result << std::endl;
    writer1->save(std::to_string(result / 100.0f));
    delete matrix;
}

void Time_counter_graph_gen::test_Dijkstra_list(int number, std::string filename, int numVertices, int startVertex,int endVertex, double denisty) {
    Writer *writer1 = new Writer();
    Dijkstra_implementation *dijkstra = new Dijkstra_implementation();
    Matrix *matrix = new Matrix();
    Reader *reader = new Reader();
    long long int result = 0;
    std::chrono::high_resolution_clock::time_point start;
    std::chrono::high_resolution_clock::time_point stop;
    generateConnectedGraph(filename, numVertices, startVertex, endVertex, denisty);
    reader->Read_from_file_for_testing(matrix, true, "graph");
    for (int i = 0; i < number; i++) {
        start = std::chrono::high_resolution_clock::now();
        dijkstra->Dijkstra_shortest_path_list(matrix,matrix->starting_vertex);
        stop = std::chrono::high_resolution_clock::now();
        result += std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
    }
    std::cout << " Dijkstra list "<< "Vertexes: " << numVertices << " Denisty: " << denisty << " result: " << result << std::endl;
    writer1->save(std::to_string(result / 100.0f));
    delete matrix;
}
void Time_counter_graph_gen::test_BellmanFord_matrix(int number, std::string filename, int numVertices, int startVertex,int endVertex, double denisty) {
    Writer *writer1 = new Writer();
    BelmanFord_implementation *bellaford = new BelmanFord_implementation();
    Matrix *matrix = new Matrix();
    Reader *reader = new Reader();
    long long int result = 0;
    std::chrono::high_resolution_clock::time_point start;
    std::chrono::high_resolution_clock::time_point stop;
    generateConnectedGraph(filename, numVertices, startVertex, endVertex, denisty);
    reader->Read_from_file_for_testing(matrix, true, "graph");
    for (int i = 0; i < number; i++) {
        start = std::chrono::high_resolution_clock::now();
        bellaford->find_paths_check_cycles(matrix,matrix->starting_vertex);
        stop = std::chrono::high_resolution_clock::now();
        result += std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
    }
    std::cout << " Bellman Ford matrix "<< "Vertexes: " << numVertices << " Denisty: " << denisty << " result: " << result << std::endl;
    writer1->save(std::to_string(result / 100.0f));
    delete matrix;
}

void Time_counter_graph_gen::test_BellmanFord_list(int number, std::string filename, int numVertices, int startVertex,int endVertex, double denisty) {
    Writer *writer1 = new Writer();
    BelmanFord_implementation *bellaford = new BelmanFord_implementation();
    Matrix *matrix = new Matrix();
    Reader *reader = new Reader();
    long long int result = 0;
    std::chrono::high_resolution_clock::time_point start;
    std::chrono::high_resolution_clock::time_point stop;
    generateConnectedGraph(filename, numVertices, startVertex, endVertex, denisty);
    reader->Read_from_file_for_testing(matrix, true, "graph");
    for (int i = 0; i < number; i++) {
        start = std::chrono::high_resolution_clock::now();
        bellaford->find_paths_check_cycles_list(matrix,matrix->starting_vertex);
        stop = std::chrono::high_resolution_clock::now();
        result += std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
    }
    std::cout << " Bellman Ford list "<< "Vertexes: " << numVertices << " Denisty: " << denisty << " result: " << result << std::endl;
    writer1->save(std::to_string(result / 100.0f));
    delete matrix;
}




