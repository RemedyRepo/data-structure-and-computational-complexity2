//
// Created by Jakub on 14.05.2023.
//

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "Reader.h"

void Reader::Read_from_file(Matrix *matrix, bool directed) {
    std::vector<int> data;
    int pomin = 0;
    std::string fileName;
    std::cout << "Podaj nazwe pliku: ";
    std::cin >> fileName;
    std::ifstream file(fileName);
    int counter = 0;
    if(file.is_open()){
        int number;
        while(file >> number){

                if(counter == 1){
                    matrix->vertexes = number;
                }else if(counter == 0){
                    matrix->edges = number;
                }else if(counter == 2){
                    matrix->starting_vertex = number;
                }else if(counter == 3){
                    matrix->end_vertex = number;
                }else{
                    data.push_back(number);
                }
                counter++;

        }
        file.close();
        std::cout << "File reading - succesed" << std::endl << std::endl;
    } else {
        std::cout << "File reading - failed" << std::endl << std::endl;
    }
//    std::cout << "Vertexes: " << matrix->vertexes << std::endl;
//    std::cout << "Edges: "<< matrix->edges << std::endl;
//    std::cout << "Starting vertex: "<< matrix->starting_vertex << std::endl;
//    std::cout << "End vertex: "<<matrix->end_vertex << std::endl;
    matrix->create_adjacency_matrix(matrix->vertexes);
    matrix->create_adjacency_list(matrix->vertexes);
    for(int i = 0; i < data.size(); i++){
        if(i % 3 == 1 && i != 0 && directed){
            matrix->adjust_adjacency_matrix(data[i-1],data[i],data[i+1]);
            matrix->adjust_adjacency_list(data[i-1],data[i], data[i+1],data[i-1],false);
        }else if(i % 3 == 1 && i != 0 && !directed){
            matrix->adjust_adjacency_matrix(data[i-1],data[i],data[i+1]);
            matrix->adjust_adjacency_matrix(data[i],data[i-1],data[i+1]);
            matrix->adjust_adjacency_list(data[i-1],data[i],data[i+1],data[i-1],false);
            matrix->adjust_adjacency_list(data[i],data[i-1],data[i+1],data[i],true);
        }
    }
}

void Reader::Read_from_file_for_testing(Matrix *matrix, bool directed, std::string filename) {
    std::vector<int> data;
    int pomin = 0;
    std::ifstream file(filename);
    int counter = 0;
    if(file.is_open()){
        int number;
        while(file >> number){

            if(counter == 1){
                matrix->vertexes = number;
            }else if(counter == 0){
                matrix->edges = number;
            }else if(counter == 2){
                matrix->starting_vertex = number;
            }else if(counter == 3){
                matrix->end_vertex = number;
            }else{
                data.push_back(number);
            }
            counter++;

        }
        file.close();
        std::cout << "File reading - succesed" << std::endl << std::endl;
    } else {
        std::cout << "File reading - failed" << std::endl << std::endl;
    }
//    std::cout << "Vertexes: " << matrix->vertexes << std::endl;
//    std::cout << "Edges: "<< matrix->edges << std::endl;
//    std::cout << "Starting vertex: "<< matrix->starting_vertex << std::endl;
//    std::cout << "End vertex: "<<matrix->end_vertex << std::endl;
    matrix->create_adjacency_matrix(matrix->vertexes);
    matrix->create_adjacency_list(matrix->vertexes);
    for(int i = 0; i < data.size(); i++){
        if(i % 3 == 1 && i != 0 && directed){
            matrix->adjust_adjacency_matrix(data[i-1],data[i],data[i+1]);
            matrix->adjust_adjacency_list(data[i-1],data[i], data[i+1],data[i-1],false);
        }else if(i % 3 == 1 && i != 0 && !directed){
            matrix->adjust_adjacency_matrix(data[i-1],data[i],data[i+1]);
            matrix->adjust_adjacency_matrix(data[i],data[i-1],data[i+1]);
            matrix->adjust_adjacency_list(data[i-1],data[i],data[i+1],data[i-1],false);
            matrix->adjust_adjacency_list(data[i],data[i-1],data[i+1],data[i],true);
        }
    }
}