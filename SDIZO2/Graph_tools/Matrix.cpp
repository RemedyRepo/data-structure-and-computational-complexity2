//
// Created by Jakub on 14.05.2023.
//

#include <iostream>
#include "Matrix.h"





void Matrix::create_adjacency_matrix(int vertexes) {
    this->adjacency_maxtrix = new int *[vertexes];
    for (int i = 0; i < vertexes; i++) {
        adjacency_maxtrix[i] = new int[vertexes];
    }
    for (int i = 0; i < vertexes; i++) {
        for (int j = 0; j < vertexes; j++) {
                adjacency_maxtrix[i][j] = 0;

        }
    }
}


void Matrix::destroy_adjacency_matrix(int vertexes) {
    for (int i = 0; i < vertexes; i++) {
        delete[] this->adjacency_maxtrix[i];
    }
    delete[] adjacency_maxtrix;
}

void Matrix::display_adjacency_matrix() {
    for (int i = 0; i < vertexes; i++) {
        for (int j = 0; j < vertexes; j++) {
            std::cout << adjacency_maxtrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void Matrix::adjust_adjacency_matrix(int beg_vert, int end_vert, int weight) {
    adjacency_maxtrix[beg_vert][end_vert] = weight;
}

void Matrix::create_adjacency_list(int vertexes) {
    this->adjacency_list = new List * [vertexes];
    for(int i = 0; i < vertexes; i++){
        adjacency_list[i] = new List(i,0,i);
    }
}

void Matrix::display_adjacecny_list() {
    for(int i = 0; i < vertexes; i++){
        std::cout << adjacency_list[i]->value << " ";
        List *temp = adjacency_list[i];
        while(temp->next){
            std::cout <<temp->next->value << ":" << temp->next->weight << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
}

void Matrix::adjust_adjacency_list(int beg_vert, int end_vert, int weight, int parent, bool duplicate){
    List *temp = adjacency_list[beg_vert];
    while(temp->next){
        temp = temp->next;
    }
   temp->next = new List(end_vert, weight, parent, duplicate);
}

Matrix::~Matrix() {
    for (int i = 0; i < vertexes; i++) {
        delete[] adjacency_maxtrix[i];
    }
    delete[] adjacency_maxtrix;
    for (int i = 0; i < vertexes; i++) {
        List *current = adjacency_list[i];
        while (current) {
            List *next = current->next;
            delete current;
            current = next;
        }
    }
    delete[] adjacency_list;
}


