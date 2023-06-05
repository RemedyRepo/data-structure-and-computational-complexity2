//
// Created by Jakub on 05.06.2023.
//

#include <iostream>
#include "Presentation.h"

#include "../File_handling/Reader.h"

void Presentation::prim() {
    matrix = new Matrix();
    reader = new Reader();
    prim_implementation *primImplementation = new prim_implementation();
    int gate = 0;
    while(gate != 5){
        std::cout << "You chose Prim algorithm choose. \n";
        std::cout << "Choose option you want to test: . \n";
        std::cout << "1 - Read graph from file. \n";
        std::cout << "2 - Display matrix and list representation. \n";
        std::cout << "3 - Run Prim algorithm using matrix. \n";
        std::cout << "4 - Run Prim algorithm using list. \n";
        std::cout << "5 - Exit. \n";
        std::cin >> gate;
        switch(gate){
            case 1:
                reader->Read_from_file(matrix,false);
                break;
            case 2:
                std::cout << "===== Adjacency Matrix: =====\n";
                matrix->display_adjacency_matrix();
                std::cout << "===== Adjacency List: =====\n";
                matrix->display_adjacecny_list();
                break;
            case 3:
                primImplementation->prim_mst(matrix,matrix->starting_vertex);
                break;
            case 4:
                primImplementation->prim_mst_list(matrix,matrix->starting_vertex);
                break;
        }
    }

}

void Presentation::kruskal() {
    matrix = new Matrix();
    reader = new Reader();
    kruskal_implementation *kruskalImplementation = new kruskal_implementation();
    int gate = 0;
    while(gate != 5){
        std::cout << "You chose Kruskal algorithm. \n";
        std::cout << "Choose option you want to test: . \n";
        std::cout << "1 - Read graph from file. \n";
        std::cout << "2 - Display matrix and list representation. \n";
        std::cout << "3 - Run Kruskal algorithm using matrix. \n";
        std::cout << "4 - Run Kruskal algorithm using list. \n";
        std::cout << "5 - Exit. \n";
        std::cin >> gate;
        switch(gate){
            case 1:
                reader->Read_from_file(matrix,false);
                break;
            case 2:
                std::cout << "===== Adjacency Matrix: =====\n";
                matrix->display_adjacency_matrix();
                std::cout << "===== Adjacency List: =====\n";
                matrix->display_adjacecny_list();
                break;
            case 3:
                kruskalImplementation->kruskal_mst_matrix(matrix);
                break;
            case 4:
                kruskalImplementation->kruskal_mst(matrix,matrix->starting_vertex);
                break;
        }
    }
}

void Presentation::dijkstra() {
    matrix = new Matrix();
    reader = new Reader();
    Dijkstra_implementation *dijkstraImplementation = new Dijkstra_implementation();
    int gate = 0;
    while(gate != 5){
        std::cout << "You chose Dijkstra algorithm choose. \n";
        std::cout << "Choose option you want to test: . \n";
        std::cout << "1 - Read graph from file. \n";
        std::cout << "2 - Display matrix and list representation. \n";
        std::cout << "3 - Run Dijkstra algorithm using matrix. \n";
        std::cout << "4 - Run Dijkstra algorithm using list. \n";
        std::cout << "5 - Exit. \n";
        std::cin >> gate;
        switch(gate){
            case 1:
                reader->Read_from_file(matrix,true);
                break;
            case 2:
                std::cout << "===== Adjacency Matrix: =====\n";
                matrix->display_adjacency_matrix();
                std::cout << "===== Adjacency List: =====\n";
                matrix->display_adjacecny_list();
                break;
            case 3:
                dijkstraImplementation->Dijkstra_shortest_path(matrix, matrix->starting_vertex);
                break;
            case 4:
                dijkstraImplementation->Dijkstra_shortest_path_list(matrix,matrix->starting_vertex);
                break;
        }
    }
}

void Presentation::bellman_ford() {
    matrix = new Matrix();
    reader = new Reader();
    BelmanFord_implementation *belmanFordImplementation = new BelmanFord_implementation();
    int gate = 0;
    while(gate != 5){
        std::cout << "You chose Bellman-Ford algorithm choose. \n";
        std::cout << "Choose option you want to test: . \n";
        std::cout << "1 - Read graph from file. \n";
        std::cout << "2 - Display matrix and list representation. \n";
        std::cout << "3 - Run Bellman-Ford algorithm using matrix. \n";
        std::cout << "4 - Run Bellman-Ford algorithm using list. \n";
        std::cout << "5 - Exit. \n";
        std::cin >> gate;
        switch(gate){
            case 1:
                reader->Read_from_file(matrix,true);
                break;
            case 2:
                std::cout << "===== Adjacency Matrix: =====\n";
                matrix->display_adjacency_matrix();
                std::cout << "===== Adjacency List: =====\n";
                matrix->display_adjacecny_list();
                break;
            case 3:
                belmanFordImplementation->find_paths_check_cycles(matrix, matrix->starting_vertex);
                break;
            case 4:
                belmanFordImplementation->find_paths_check_cycles_list(matrix,matrix->starting_vertex);
                break;
        }
    }
}